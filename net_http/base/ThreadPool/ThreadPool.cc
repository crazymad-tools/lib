/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:03
 * Filename         : ThreadPool.cc
 * Description      : 
 *********************************************************/

#include "ThreadPool.h"

using namespace crazy;

void ThreadPool::start() {
	for (int i = 0; i < threadsNum; i++) {
		threads.push_back(new Thread(func));
	}
	running = true;				// 现在开启线程
	for (int i = 0; i < threadsNum; i++) {
		threads[i]->start();
	}
}
void ThreadPool::run(boost::function<void (void)> task) {
	taskQueue.push(task);
	notEmpty.notify();
}
boost::function<void (void)> ThreadPool::take() {
	boost::function<void(void)> res;
	MutexMonitor monitor(mutex_);
	while (taskQueue.empty() && running) {
		notEmpty.wait();
	}
	if (taskQueue.size() > 0) {
		res = taskQueue.front();
		taskQueue.pop();
	}
	if (taskQueue.size() > 0) {
		notEmpty.notify();
	}
	return res;
}
void ThreadPool::runInThread() {
	while (running) {
		boost::function<void (void)> task = take();
		if (task) {
			task();
		}
	}
}

