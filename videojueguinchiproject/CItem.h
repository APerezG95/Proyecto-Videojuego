#pragma once
#include "CPosicion.h"

class CItem{
private:
	//CBonus m_Bonus;               Clase bonus por definir
	/*enum m_eTipo{SALUD, DEF_FIS, DEF_HAB, ATAC_FIS, ATAQ_HAB, VEL};
	m_eTipo Tipo;                                                         Todo esto irá en la clase Bonus
	int m_iBonus;*/
	char m_sName[20];                        
	CPosicion m_Pos;
public:
	CItem(char* name, CPosicion Pos/*, CBonus Bonus*/);
};

