/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:48
 * Filename         : Mutex.h
 * Description      : 
 *********************************************************/

#ifndef _MUTEX_H
#define _MUTEX_H

#include <pthread.h>

class Mutex {
public:	
	void lock() {
		pthread_mutex_lock(&mutex);
	}
	void unlock() {
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_t& getMutex() {
		return mutex;
	}
private:
	pthread_mutex_t mutex;
};

class MutexMonitor {
public:
	MutexMonitor(Mutex& mutex)
		: mutex(mutex)   
	{
		mutex.lock();
	}
	~MutexMonitor() {
		mutex.unlock();
	}
private:
	Mutex& mutex;
};

#endif

