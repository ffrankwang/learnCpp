/******************************************************************
 *  ������ socketxx.cpp
 *  ����  �� ͨ���װ��ֽӿڷ�װ��
 *  �������ڣ�2013-09
 *  ���ߣ�   Fang Yongjun
 *****************************************************************/
#include <string.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <arpa/inet.h>
#include<unistd.h>
#include "ssocket.h"
/*
   int Socketxx::getFD() {
   return sock;
   }

   void Socketxx::setFD(int fd) {
   sock = fd;
   }
   */
SSocket::SSocket()
{
    sock = -1;
}

bool SSocket::CreateTcpServer(int port) {
    int reuse = 1;
    struct sockaddr_in addr;

    if(sock < 0)
        sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        return false;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
    if(::bind(sock, (SA *)&addr,  sizeof(addr)) == 0) {
        listen(sock, 5);
        return true;
    }

    Close();
    return false;
}

bool SSocket::Connect(const char *ip, int port) {
    struct sockaddr_in addr;

    if(sock < 0)
        sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        return false;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    if(::connect(sock, (SA *)&addr, sizeof(addr)) == 0) {
        return true;
    }
    Close();
    return false;
}

bool SSocket::ConnectHost(const char *, int ) {
    if(sock < 0)
        sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        return false;
    //TODO: Add code here
    return true;
}

int SSocket::SetTimeout(int sec) {

    timeout = sec;
    //if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) != 0)
    //	return false;
    return timeout;
}

int SSocket::ReadN(void *buf, int size) {
    int readed = 0;
    int rsize;
    while(readed < size) {
        if((rsize = Read((char *)buf+readed, size - readed)) <= 0) {
            return  readed;
        }
        readed += rsize;
    }
    return readed;
}

int SSocket::Read(void *buf, int size) {
    if(timeout > 0) {
        int res;
        fd_set readFDs;
        struct timeval waitTime;

        waitTime.tv_sec = timeout;
        waitTime.tv_usec = 0;
        FD_ZERO(&readFDs);
        FD_SET(sock, &readFDs);
        res = select(sock+1, &readFDs, NULL, NULL, &waitTime);
        if(res <= 0 || !FD_ISSET(sock, &readFDs))
            return -1;
    }
    return recv(sock, buf, size, 0);
}

int SSocket::Accept(char *remoteIp) {
    SAI addr;
    socklen_t size = sizeof(SAI);

    int newSock =  ::accept(sock, (SA *)&addr, &size);
    inet_ntop(addr.sin_family, &addr.sin_addr, remoteIp, 32);

    return newSock;
}

void SSocket::Close()
{
    if(sock >= 0) {
        ::close(sock);
        sock = -1;
    }
}

int SSocket::Write(const void *buf, int size)
{
    return send(sock, buf, size, 0);
}
