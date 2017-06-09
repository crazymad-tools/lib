/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:03
 * Filename         : ThreadPool.h
 * Description      : 
 *********************************************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include "Thread.h"
#include "ThreadCond.h"
#include <queue>
#include <vector>
#include <functional>
#include <boost/bind.hpp>
#include <boost/function.hpp>

using namespace crazy;
namespace crazy {

class ThreadPool {
public:
	ThreadPool(int threadsNum) 
		: threadsNum(threadsNum), mutex_(), notEmpty(mutex_)
	{
		func = boost::bind(&ThreadPool::runInThread, this);
		running = false;
	}
	~ThreadPool() {
		running = false;
		notEmpty.notifyAll();
		for (int i = 0; i < threadsNum; i++) {
			threads[i]->join();
		}
		for (int i = 0; i < threadsNum; i++) {
			delete threads[i];
		}
	}
	void start(); 
	void run(boost::function<void (void)> task);
	boost::function<void (void)> take();
	void runInThread();

private:
	std::vector<Thread*> threads;								// 线程列表
	std::queue<boost::function<void (void)> > taskQueue;		// 任务列表
	boost::function<void (void)> func;
	int threadsNum;												// 线程数量
	CMutex mutex_;
	ThreadCond notEmpty;								// 告知线程池当前任务列表已不为空
	bool running;										// 标记当前线程池状态
};

}								// 命名空间结束位置 

#endif

