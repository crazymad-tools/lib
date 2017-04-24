/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-04-24 20:24
 * Filename         : vector.h
 * Description      : 
 *********************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#include <string.h>

template<typename T>
class Vector {
public:
	explicit Vector(int size = 0, int cap = 5)
		: mSize(size), mCap(cap)
   	{
		mArray = new int[cap];
	}
	~Vector() {
		delete [] mArray;
	}
	class iterator {
	public:
		iterator(T* p) {
			this->p = p;
		}	
		T& operator++(int) {
			iterator res = *this;
			p++;
			return res;
		}
		T& operator++() {
			p++;
			return *this;
		}
		T operator*() {
			return *p;
		}
	private:
		T* p;
	};
	void push_back(T value) {
		if (++mSize > mCap) {
			doubleCap();
		}
		mArray[mSize-1] = value;
	}
	void push_pop() {
		if (mSize) mArray[--mSize];
	}
	T operator[](int index) {
		return mArray[index];
	}
	iterator end() {
		return iterator(mArray+mSize-1);
	}
	iterator begin() {
		return iterator(mArray);
	}
private:
	void doubleCap() {
		T* newArray = new T[(mCap*=2)];
		memcpy(newArray, mArray, mCap/2);
		mArray = newArray;
	}

private:
	int mCap;			// capacity
	int mSize;			// real size
	T* mArray;		
};

#endif

