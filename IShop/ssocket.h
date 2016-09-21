#ifndef SSOCKET_H
#define SSOCKET_H
typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

class SSocket
{
public:
    SSocket();
    SSocket(int fd) {
        sock = fd;
    }
    int GetFd() {
        return sock;
    }

    void SetSocket(int fd) {
		sock = fd;
	}
    const SSocket & operator = (int fd) {
        sock = fd;
        return *this;
    }

    bool Connect(const char *ip, int port);

    bool CreateTcpServer(int port);

    int Accept(char *remoteIp);

    int SetTimeout(int ms);

    /** 接收数据
     * buf - 接收缓冲区，接收到的数据放在buf中返回
     * size - buf的大小
     * 返回 － 接收到的字节个数
     */
    int Read(void *buf, int size);

    //6. 接收指定字节数的数据
     int ReadN(void *buf, int nBytes);
    //7. 发送数据
     int Write(const void *buf, int size);
    //8. 关闭套接字
     void Close();

     //连接域名，可不实现
     bool ConnectHost(const char *host, int port);

private:
     int sock;  //套接字
     int timeout;//microsecond，构造函数 里timeout=0;
};

#endif // SSOCKET_H
