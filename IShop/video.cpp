#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>            
#include <fcntl.h>             
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <asm/types.h>         
#include <linux/videodev2.h>
#include <linux/fb.h>
#include <time.h>
#include <jpeglib.h>

#include "jdatabuf.h"
#include "video.h"
#include "yuv2rgb.h"

VIDEO_INFO_S g_VideoInfo;

int __VIDEO_Open(const char *devName, int width, int height, int fmt)
{
	struct v4l2_capability cap; 
	unsigned int i;
//	enum v4l2_buf_type type;
//	struct v4l2_fmtdesc fmt1;
	int cameraFd;
	int ret;

	//打开视频设备
	cameraFd = open (devName, O_RDWR);
	if (cameraFd == -1) {
		perror("Open");
		return VIPP_ERR;
	}

	ret = ioctl (cameraFd, VIDIOC_QUERYCAP, &cap);
	if(ret < 0){
		perror("QUERYCAP");
		goto OPEN_ERROR;
	}
	g_VideoInfo.cameraFd = cameraFd;

	//设置视频格式
	g_VideoInfo.format = fmt;
	if(VIPP_OK != __VIDEO_SetCamParam(width, height, fmt)) {
		perror("SET_CAM_PARAM");
		goto OPEN_ERROR;
	}

	//申请缓冲
	if(VIPP_OK != __VIDEO_RequestBuffers()) {
		perror("REQUEST_BUFFERS");
		goto OPEN_ERROR;
	}

	//获取当前视频的相关参数
	g_VideoInfo.width = width;
	g_VideoInfo.height = height;
	g_VideoInfo.brightness = VIDEO_GetBrightness(cameraFd);
	g_VideoInfo.contrast = VIDEO_GetContrast(cameraFd);
	g_VideoInfo.hue = VIDEO_GetHue(cameraFd);
	g_VideoInfo.saturation = VIDEO_GetSaturation(cameraFd);

	//开启视频捕捉
	if(__VIDEO_StreamOn() != VIPP_OK) {
		close(cameraFd);
		return -1;
	}

	return cameraFd;

OPEN_ERROR:
	close(cameraFd);
	g_VideoInfo.cameraFd = -1;
	return -1;
}

int __VIDEO_StreamOn()
{
	enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	if (-1 == ioctl (g_VideoInfo.cameraFd, VIDIOC_STREAMON, &type)) {
		perror("STREAM_ON");
		return VIPP_ERR;
	}

	return VIPP_OK;
}

//关闭视频流
int __VIDEO_StreamOff()
{
	enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	if (-1 == ioctl (g_VideoInfo.cameraFd, VIDIOC_STREAMOFF, &type)) {
		return VIPP_ERR;
	}

	return VIPP_OK;
}

int __VIDEO_RequestBuffers() 
{
	int i;
	int cameraFd = g_VideoInfo.cameraFd;
	struct v4l2_requestbuffers req;
	FRAME_BUFFER_S *frames;

	CLEAR (req);
	req.count               = 1;
	req.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	req.memory              = V4L2_MEMORY_MMAP;
	if(ioctl (cameraFd, VIDIOC_REQBUFS, &req) < 0)
	{
		return VIPP_ERR;
	}

	if (req.count > 0)
	{
        frames = (FRAME_BUFFER_S *)calloc (req.count, sizeof (FRAME_BUFFER_S));
	}

	for (i= 0; i < req.count; ++i){
		struct v4l2_buffer buf;   
		CLEAR (buf);
		buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory      = V4L2_MEMORY_MMAP;
		buf.index       = i;

		if( -1 == ioctl (cameraFd, VIDIOC_QUERYBUF, &buf))
		{
			free(frames);
			return VIPP_ERR;
		}

		frames[i].length = buf.length;
		frames[i].start = mmap (NULL, buf.length, 
				PROT_READ | PROT_WRITE, MAP_SHARED, cameraFd, buf.m.offset);

		if (MAP_FAILED == frames[i].start){
			free(frames);
			return VIPP_ERR;
		}
		memset(frames[i].start, 0, buf.length); 
	}

	for (i = 0; i < req.count; ++i){
		struct v4l2_buffer buf;
		CLEAR (buf);
		buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory      = V4L2_MEMORY_MMAP;
		buf.index       = i;
		if (-1 == ioctl (cameraFd, VIDIOC_QBUF, &buf)) {
		}
	}

	g_VideoInfo.buffers = frames;
	return VIPP_OK;
}

