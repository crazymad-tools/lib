/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-06-09 17:29
 * Filename         : main.cc
 * Description      : 
 *********************************************************/

#include <Draw.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
	system("clear");
	Draw draw;
	draw.border();
	draw.line(3, 2, 3, draw.getCol()-1, '_');
	draw.line(4, 30, draw.getRow(), 30, '|');
	draw.print(2, 2, "server statu", strlen("server statu"));
	draw.print(4, 2, "在线列表", strlen("在线列表"));
	draw.print(4, 31, "即时消息", strlen("即时消息"));
	draw.move(draw.getRow(), 1);
	pause();
	draw.print(draw.getRow(), 1, "\n", 1);

	return 0;
}
