#pragma once
#include "CPersonaje.h"
class CCordilleras :
	public CPersonaje
{
public:
	virtual void dibuja(int, int);
	CCordilleras();
	~CCordilleras();
	virtual void Inicializa();
};

