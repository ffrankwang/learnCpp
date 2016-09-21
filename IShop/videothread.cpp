#include "videothread.h"
#include "ssocket.h"
#include <arpa/inet.h>

#include <QDebug>
VideoThread::VideoThread(QObject *parent) :
    QThread(parent)
{
}

void VideoThread::run()
{
   // (1)定义一个SSocket对象,连接服务器
    SSocket sock;
    if(!sock.Connect("192.168.106.98", 8888)) {
        qDebug()<<"Connect failed";
        return;
    }
    //(2)向服务器发送一个视频请求
    Request head = {0x10000000, 0x000007, 1, 0};
    time_t t;
    int len;
    t = time(NULL);
    char *image;
    char body[100];
    len = sprintf(body, "<?xml version=\"1.0\">"
                                    "<REQUEST>"
                                    "<SESSION>%d</SESSION>"
                                    "</REQUEST>", (int)t);
    head.cmdNo = htonl(head.cmdNo); //将一个整数从主机字节顺序转换为网络字节序
    head.bodyLen = htonl(len);
    sock.Write(&head, sizeof(head)); //发送头
    sock.Write(body, len); //发送消息体
    //(3)循环接收图像，收到一张图像时，发射一次信号
    while(1) {
        //1. 接收16字节的头
        if(sock.ReadN(&head, sizeof(head)) <= 0) {
            qDebug() << "接收头失败";
            break;
        }
        //2. 接收图像内容
        head.bodyLen = ntohl(head.bodyLen); //将网络字节顺序的数字转换主机字节顺序
        image = new char[head.bodyLen]; //分配内存，用于存储图像
        qDebug() << "图像大小："<<head.bodyLen;
        sock.ReadN(image, head.bodyLen) ; //拉收bodyLen个字节长度的一张图像
        //3. 发射信号
        emit recv_image(image, head.bodyLen);
    }
}
