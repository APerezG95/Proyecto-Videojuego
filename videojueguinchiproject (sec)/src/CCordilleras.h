#pragma once
#include "CPersonaje.h"
#include "ETSIDI.h"


class CCordilleras :
	public CPersonaje
{
public:
	ETSIDI::SpriteSequence textura;
	virtual void dibuja();
	CCordilleras();
	~CCordilleras();
	virtual void Inicializa();
};

