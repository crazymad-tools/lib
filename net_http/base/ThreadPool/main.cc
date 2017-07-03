/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:03
 * Filename         : main.cc
 * Description      : 
 *********************************************************/

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "Thread.h"
#include "CMutex.h"
#include "ThreadCond.h"
#include "ThreadPool.h"
#include "Node.h"

using namespace std;
using namespace crazy;

CMutex mutex_;
ThreadCond cond_(mutex_);

void wait_() {			// 等待其他线程条件变量该表
	MutexMonitor monitor(mutex_);
	cond_.wait();
	cout << "等待结束" << endl;
}

void call() {			// 告知其他线程条件变量改变
	sleep(1);
	cond_.notify();
}

void test() {
	sleep(1);
	std::cout << "hello world!" << std::endl;
}

void create() {

}


int main() {
	ThreadPool *pool = new ThreadPool(3);
	pool->start();
	pool->run(boost::bind(&test));
	pause();
	delete pool;

	return 0;
}

int main4() {
	Node node;
	node.create();
	sleep(1);
	return 0;
}

/*
int mai1n3() {
	vector<Thread> threads;
	threads.push_back(Thread());
	threads[0].create(std::bind(test));
	sleep(1);

	return 0;
}*/

int main2() {
	ThreadPool* pool = new ThreadPool(2);
	pool->start();
	//sleep(1);
	pool->run(boost::bind(test));
	pool->run(boost::bind(test));
	pool->run(boost::bind(test));
	pool->run(boost::bind(test));
	/*while (1) {
		;
	}*/
	sleep(3);
	cout << "准备关闭线程池" << endl;
	delete pool;

	return 0;
}
/*

int main1(int argc, char* argv[])
{/
	Thread thread_1, thread_2;
	thread_1.create(std::bind(wait_));
	thread_2.create(std::bind(call));
	thread_1.join();
	thread_2.join();

	return 0;
}*/
