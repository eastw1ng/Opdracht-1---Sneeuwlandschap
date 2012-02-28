/*
 * SneeuwLandschap.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_


#include <ma.h>
#include <MAUtil/Vector.h>
#include "SneeuwMan.h"
#include "SneeuwVlok.h"

using namespace MAUtil;

class SneeuwLandschap
{
private:
	int sneeuwHoogte;
	SneeuwMan* sneeuwMan;
	Vector<SneeuwVlok*> vlokjes;
public:
	SneeuwLandschap();
	void draw();
	void run( MAEvent event );
};


#endif /* SNEEUWLANDSCHAP_HPP_ */
