/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Inform�tica             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha �ltima Modificaci�n: 22/04/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#include "CPersonaje.h"

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

bool CPersonaje::Moverse(CPosicion input)
{
	int pos_max_x = m_iVel + m_Pos.x;	//Posici�n m�xima a la que se puede mover en x
	int pos_max_y = m_iVel + m_Pos.y;	//Posici�n m�xima a la que se puede mover en y

	if ((pos_max_x < input.x) || (pos_max_y < input.y))	//posible sobrecarga de operador <
		return 0;						//Error, no se puede mover tan lejos

	m_Pos = input;					
	return 1;							//Ok, se mueve a esa posici�n


}

void CPersonaje::A�adir_Buff()
{
	if (!m_bObjOn)
	{
		//Meter aqu� la funci�n item para calcular el buff y meterlo al personaje.
		m_bObjOn = true;
	}
}

//Falta la funci�n actualizar y posiblemente el constructor