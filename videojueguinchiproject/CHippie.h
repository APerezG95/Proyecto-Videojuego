#pragma once
#include "CPersonaje.h"
class CHippie :
	public CPersonaje
{
public:
	virtual void Inicializa();
	CHippie();
	~CHippie();
		virtual bool ataque_esp(CPersonaje &p, int consumo = 0, bool tipodaño = 0, int daño_base = 1);	//Tipodaño 0 para curar y 1 para hacer daño de habilidad. daño_base es el daño de la habilidad. Consumo es para el gasto de Aguante.
};
