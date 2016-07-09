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

void CPersonaje::dibuja()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);

	textura.setPos((m_Pos.x), (m_Pos.y));
	textura.setState(orientacion());
	textura.draw();

	glPopMatrix(); 
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


CPersonaje::CPersonaje():
	textura("imagenes/Hippie.png", 3, 4, 50, false, 0, 0, 0, 0, 1),
	m_Pos(15,15)
{

	textura.setCenter(0, 0);
	textura.setSize(1, 1);
}

bool CPersonaje::ataque_esp(CPersonaje &p, int consumo, bool tipodano, int dano_base)
{
	float danio;
	if (tipodano == 0) {					//Daño físico
		if (m_iAguante < consumo) return 0;
		danio = dano_base*(1 - p.m_iDef_fis);
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
		danio = dano_base*(1 - p.m_iDef_hab);
		p.m_iSalud = p.m_iSalud - danio;
		if (p.m_iSalud <= 0) {
			p.m_iSalud = 0;
			p.m_bDisp = 0;
		}
		m_iAguante -= consumo;
		return 1;
	}
}


int CPersonaje::orientacion()	//Devuelve el índice dentro de la imagen que se usa en setState();
{
	if ((posAntigua.x) > (getPos().x))
		return 4;
	if ((posAntigua.x) < (getPos().x))
		return	7;
	if ((posAntigua.y) > (getPos().y))
		return 2;
	if ((posAntigua.y) < (getPos().y))
		return 10;
}
