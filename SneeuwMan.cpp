/*
 * SneeuwMan.cpp
 *
 *  Created on: Feb 27, 2012
 *      Author: Administrator
 */
#include <ma.h>
#include "SneeuwMan.h"

SneeuwMan::SneeuwMan(int positionX, int positionY, int size) {
	this->size = size;
	this->positionX = positionX;
	this->positionY = positionY;
}

void SneeuwMan::move(int direction){
	positionX += direction;
}

void SneeuwMan::draw(){
	int headSize = size/2;

	maSetColor(0x888888);
	maFillRect(this->positionX-size/2, this->positionY-size, size, size);
	maFillRect(this->positionX-headSize/2, this->positionY-size-headSize, headSize, headSize);
}

