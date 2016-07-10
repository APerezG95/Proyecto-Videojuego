#pragma once
#include "CPersonaje.h"
#include "ETSIDI.h"


class CDestruye :
	public CPersonaje
{
public:
	virtual void dibuja();
	virtual void Inicializa();
	CDestruye(char* text);
	~CDestruye();
	virtual bool ataque_esp(CPersonaje &p, int consumo = 0, bool tipodano = 0, int dano_base = 1);	//Tipodaño 0 para debilitar y 1 para hacer daño de habilidad. daño_base es el daño de la habilidad. Consumo es para el gasto de Aguante.
};

