/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:05
 * Filename         : Thread.h
 * Description      : 
 *********************************************************/

#ifndef _THREAD_H
#define _THREAD_H

#include <functional>
#include <pthread.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <utility>

namespace crazy {

typedef boost::function<void (void)> Func;
class ThreadData {
public:
	ThreadData(Func &func)
		: func(func)
   	{ }
	void runInThread() {
		func();
	}
	Func func;
};

class Thread {
public:
	Thread(Func& func) 
		: func(func)
	{
	//	this->func();
	}
	void start();
	void runInThread();
	void join() {
		pthread_join(p_id, NULL);
	}
	
private:
	Func func;		// 线程中需要执行的函数
	pthread_t p_id;
	ThreadData *threadData;
};

}						// 命名空间结束

#endif

