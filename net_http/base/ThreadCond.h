/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:46
 * Filename         : ThreadCond.h
 * Description      : 
 *********************************************************/

#ifndef _THREADCOND_H
#define _THREADCOND_H

#include <pthread.h>
#include <stdio.h>
#include "Mutex.h"

namespace crazy {

class ThreadCond {
public:
	ThreadCond(Mutex& mutex_) 
		: mutex_(mutex_)   
	{
		pthread_cond_init(&cond_, NULL);
	}
	~ThreadCond() {
		pthread_cond_destroy(&cond_);
	}
	void wait();
	void notify();
	void notifyAll();
	
private:
	pthread_cond_t cond_;
	Mutex& mutex_;
};

}					// 命名空间结束位置

#endif

