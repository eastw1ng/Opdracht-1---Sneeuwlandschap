/*
 * SneeuwMan.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#ifndef SNEEUWMAN_HPP_
#define SNEEUWMAN_HPP_


//bevat teken functies
#include <ma.h>

//de klasse SneeuwMan
class SneeuwMan
{
private:
	int positionX;	//x positie van sneeuwman
	int positionY;	//y positie van sneeuwman
	int size; //grootte van het object

public:
	//constructor
	SneeuwMan( int positionX, int positionY, int size);

	//beweeg de sneeuwman in de richting "direcion", negatief getal is links, positief is rechts
	void move( int direction );

	//tekent een sneeuwman
	void draw();
};


#endif /* SNEEUWMAN_HPP_ */
