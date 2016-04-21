#pragma once
#include "CPosicion.h"
#include "CBonus.h"

class CItem{
private:
	CBonus m_Bonus;               
	char m_sName[20];                        
	CPosicion m_Pos;
public:
	CItem(char* name, CPosicion Pos, CBonus bonus);
	
};

