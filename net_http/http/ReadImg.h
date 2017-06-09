/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-10 18:40
 * Filename         : ReadImg.h
 * Description      : 
 *********************************************************/

#ifndef _READIMG_H
#define _READIMG_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>

class ReadImg {
public:
	ReadImg(std::string filename) {
		fin.open(filename.c_str(), std::ios::binary);
	}

private:
	uint8_t *data;
	std::ifstream fin;
};

#endif

