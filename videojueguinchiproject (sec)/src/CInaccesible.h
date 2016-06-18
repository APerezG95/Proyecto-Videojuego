#pragma once
#include "CEnte.h"

class CInaccesible: public CEnte
{
public:
	virtual void foo() {};

	CInaccesible() {};
	~CInaccesible();
};

