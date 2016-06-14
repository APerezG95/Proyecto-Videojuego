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


//Falta la función actualizar y posiblemente el constructor
