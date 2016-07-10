#pragma once
#include "CPersonaje.h"
class CPasota :
	public CPersonaje
{
public:
virtual void dibuja(int, int);
	virtual void Inicializa();
	CPasota(char* text);
	~CPasota();
};


