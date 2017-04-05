/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-04-05 19:09
 * Filename         : ptr.h
 * Description      : 
 *********************************************************/

#ifndef _PTR_H
#define _PTR_H

template<typename T>
class Ptr {
public:
	Ptr(T *kernel = NULL) {
		using_count = new int(1);
		this->kernel = kernel;
	}	
	Ptr(Ptr &src) {
		using_count = src.using_count;
		kernel = src.kernel;
		(*using_count)++;
	}
	~Ptr() {
		if (--(*using_count) == 0) {
			delete T;
			delete using_count;
		} 
	}
	T& operator*() {
		return *kernel;
	}
	Ptr& operator=(Ptr &src) {
		if (*using_count == 1) {
			delete using_count;
			delete kernel;
		}
		using_count = src.using_count;
		kernel = src.kernel;
	}
	Ptr& operator=(T *src) {
		if (*using_count == 1) {
			delete kernel;
		}
		kernel = src
	}

private:
	int *using_count;
	T *kernel;

};

#endif

