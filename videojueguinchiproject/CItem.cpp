/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Adrián Pérez Gutiérrez               |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 18/05/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#include "CItem.h"
#include "CBonus.h"

CItem::CItem(char * name, CPosicion Pos, CBonus Bonus)
{
	m_Pos = Pos;
	*m_sName = *name;
	m_Bonus = Bonus;
}

CBonus CItem::getDatos()
{
	return m_Bonus;
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