#pragma once
#include "CPosicion.h"
#include "CBonus.h"

#define MAX_NOM 20

class CItem{
private:
	CBonus m_Bonus;               
	char m_sName[MAX_NOM];                        
	CPosicion m_Pos;
public:
	CItem(char* name, CPosicion Pos, CBonus bonus);
	CItem(CBonus);
	
};

