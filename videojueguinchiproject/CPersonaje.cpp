/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 22/04/2016       |       |  */
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

	if (map.ComprobarContenido(input.x,input.y) == CMapa::m_eEnte::NADA) {		//Si en la pos no hay nada, se mueve
		m_Pos = input;
		map.ActualizarMapa(input.x, input.y, CMapa::PERSONAJE);
		return 1;	
	}
	if (map.ComprobarContenido(input.x, input.y) == CMapa::OBJETO) {		//Si en la pos hay un objeto, se mueve y (si puede) lo recoje
		if(/*Recoger_Objeto(i)*/1)
		{
			m_Pos = input;
			map.ActualizarMapa(input.x, input.y, CMapa::PERSONAJE);
			return 1;
		}
		else return 0;			//Había un objeto, pero como ya tenia uno no ha podido recogerlo
		
	}
	
	return 0;										//En la posición hay algún tipo de obstaculo. No se puede mover


}

void CPersonaje::Añadir_Buff()
{
	if (!m_bObjOn)
	{
		//Meter aquí la función item para calcular el buff y meterlo al personaje.
		m_bObjOn = true;
	}
}

bool CPersonaje::Recoger_Objeto(CItem item)
{
	if (!m_bObjDisp) 
		return 0; 					//ya tiene un objeto, no se ha podido recoger
	else
	{
		m_Obj = item;
		m_bObjDisp = 1;				//cambiamos el estado de disponibilidad de objeto tras recogerlo
		Añadir_Buff();
		return 1;					//el objeto se ha recogido
	}
}

//Falta la función actualizar y posiblemente el constructor