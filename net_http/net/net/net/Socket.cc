/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-09 15:26
 * Filename         : Socket.cc
 * Description      : 
 *********************************************************/

#include <Socket.h>
//#include <net_def.h>

Socket::Socket(char ip[20], int port) {
	socketData.fd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&socketData.addr, 0, sizeof(struct sockaddr_in));
	socketData.addr.sin_family = AF_INET;
	socketData.addr.sin_port = htons(port);
	socketData.addr.sin_addr.s_addr = inet_addr(ip);
}
Socket::Socket(int port) {
	socketData.fd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&socketData.addr, 0, sizeof(struct sockaddr_in));
	socketData.addr.sin_family = AF_INET;
	socketData.addr.sin_port = htons(port);
	socketData.addr.sin_addr.s_addr = htonl(INADDR_ANY);
}	
Socket::Socket(struct SocketData socketData) { 
	this->socketData = socketData;
}

void Socket::Accept(struct SocketData* peer) {
	socklen_t len = sizeof(sockaddr_in);
	peer->fd = accept(socketData.fd, (struct sockaddr*)&peer->addr, &len);
}
bool Socket::Bind() {
	if (bind(socketData.fd, (struct sockaddr*)&socketData.addr, sizeof(struct sockaddr_in)) == -1) {
		perror("bind error");
		return false;
	}
	return true;
}
void Socket::Listen(int len) {
	listen(socketData.fd, len);
}
bool Socket::Connect() {
	if (connect(socketData.fd, (struct sockaddr*)&socketData.addr, sizeof(struct sockaddr_in)) == -1) {
		perror("connect error");
		return false;
	}
	return true;
}
int Socket::Read(struct SocketData* peer, char* buf, int len) {
	return read(peer->fd, buf, len);
}
int Socket::Read(char* buf, int len) {
	return read(socketData.fd, buf, len);
}
int Socket::Write(struct SocketData* peer, char* buf, int len) {
	return write(peer->fd, buf, len);
}
int Socket::Write(char* buf, int len) {
	return write(socketData.fd, buf, len);
}
void Socket::Close() {
	close(socketData.fd);
}
bool Socket::init() {
	int on = 1;
	if (setsockopt(socketData.fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on) == -1) {
		perror("setsockopt");
		return false;
	}
}
void Socket::setFd(int fd) {
	this->socketData.fd = fd;
}
int Socket::getFd() {
	return socketData.fd;
}
void Socket::setSocketData(SocketData socketData) {
	this->socketData = socketData;
}
char* Socket::ipToString(char* buf) {
	char ip[20] = "\0";
	inet_ntop(AF_INET, (void*)&socketData.addr, ip, 20);
	if (buf) {
		strcpy(buf, ip);
	} 
	return ip;
}
