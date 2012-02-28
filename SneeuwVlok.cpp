/*
 * SneeuwVlok.cpp
 *
 *  Created on: Feb 27, 2012
 *      Author: Administrator
 */
#include <ma.h>
#include "SneeuwVlok.h"

bool dead = false;

SneeuwVlok::SneeuwVlok(int positionX, int positionY, int size) {
	this->size = size;
	this->positionX = positionX;
	this->positionY = positionY;
}

void SneeuwVlok::fall(int sneeuwHoogte){
	MAExtent screenSize = maGetScrSize();

	if(positionY >= EXTENT_Y( screenSize )-sneeuwHoogte){
		dead = true;
	}else{
		this->positionY += 5;
	};
}

void SneeuwVlok::draw(){
	maSetColor(0xffffff);
	maFillRect(this->positionX, this->positionY, size, size);
}

bool SneeuwVlok::isDead(){
	return dead;
}
