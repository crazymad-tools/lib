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
		func = boost::bind(&ThreadPool::runInThread, this);		// 设置回调函数(无意义，可删)
		running = false;										// 线程池出事状态为关闭状态
	}
	~ThreadPool() {
		running = false;										// 改变线程逻辑状态，告知线程对象在执行完手头的任务后退出线程
		notEmpty.notifyAll();									// 告知所有线程对象读取一下线程池逻辑状态
		for (int i = 0; i < threadsNum; i++) {	
			threads[i]->join();									// 等待每一个线程退出，防止还有尚在执行任务的线程
		}
		for (int i = 0; i < threadsNum; i++) {
			delete threads[i];									// 暂时先这样写，以后改成智能指针
		}
	}
	void start();												// 开启线程池
	void run(boost::function<void (void)> task);				// 放置任务
	boost::function<void (void)> take();						// 线程对象获取任务的函数
	void runInThread();											// 线程对象的回调函数

private:
	std::vector<Thread*> threads;								// 线程列表
	std::queue<boost::function<void (void)> > taskQueue;		// 任务列表
	boost::function<void (void)> func;
	int threadsNum;												// 线程数量
	Mutex mutex_;
	ThreadCond notEmpty;								// 告知线程池当前任务列表已不为空
	bool running;										// 标记当前线程池状态
};

}								// 命名空间结束位置 

#endif

