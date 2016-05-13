/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Adrián Pérez Gutiérrez               |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 13/05/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */


#pragma once
#include "CPosicion.h"
#include "CBonus.h"
#include "CEnte.h"

#define MAX_NOM 20

class CItem: public CEnte
{
private:         
	char m_sName[MAX_NOM];
public:
	CBonus m_Bonus;
	CItem(char* name, CPosicion Pos, CBonus bonus);
	CItem(CBonus);                                  //Nombre en blanco y posicion (0,0)
	
};

