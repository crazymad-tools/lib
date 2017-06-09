/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-04-05 19:09
 * Filename         : ptr.h
 * Description      : 
 *********************************************************/

#ifndef _PTR_H
#define _PTR_H

#include "Atomic.h"
#include <stdlib.h>

template<typename T>
class Ptr {
public:
	Ptr(T *value_ = NULL) {
		this->value_ = value_;
		if (this->value_ == NULL) {
			value_ = new T();
		}
		count_++;
	}	
	Ptr(Ptr &src) {
		value_ = src.value_;
		count_.getAndAdd(++src.count_);
	}
	~Ptr() {
		if (--count_ == 0) {
			delete value_;
		} 
	}
	T& operator*() {
		return *value_;
	}
	Ptr& operator=(Ptr &src) {
		if (count_.get() == 1) {
			delete value_;
		}
		count_++;
		src.count_++;
		value_ = src.value_;
	}
	long long get_count() {
		return static_cast<long long>(count_.get());
	}
	friend T& operator*() {
		return *value_;
	}

private:
	//int *using_count;
	T *value_;
	muduo::AtomicInt64 count_;

};

#endif

