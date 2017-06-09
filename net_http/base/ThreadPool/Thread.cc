/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:05
 * Filename         : Thread.cc
 * Description      : 
 *********************************************************/

#include "Thread.h"
#include <stdio.h>

using namespace crazy;

static void* startThread(void *obj) {
	ThreadData *thread = static_cast<ThreadData*>(obj);
	thread->runInThread();
	delete thread;
	return NULL;
}

void Thread::start() {
	threadData = new ThreadData(func);
	pthread_create(&p_id, NULL, &startThread, threadData);
}

void Thread::runInThread() {
	//printf("线程---\n");
	this->func();
}
