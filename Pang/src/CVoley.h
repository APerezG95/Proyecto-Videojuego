#pragma once
#include "CPersonaje.h"
class CVoley :
	public CPersonaje
{
public:
	virtual void Inicializa();
	CVoley(char* text, char* careto);
	~CVoley();
};

