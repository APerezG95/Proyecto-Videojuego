#pragma once

class CBonus 
{
private:
	
	
	int m_iBonus;                                                    //Valor del bonus. Independiente del tipo

public:
	enum m_eTipo { SALUD, DEF_FIS, DEF_HAB, ATAC_FIS, ATAQ_HAB, VEL };
	m_eTipo Tipo;
	CBonus(m_eTipo tipo, int bonus);
	CBonus();                                                        //por defecto tipo salud y valor=0
	m_eTipo getType();
	int getBonus();




};