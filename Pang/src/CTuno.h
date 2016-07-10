#pragma once
#include "CPersonaje.h"
class CTuno :
	public CPersonaje
{
public:
virtual void dibuja(int, int);
	virtual void Inicializa();
	CTuno(char* text);
	~CTuno();
};

