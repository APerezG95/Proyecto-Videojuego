#pragma once
#include "CPersonaje.h"
#include "CMapa.h"


class CEnemigo :
	public CPersonaje
{
public:
virtual void dibuja(int, int);

	CEnemigo(); 
	~CEnemigo();
	void SeleccionObjetivo(CMapa map);
};

