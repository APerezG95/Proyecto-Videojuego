/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Inform�tica             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha �ltima Modificaci�n: 18/05/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#pragma once
#include "CPosicion.h"

class CEnte
{
public:
	enum  m_eTipo { PERSONAJE, ITEM, NADA, INACCESIBLE };
	CEnte();
	~CEnte();
	m_eTipo m_Type;
	virtual CBonus getDatos();

protected:
	CPosicion m_Pos;
	
};

