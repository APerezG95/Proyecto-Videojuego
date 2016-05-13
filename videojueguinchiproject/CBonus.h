#pragma once

class CBonus 
{
private:
	
	
	int m_iBonus;                                                    //Valor del bonus. Independiente del tipo

public:
	enum m_eTipo { SALUD_MAX, SALUD, DEF_FIS, DEF_HAB, ATQ_FIS, ATQ_HAB, VEL, AGUANTE };
	m_eTipo Tipo;
	CBonus(m_eTipo tipo, int bonus);
	CBonus();                                                        //por defecto valor=0
	m_eTipo getType();
	int getBonus();




};