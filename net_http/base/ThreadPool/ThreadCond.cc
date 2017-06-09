/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-22 20:37
 * Filename         : ThreadCond.cc
 * Description      : 
 *********************************************************/

#include "ThreadCond.h"

using namespace crazy;

void ThreadCond::wait() {
	pthread_cond_wait(&cond_, &(mutex_.getMutex()));
}

void ThreadCond::notify() {
	pthread_cond_signal(&cond_);
}

void ThreadCond::notifyAll() {
	pthread_cond_broadcast(&cond_);
}
