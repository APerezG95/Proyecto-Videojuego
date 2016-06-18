#pragma once
#include "CEnte.h"
#include "ETSIDI.h"

class CNada: public CEnte
{
public:
	ETSIDI::SpriteSequence textura;
	virtual void dibuja();
	CNada() :textura("imagenes/suelo13.png", 1,1,50,false,0,0,0,0,0) 
	{
		textura.setCenter(0, 0);
		textura.setSize(1, 1);
	};
	virtual void foo() {};
	~CNada();
};