int VIDEO_ImageToJpeg(char *img, int w, int h, char *jpeg_data, int quality)
{
	struct jpeg_compress_struct cinfo;	
	struct jpeg_error_mgr jerr;	
	int i, size;	
	unsigned char *line;		

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);
	jpeg_buff_dest(&cinfo);
	cinfo.image_width = w;	
	cinfo.image_height = h;
	cinfo.input_components = 3;	
	cinfo.in_color_space = JCS_RGB;
	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE);	
	jpeg_start_compress(&cinfo, TRUE);
    for (i = 0, line = (unsigned char *)img; i < h; i++, line += w*3)
		jpeg_write_scanlines(&cinfo, &line, 1);	
	jpeg_finish_compress(&cinfo);
	size = get_jpeg_size(&cinfo);	
	
	/* this memory must be freed elsewhere */
	/*
	(*jpeg_data) = (char *)malloc(size);	
	if(!(*jpeg_data))	
	{	
		jpeg_destroy_compress(&cinfo);
		jpeg_buff_free(&cinfo);
		return -1;	
	}	
	memcpy(*jpeg_data, ((my_dest_ptr)cinfo.dest)->buffer, size);
	*/

	memcpy(jpeg_data, ((my_dest_ptr)cinfo.dest)->buffer, size);
	jpeg_destroy_compress(&cinfo);
	jpeg_buff_free(&cinfo);	

	return size;
}

int __VIDEO_GrabFrame(FRAME_BUFFER_S *frame)
{
	int imageSize = -1;
	FRAME_BUFFER_S *buf;
	FILE *fp;
	unsigned char *rgb ;

	CLEAR (g_VideoInfo.frame);
	g_VideoInfo.frame.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	g_VideoInfo.frame.memory = V4L2_MEMORY_MMAP;

	//从缓冲队列取一帧图像出来
	printf("Grab\n");
	if( ioctl (g_VideoInfo.cameraFd, VIDIOC_DQBUF, &g_VideoInfo.frame) < 0)
	{
		return -1;
	}
	printf("Grab ok\n");

	buf = &g_VideoInfo.buffers[g_VideoInfo.frame.index];
	
	if(g_VideoInfo.format == V4L2_PIX_FMT_YUYV)
	{
		rgb = (unsigned char *)malloc(g_VideoInfo.width * g_VideoInfo.height * 3);
        YuvToRgb((unsigned char *)buf->start, rgb, g_VideoInfo.width, g_VideoInfo.height);

		//libjpeg库来实现压缩
        imageSize = VIDEO_ImageToJpeg((char *)rgb, g_VideoInfo.width, g_VideoInfo.height, (char *)frame->start, 90);
		free(rgb);
		//fp = fopen("./temp.jpg", "w");
		//fwrite(frame->start, imageSize, 1, fp);
		//fclose(fp);
	}
	else
	{
		imageSize = g_VideoInfo.frame.bytesused;
		memcpy(frame->start, buf->start, imageSize);
	}

	printf("Grab image size:%d\n", imageSize);
	ioctl(g_VideoInfo.cameraFd, VIDIOC_QBUF, &g_VideoInfo.frame);

	return imageSize;
}

int __VIDEO_ReleaseFrame()
{
	if(-1 == ioctl (g_VideoInfo.cameraFd, VIDIOC_QBUF, &g_VideoInfo.frame))
	{
		printf("error: VIDIOC_QBUF %s\n", __func__);
		return VIPP_ERR;
	}

	return VIPP_OK;
}

//
int __VIDEO_SetCamParam(int width, int height, int format)
{
	struct v4l2_format fmt;

	CLEAR (fmt);
	fmt.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width       = width; 
	fmt.fmt.pix.height      = height;
	fmt.fmt.pix.pixelformat = format;
	//	fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;//RGB24
	fmt.fmt.pix.field       = V4L2_FIELD_ANY;

	if(-1 == ioctl (g_VideoInfo.cameraFd, VIDIOC_S_FMT, &fmt))
	{
		perror("VIDEOC_S_FMT");
		return VIPP_ERR;
	}

	return VIPP_OK;
}

