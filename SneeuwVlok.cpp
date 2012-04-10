/*
 * SneeuwVlok.cpp
 *
 *  Created on: Feb 27, 2012
 *      Author: Administrator
 */
#include <ma.h>
#include "SneeuwVlok.h"

//Constructor
SneeuwVlok::SneeuwVlok(int positionX, int positionY, int size) {
	this->dead = false;
	this->size = size;
	this->positionX = positionX;
	this->positionY = positionY;
}

//Wordt aangeroepen door sneeuwlandschap het vlokje te laten vallen
void SneeuwVlok::fall(int sneeuwHoogte){
	MAExtent screenSize = maGetScrSize();

	//Laat het vlokje vallen of markeert het vlokje als dood als het de sneeuw raakt
	if(positionY >= EXTENT_Y( screenSize )-sneeuwHoogte){
		this->dead = true;
	}else{
		this->positionY += 5;
	};
}

//Wordt aangeroepen door sneeuwlandschap het vlokje te laten tekenen
void SneeuwVlok::draw(){
	maSetColor(0xffffff);
	maFillRect(this->positionX, this->positionY, size, size);
}

//Methode die de status van het vlokje opvraagt
bool SneeuwVlok::isDead(){
	return dead;
}

SneeuwVlok::~SneeuwVlok() {
}
