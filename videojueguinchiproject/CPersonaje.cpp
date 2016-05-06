/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Inform�tica             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha �ltima Modificaci�n: 22/04/2016       |       |  */
/*  |       |---------------------------------------------------- |       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#include "CPersonaje.h"
#include "CMapa.h"


int CPersonaje::Atacar(int consumo, bool tipoda�o, int proporcion)
{
	if (tipoda�o == 0)					//Da�o f�sico
		return m_iAtq_fis;				//Devuelve el da�o crudo

	else
	{
		m_iAguante -= consumo;			//Da�o de habilidad
		return m_iAtq_hab*proporcion;	//Devuelve el da�o con la habilidad proporcionalmente
	}
}

int CPersonaje::Defender(int dmg, bool tipoda�o)
{
	if (tipoda�o == 0)					//Da�o f�sico
		return (dmg - dmg*m_iDef_fis);	//Reducci�n proporcional con defensa f�sica

	else
		return (dmg - dmg*m_iDef_hab);	//Da�o de habil, idem con la defensa de habil.

}

void CPersonaje::Actualizar()
{
}

bool CPersonaje::Moverse(CPosicion input, CMapa map)
{
	int pos_max_x = m_iVel + m_Pos.x;	//Posici�n m�xima a la que se puede mover en x
	int pos_max_y = m_iVel + m_Pos.y;	//Posici�n m�xima a la que se puede mover en y

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
		else return 0;			//Hab�a un objeto, pero como ya tenia uno no ha podido recogerlo
		
	}
	
	return 0;										//En la posici�n hay alg�n tipo de obstaculo. No se puede mover


}

void CPersonaje::A�adir_Buff()
{
	if (!m_bObjOn)
	{
		//Meter aqu� la funci�n item para calcular el buff y meterlo al personaje.
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
		A�adir_Buff();
		return 1;					//el objeto se ha recogido
	}
}

//Falta la funci�n actualizar y posiblemente el constructor