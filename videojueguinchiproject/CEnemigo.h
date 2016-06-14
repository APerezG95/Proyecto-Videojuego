#pragma once
#include "CPersonaje.h"
class CEnemigo :
	public CPersonaje
{
public:
virtual void dibuja(int, int);
    void Inicializa(int a, int b, int c, float d, float e, int f, int g); //ataque fisico, habilidad, salud, def fis, def hab, nivel, aguante
	CEnemigo(); 
	~CEnemigo();
	void SeleccionObjetivo(CMapa map);
};

