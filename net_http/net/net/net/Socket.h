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

struct SocketData {
	sockaddr_in addr;
	int fd;
};

class Socket {
public:
	Socket(char ip[20], int port);		// 指定ip地址
	Socket(int port);					// 默认本机ip地址
	Socket(struct SocketData socketData);// 默认构造函数
	
	void Accept(struct SocketData* peer);
	bool Bind();
	void Listen(int len);
	bool Connect();
	int Read(struct SocketData* peer, char* buf);
	int Read(char* buf);
	int Write(struct SocketData* peer, char* buf, int len);
	int Write(char* buf, int len);
	void Close();
	bool init();			// 一般用于服务器端初始化套接字
	void setFd(int fd);
	//int getFd();

private:
	char m_ip[20];
	int m_oprt;		
	SocketData socketData;
};

#endif

