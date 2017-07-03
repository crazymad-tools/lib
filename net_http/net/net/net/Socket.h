/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-09 15:04
 * Filename         : Socket.h
 * Description      : 
 *********************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H

#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <crazy/net/net_def.h>

struct SocketData {
	sockaddr_in addr;
	int fd;
};

class Socket {
public:
	Socket(char ip[20], int port);		// 指定ip地址
	Socket(int port);					// 默认本机ip地址
	Socket(struct SocketData socketData);// 默认构造函数
	Socket() { }
	
	void setFd(int fd);
	void setSocketData(SocketData socketData);
	bool init();			// 一般用于服务器端初始化套接字
	bool Bind();
	void Listen(int len);
	void Accept(struct SocketData* peer);
	bool Connect();
	int Read(struct SocketData* peer, char* buf, int len=BUFSIZE);
	int Read(char* buf, int len=BUFSIZE);
	int Write(struct SocketData* peer, char* buf, int len);
	int Write(char* buf, int len);
	void Close();
	int getFd();
	char* ipToString(char* buf = NULL);

private:
	char m_ip[20];
	int m_oprt;		
	SocketData socketData;
};

#endif

