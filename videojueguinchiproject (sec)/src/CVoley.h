#pragma once
#include "CPersonaje.h"
class CVoley :
	public CPersonaje
{
public:
virtual void dibuja(int, int);
	virtual void Inicializa();
	CVoley();
	~CVoley();
};

