#pragma once
#include "CPersonaje.h"
#include "CMapa.h"


class CEnemigo :
	public CPersonaje
{
public:
	void Inicializa();
	CEnemigo(char* text, char* careto);
	~CEnemigo();
};

