/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-09 15:04
 * Filename         : Socket.h
 * Description      : 
 *********************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H

#include <stdint.h>

class Socket {
public:
	Socket(char ip[20], int port);		// 指定ip地址
	Socket(int port);					// 默认本机ip地址

	void Bind();
	bool Connect();
	bool Read();
	bool Write();
	void Close();
private:
	char m_ip[20];
	int m_oprt;		
};

#endif

