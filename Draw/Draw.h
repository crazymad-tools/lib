/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-06-09 16:44
 * Filename         : Draw.h
 * Description      : 
 *********************************************************/

#ifndef _DRAW_H
#define _DRAW_H

class Draw {
private:
	int col;			// 列宽
	int row;			// 行高


public:
	Draw();				// 获取屏幕尺寸
	void reset(int x1, int y1, int x2, int y2);	// 擦除
	void line(int x1, int y1, int x2, int y2, char ch);	// 绘制线
	void print(int x, int y, char* str, int len);	// 定点输出字符串
	int getCol();
	int getRow();
	void move(int x, int y);
};

#endif

