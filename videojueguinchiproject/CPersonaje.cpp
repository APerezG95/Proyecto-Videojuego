/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 07/05/2016       |       |  */
/*  |       |---------------------------------------------------- |       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#include "CPersonaje.h"
#include "CMapa.h"


int CPersonaje::Atacar(int consumo, bool tipodaño, int proporcion)
{
	if (tipodaño == 0)					//Daño físico
		return m_iAtq_fis;				//Devuelve el daño crudo

	else
	{
		m_iAguante -= consumo;			//Daño de habilidad
		return m_iAtq_hab*proporcion;	//Devuelve el daño con la habilidad proporcionalmente
	}
}

int CPersonaje::Defender(int dmg, bool tipodaño)
{
	if (tipodaño == 0)					//Daño físico
		return (dmg - dmg*m_iDef_fis);	//Reducción proporcional con defensa física

	else
		return (dmg - dmg*m_iDef_hab);	//Daño de habil, idem con la defensa de habil.

}

void CPersonaje::Actualizar()
{
}

bool CPersonaje::Moverse(CPosicion input, CMapa map)
{
	int pos_max_x = m_iVel + m_Pos.x;	//Posición máxima a la que se puede mover en x
	int pos_max_y = m_iVel + m_Pos.y;	//Posición máxima a la que se puede mover en y

	if ((pos_max_x < input.x) || (pos_max_y < input.y))	//posible sobrecarga de operador <
		return 0;						//Error, no se puede mover tan lejos

	if ((map.ComprobarContenido(input.x,input.y)).m_Type == CEnte::NADA) //Si en la pos no hay nada, se mueve
	{		
		map.ActualizarMapa(input.x, input.y, CEnte::PERSONAJE);	//Colocamos al personaje
		map.ActualizarMapa(m_Pos.x, m_Pos.y, CEnte::NADA);
		m_Pos = input;
		return 1;	
	}

	if ((map.ComprobarContenido(input.x, input.y)).m_Type == CEnte::ITEM)
	{		//Si en la pos hay un objeto, si puede se mueve y lo recoje
		if(m_bObjDisp)
		{
			Recoger_Objeto(map.ComprobarContenido(input.x, input.y));	//Ojo, aquí problema
			map.ActualizarMapa(input.x, input.y, CEnte::PERSONAJE);
			map.ActualizarMapa(m_Pos.x, m_Pos.y, CEnte::NADA);
			m_Pos = input;

			return 1;
		}
		else return 0;			//Había un objeto y ya tiene uno, no puede moverse
	}
	
	if ((map.ComprobarContenido(input.x, input.y)).m_Type == CEnte::INACCESIBLE)	//En la posición hay algún tipo de obstaculo. No se puede mover
		return 0;

	if ((map.ComprobarContenido(input.x, input.y)).m_Type == CEnte::PERSONAJE)	//Ya hay un personaje en esa casilla, no puedes moverte.
		return 0;

}

void CPersonaje::Añadir_Buff(CItem item)
{
	if (!m_bObjOn)
	{
		switch (item.m_Bonus.getType())	//EnTUBOCA EL SWITCH
		{
		case CBonus::SALUD:
		{
			//ACABELO WEY
		}
		}
		m_bObjOn = true;
	}
}

void CPersonaje::Recoger_Objeto(CItem item)
{
		m_Obj = item;
		m_bObjDisp = false;				//cambiamos el estado de disponibilidad de objeto tras recogerlo
		Añadir_Buff(item);
}

//Falta la función actualizar y posiblemente el constructor