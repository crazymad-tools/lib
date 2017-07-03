/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-07-02 01:28
 * Filename         : Epoll.h
 * Description      : 
 *********************************************************/

#ifndef _EPOLL_H
#define _EPOLL_H

class Epool {
private:
	int efd;			// epoll套接字

public:
	void add(int fd);
	void get(int fd[]);
};

#endif

