/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 18/05/2016       |       |  */
/*  |       |---------------------------------------------------- |       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#include "CPersonaje.h"
#include "CMapa.h"


bool CPersonaje::ataque_hab(CPersonaje &p) {
	if (m_iAguante < 20) return 0;
	float danio;
	danio = m_iAtq_hab*(1-p.m_iDef_hab);
	p.m_iSalud = p.m_iSalud - danio;
	if (p.m_iSalud <= 0) {
		p.m_iSalud = 0;
		p.m_bDisp = 0;
	}
	m_iAguante -= 15;
	return 1;
}

void CPersonaje::ataque_fis(CPersonaje &p) {
	float danio;
	danio = m_iAtq_fis*(1-p.m_iDef_fis);
	p.m_iSalud = p.m_iSalud - danio;
	if (p.m_iSalud <= 0) {
		p.m_iSalud = 0;
		p.m_bDisp = 0;
	}
}

bool CPersonaje::ataque_esp(CPersonaje &p, int consumo, bool tipodaño, int daño_base)
{
	float danio;
	if (tipodaño == 0) {					//Daño físico
		if (m_iAguante < consumo) return 0;
		danio = daño_base*(1 - p.m_iDef_fis);
		p.m_iSalud = p.m_iSalud - danio;
		if (p.m_iSalud <= 0) {
			p.m_iSalud = 0;
			p.m_bDisp = 0;
		}
		m_iAguante -= consumo;
		return 1;
	}
	else                                       //daño habilidad
	{
		if (m_iAguante < consumo) return 0;
		danio = daño_base*(1 - p.m_iDef_hab);
		p.m_iSalud = p.m_iSalud - danio;
		if (p.m_iSalud <= 0) {
			p.m_iSalud = 0;
			p.m_bDisp = 0;
		}
		m_iAguante -= consumo;
		return 1;
	}
}

void CPersonaje::Actualizar()
{
}

bool CPersonaje::Moverse(CPosicion input, CMapa* map)
{
	int pos_max_x = m_iVel + m_Pos.x;	//Posición máxima a la que se puede mover en x
	int pos_max_y = m_iVel + m_Pos.y;	//Posición máxima a la que se puede mover en y

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
		else return 0;			//Había un objeto y ya tiene uno, no puede moverse
	}
	
	if ((map->ComprobarContenido(input.x, input.y)).m_Type == CEnte::INACCESIBLE)	//En la posición hay algún tipo de obstaculo. No se puede mover
		return 0;

	if ((map->ComprobarContenido(input.x, input.y)).m_Type == CEnte::PERSONAJE)	//Ya hay un personaje en esa casilla, no puedes moverte.
		return 0;

}

void CPersonaje::Añadir_Buff(CBonus bonus)
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
		Añadir_Buff(item->getDatos());
}

//Falta la función actualizar y posiblemente el constructor
