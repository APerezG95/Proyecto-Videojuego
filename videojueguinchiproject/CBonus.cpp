#include "CBonus.h"

CBonus::CBonus(m_eTipo tipo, int bonus)
{
	m_iBonus = bonus;
	Tipo = tipo;
}

CBonus::m_eTipo CBonus::getType()
{
	return Tipo;
}

int CBonus::getBonus()
{
	return m_iBonus;
}
