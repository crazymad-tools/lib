/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-04-24 20:26
 * Filename         : main.cc
 * Description      : 
 *********************************************************/

#include <Vector.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	Vector<int>::iterator it = vec.begin();
	char buf[10] = "hello";
	//cout << strlen(buf) << endl;

	return 0;
}
