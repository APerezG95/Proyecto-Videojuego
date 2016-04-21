#pragma once

class CBonus 
{
private:
	enum m_eTipo{ SALUD, DEF_FIS, DEF_HAB, ATAC_FIS, ATAQ_HAB, VEL };
	m_eTipo Tipo;
	int m_iBonus;

public:
	CBonus(m_eTipo tipo, int bonus);
	CBonus();
	m_eTipo getType();
	int getBonus();




};