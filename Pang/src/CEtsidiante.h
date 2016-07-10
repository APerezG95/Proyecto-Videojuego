#pragma once
#include "CPersonaje.h"
class CEtsidiante :
	public CPersonaje
{
public:
virtual void dibuja(int, int);
	virtual void Inicializa();
	CEtsidiante(char* text);
	~CEtsidiante();
};

