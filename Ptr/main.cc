/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-11 19:18
 * Filename         : main.cc
 * Description      : 
 *********************************************************/

#include "Atomic.h"
#include "Ptr.h"
#include <iostream>

using namespace std;

int main() {
	muduo::AtomicInt32 a;
	a.getAndAdd(19);
	cout << a.get() << endl;

	//char *c = new(char);
	Ptr<char> ppp(new char('c'));
	
	return 0;
}
