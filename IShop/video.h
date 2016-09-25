#ifndef VIPP_VIDEO_H
#define VIPP_VIDEO_H

#define DEFAULT_CAMERA_DEVICE "/dev/video1"

#define FREAMBUF_DEV	"/dev/fb0"
#define CAMERA_DEVICE	"/dev/video1"
#define VIDEO_WIDTH		320
#define VIDEO_HEIGHT	240
#define VIDEO_FORMAT	V4L2_PIX_FMT_YUYV

#define TEMP_FRAME_FILE "/tmp/vipp.jpg"
#include <sys/time.h>
#include <linux/videodev2.h>

#define VIPP_OK 0
#define VIPP_ERR -1
#define CLEAR(x) memset (&(x), 0, sizeof (x))

typedef struct FrameBuffer {
	void *              start;
	size_t              length;
}FRAME_BUFFER_S;

typedef struct VideoInfo
{
	char cameraDev[32];				//摄像头文件
	int cameraFd;					//视频设备描述符，采集用

	FRAME_BUFFER_S	*buffers;		//帧缓冲队列

	int			width;				//宽
	int			height;				//高
	int			format;
	int			brightness;			//亮度
	int			hue;				//色度
	int			saturation;			//饱和度
	int			contrast;			//对比度
	struct v4l2_buffer frame;		//当前帧

	int snapImage;

}VIDEO_INFO_S;

extern struct VideoInfo g_VideoInfo;

#ifdef __cplusplus
extern "C" {
#endif

/** 打开视频设备 
 * devName - 视频设备文件名
 * width - 视频宽度
 * height - 视频高度
 */
int __VIDEO_Open(const char *devName, int width, int height, int fmt);

/** 设置视频格式 */
int __VIDEO_SetCamParam(int width, int height, int format);

/** 开始视频捕捉 */
int __VIDEO_StreamOn();

/** 关闭视频捕捉 */
int __VIDEO_StreamOff();

/** 申请视频缓冲队列 */
int __VIDEO_RequestBuffers() ;

/** 采集一张视频图像 */
int __VIDEO_GrabFrame(FRAME_BUFFER_S *frame);

/** 将视频图像放回缓冲队列 */
int __VIDEO_ReleaseFrame();

/** 关闭视频设备 */
int __VIDEO_Close();

/** 获取亮度 */
int VIDEO_GetBrightness(int fd);

/** 设置亮度 */
int VIDEO_SetBrightness(int fd, int br);

/** 获取对比度 */
int VIDEO_GetContrast(int fd);

/** 设置对比度 */
int VIDEO_SetContrast(int fd, int contrast);

int VIDEO_GetSaturation(int fd);

int VIDEO_SetSaturation(int fd, int saturation);

/** 打印摄像头参数 */
int VIDEO_PrintParam();


int VIDEO_GetHue(int fd);

int VIDEO_SetHue(int fd, int hue) ;


/** 获取视频捕捉的设备文件描述符 */
int VIDEO_GetCamFd();

#ifdef __cplusplus
}
#endif



#endif

