#pragma once
#include "CPersonaje.h"
#include "ETSIDI.h"


class CCordilleras :
	public CPersonaje
{
public:
	CCordilleras(char* text, char* careto);
	~CCordilleras();
	virtual void Inicializa();
};

