/*
 * SneeuwMan.cpp
 *
 *  Created on: Feb 27, 2012
 *      Author: Administrator
 */
#include <ma.h>
#include "SneeuwMan.h"

//Contstructor
SneeuwMan::SneeuwMan(int positionX, int positionY, int size) {
	this->size = size;
	this->positionX = positionX;
	this->positionY = positionY;
}

//Wordt aangeroepen door sneeuwlandschap om de sneeuwman te verplaatsen
void SneeuwMan::move(int direction){
	positionX += direction;
}

//Wordt aangeroepen door sneeuwlandschap om de sneeuwman te tekenen
void SneeuwMan::draw(){
	int headSize = size/2;

	//Zet de kleur
	maSetColor(0x888888);
	//Teken de vierkantjes
	maFillRect(this->positionX-size/2, this->positionY-size, size, size);
	maFillRect(this->positionX-headSize/2, this->positionY-size-headSize, headSize, headSize);
}

SneeuwMan::~SneeuwMan() {

}
