#include "CItem.h"
#include "CBonus.h"

CItem::CItem(char * name, CPosicion Pos, CBonus Bonus):m_Pos(Pos)
{
	*m_sName = *name;
	m_Bonus = Bonus;
}



CItem::CItem(CBonus bonus)
{
	for (int i = 0; i < MAX_NOM; i++)
	{
		m_sName[i] = ' ';
	}
	m_Bonus = bonus;
	m_Pos.x = 0;	m_Pos.y = 0;

}