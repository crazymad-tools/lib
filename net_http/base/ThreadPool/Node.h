/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-21 19:42
 * Filename         : Node.h
 * Description      : 
 *********************************************************/

#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <vector>
#include <boost/bind.hpp>
#include <boost/function.hpp>

using namespace std;
using namespace crazy;

class Node {
public:
	Node() {
		func = boost::bind(&Node::test, this);
	}
	vector<Thread> threads;
	void test() {
		cout << "hello world!" << endl;
	}
	void create() {
		for (int i = 0; i < 3; i++) {
			threads.push_back(Thread(func));
			threads[i].start();
		}
	}
	boost::function<void (void)> func;
};

#endif

