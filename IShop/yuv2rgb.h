#ifndef YUV2RGB_H
#define YUV2RGB_H

#ifdef __cplusplus
extern "C" {
#endif


int YuvToRgb(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);

#ifdef __cplusplus
}
#endif


#endif
