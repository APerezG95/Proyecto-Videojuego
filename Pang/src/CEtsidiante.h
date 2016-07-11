#pragma once
#include "CPersonaje.h"
class CEtsidiante :
	public CPersonaje
{
public:
	virtual void Inicializa();
	CEtsidiante(char* text, char* careto);
	~CEtsidiante();
};

