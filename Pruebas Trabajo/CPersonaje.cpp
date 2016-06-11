/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Inform�tica             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha �ltima Modificaci�n: 18/05/2016       |       |  */
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

bool CPersonaje::Moverse(CPosicion input, CMapa* map)
{
	int pos_max_x = m_iVel + m_Pos.x;	//Posici�n m�xima a la que se puede mover en x
	int pos_max_y = m_iVel + m_Pos.y;	//Posici�n m�xima a la que se puede mover en y

	if ((pos_max_x < input.x) || (pos_max_y < input.y))	//posible sobrecarga de operador <
		return 0;						//Error, no se puede mover tan lejos

	if ((map->ComprobarContenido(input.x,input.y)).m_Type == CEnte::NADA) //Si en la pos no hay nada, se mueve
	{		
		map->ActualizarMapa(input.x, input.y, CEnte::PERSONAJE);	//Colocamos al personaje
		map->ActualizarMapa(m_Pos.x, m_Pos.y, CEnte::NADA);
		m_Pos = input;
		return 1;	
	}

	if ((map->ComprobarContenido(input.x, input.y)).m_Type == CEnte::ITEM)
	{		//Si en la pos hay un objeto, si puede se mueve y lo recoje
		if(m_bObjDisp)
		{
			Recoger_Objeto(&map->ComprobarContenido(input.x, input.y));
			map->ActualizarMapa(input.x, input.y, CEnte::PERSONAJE);
			map->ActualizarMapa(m_Pos.x, m_Pos.y, CEnte::NADA);
			m_Pos = input;

			return 1;
		}
		else return 0;			//Hab�a un objeto y ya tiene uno, no puede moverse
	}
	
	if ((map->ComprobarContenido(input.x, input.y)).m_Type == CEnte::INACCESIBLE)	//En la posici�n hay alg�n tipo de obstaculo. No se puede mover
		return 0;

	if ((map->ComprobarContenido(input.x, input.y)).m_Type == CEnte::PERSONAJE)	//Ya hay un personaje en esa casilla, no puedes moverte.
		return 0;

}

void CPersonaje::A�adir_Buff(CBonus bonus)
{
	if (!m_bObjOn)
	{
		switch (bonus.getType())
		{
		case CBonus::SALUD:
		{
			m_iSalud += bonus.getBonus();
			break;
		}
		case CBonus::VEL:
		{
			m_iVel += bonus.getBonus();
			break;
		}
		case CBonus::ATQ_FIS:
		{
			m_iAtq_fis += bonus.getBonus();
			break;
		}
		case CBonus::ATQ_HAB:
		{
			m_iAtq_hab += bonus.getBonus();
			break;
		}
		case CBonus::DEF_FIS:
		{
			m_iDef_fis += bonus.getBonus();
			break;
		}
		case CBonus::DEF_HAB:
		{
			m_iDef_hab += bonus.getBonus();
			break;
		}
		case CBonus::SALUD_MAX:
		{
			m_iSaludMax += bonus.getBonus();
			m_iSalud = m_iSaludMax;
			break;
		}
		case CBonus::AGUANTE:
		{
			if (m_iAguante += bonus.getBonus() <= m_iAguanteMax)
				m_iAguante += bonus.getBonus();
			else
				m_iAguante = m_iAguanteMax;
			break;
		}

		}
		m_bObjOn = true;
	}
}

void CPersonaje::Recoger_Objeto(CEnte* item)
{
		m_Obj = *((CItem*) item);
		m_bObjDisp = false;				//cambiamos el estado de disponibilidad de objeto tras recogerlo
		A�adir_Buff(item->getDatos());
}

//Falta la funci�n actualizar y posiblemente el constructor