#pragma once
#include "CPersonaje.h"
class CTuno :
	public CPersonaje
{
public:
	virtual void Inicializa();
	CTuno(char* text, char* careto);
	~CTuno();
};

