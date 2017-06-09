/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-20 14:48
 * Filename         : Mutex.h
 * Description      : 
 *********************************************************/

#ifndef _CMUTEX_H
#define _CMUTEX_H

#include <pthread.h>

namespace crazy {

class CMutex {
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
	MutexMonitor(CMutex& mutex)
		: mutex(mutex)   
	{
		mutex.lock();
	}
	~MutexMonitor() {
		mutex.unlock();
	}
private:
	CMutex& mutex;
};

}

#endif

