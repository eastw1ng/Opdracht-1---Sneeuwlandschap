/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#include "SneeuwLandschap.h"

//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;

//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan(screenWidth/2, screenHeight - this->sneeuwHoogte, 40);
}

//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}


	//Voeg een sneeuwvlok toe
	vlokjes.add(new SneeuwVlok(rand() % screenWidth,0,rand() % 10+2));

	//Laat alle sneeuwvlokken vallen en verwijder de DODE vlokken
	for(int i = 0;i<vlokjes.size();i++){
		if(vlokjes[i]->isDead()){
			vlokjes.remove(i);
		}else{
			vlokjes[i]->fall(sneeuwHoogte);
		}
	};
}


//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0B0B3B );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	//Teken de sneeuwman
	this->sneeuwMan->draw();

	//Teken alle sneeuwvlokken
	for(int i = 0;i<vlokjes.size();i++){
		vlokjes[i]->draw();
	};
}


