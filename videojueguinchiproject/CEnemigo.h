#pragma once
#include "CPersonaje.h"
class CEnemigo :
	public CPersonaje
{
public:
virtual void Inicializa(); //No la usamos
	CEnemigo(int a, int b, int c, float d, float e, int f, int g); //ataque fisico, habilidad, salud, def fis, def hab, nivel, aguante
	~CEnemigo();
};