int __VIDEO_Close()
{
	int i;

	__VIDEO_StreamOff();

	printf("VIDEO streamoff OK\n");
	if(NULL != g_VideoInfo.buffers) {
		for(i=0; i<1; i++) {
			munmap(g_VideoInfo.buffers[i].start, g_VideoInfo.buffers[i].length);
		}
		free(g_VideoInfo.buffers);
		g_VideoInfo.buffers = NULL;
	}

	close(g_VideoInfo.cameraFd);

	return 0;
}

int VIDEO_GetCamFd()
{
	return g_VideoInfo.cameraFd;
}

int VIDEO_GetBrightness(int fd) 
{
	struct v4l2_control ctl = {V4L2_CID_BRIGHTNESS, 0};

	if(-1 == ioctl(fd, VIDIOC_G_CTRL, &ctl)) {
		return -1;
	}

	return ctl.value;
}

int VIDEO_SetBrightness(int fd, int br) 
{
	struct v4l2_control ctl = {V4L2_CID_BRIGHTNESS, br};

	return ioctl(g_VideoInfo.cameraFd, VIDIOC_S_CTRL, &ctl);
	/*
	struct video_picture videopict;

	if (ioctl (g_VideoInfo.cameraFd, VIDIOCGPICT, &videopict) < 0)
		printf("VIDIOCGPICT error\n");
	videopict.brightness = br;

	if (ioctl (g_VideoInfo.cameraFd, VIDIOCSPICT, &videopict) < 0)
		printf("Couldnt set videopict params with VIDIOCSPICT\n");

	printf ("VIDIOCSPICT brightnes=%d hue=%d color=%d contrast=%d"
			" whiteness=%d depth=%d palette=%d\n", 
			videopict.brightness, videopict.hue, videopict.colour, 
			videopict.contrast,  videopict.whiteness, videopict.depth,
			videopict.palette);
	*/
}

int VIDEO_GetContrast(int fd) 
{
	struct v4l2_control ctl = {V4L2_CID_CONTRAST, 0};

	if(-1 == ioctl(fd, VIDIOC_G_CTRL, &ctl)) 
	{
		return -1;
	}

	return ctl.value;
}

int VIDEO_SetContrast(int fd, int contrast) 
{
	struct v4l2_control ctl = {V4L2_CID_CONTRAST, contrast};

	return ioctl(fd, VIDIOC_S_CTRL, &ctl);
}

int VIDEO_GetSaturation(int fd) 
{
	struct v4l2_control ctl = {V4L2_CID_SATURATION, 0};

	if(-1 == ioctl(fd, VIDIOC_G_CTRL, &ctl)) {
		return -1;
	}

	return ctl.value;
}

int VIDEO_SetSaturation(int fd, int saturation) 
{
	struct v4l2_control ctl = {V4L2_CID_SATURATION, saturation};

	return ioctl(fd, VIDIOC_S_CTRL, &ctl);
}

int VIDEO_PrintParam()
{
	printf("resolution :\t%d x %d\n", g_VideoInfo.width, g_VideoInfo.height);
	printf("brightness :\t%d\n", g_VideoInfo.brightness);
	printf("contrast   :\t%d\n", g_VideoInfo.contrast);
	printf("saturation :\t%d\n", g_VideoInfo.saturation);
	printf("Hue        :\t%d\n", g_VideoInfo.hue);

	return VIPP_OK;
}

int VIDEO_GetHue(int fd) 
{
	struct v4l2_control ctl = {V4L2_CID_HUE, 0};

	if(-1 == ioctl(fd, VIDIOC_G_CTRL, &ctl)) {
		return -1;
	}

	return ctl.value;
}

int VIDEO_SetHue(int fd, int hue) 
{
	struct v4l2_control ctl = {V4L2_CID_HUE, hue};

	return ioctl(fd, VIDIOC_S_CTRL, &ctl);
}
