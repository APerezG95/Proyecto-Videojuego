#pragma once
#include "CPersonaje.h"
class CPasota :
	public CPersonaje
{
public:

	virtual void Inicializa();
	CPasota(char* text, char* careto);
	~CPasota();
};


