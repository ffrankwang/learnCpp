#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
struct Request { //请求的结构体
    unsigned int version; //通讯协议的版本号
    unsigned int cmdNo; //指令，是告诉服务器要做什么，0x000007
    unsigned int seqNo; //赋值为1
    unsigned int bodyLen; //消息体长度
};

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = 0);
    void run(); //线程函数，在这个函数中实现连接服务器以及接收图像的功能
signals:
    void recv_image(char *, int);

public slots:
    
};

#endif // VIDEOTHREAD_H
