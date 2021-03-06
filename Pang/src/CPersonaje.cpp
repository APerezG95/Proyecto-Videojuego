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
#include <cmath>

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

void CPersonaje::dibuja(float xojo, float yojo)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);

	if (m_bDisp) {
		textura.setPos((m_Pos.x - 10.5), (m_Pos.y + 1.5));
		textura.setState(orientacion());
		textura.draw();
	}
	glPopMatrix(); 

	switch (m_iNum)
	{
	case 0:
	{
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		cara.setSize(2.95, 2.95);
		cara.setPos(xojo - 15.56, yojo + 6.03);
		cara.draw();
		glPopMatrix();

		glLineWidth(10);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(xojo - 12.1, yojo + 8.59, 0.0);
		glVertex3f(xojo + 2.5*((float)m_iSalud/(float)m_iSaludMax)-12.1, yojo + 8.59, 0);
		glEnd();
		break;
	}
	case 1:
	{
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		cara.setSize(2.95, 2.95);
		cara.setPos(xojo - 15.56, yojo - 1.6);
		cara.draw();
		glPopMatrix();

		glLineWidth(9.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(xojo - 12.1, yojo + 0.673, 0.0);
		glVertex3f(xojo + 2.5*((float)m_iSalud / (float)m_iSaludMax) - 12.1, yojo + 0.673, 0);
		glEnd();
		break;
	}
	case 2:
	{
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		cara.setSize(2.95, 2.95);
		cara.setPos(xojo - 15.55, yojo - 8.99);
		cara.draw();
		glPopMatrix();

		glLineWidth(9.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(xojo - 12.1, yojo - 6.59, 0.0);
		glVertex3f(xojo + 2.5*((float)m_iSalud / (float)m_iSaludMax) - 12.1, yojo - 6.59, 0);
		glEnd();
		break;
	}
	case 3:
	{
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		cara.setSize(2.95, 2.95);
		cara.setPos(xojo + 11.7, yojo + 6.03);
		cara.draw();
		glPopMatrix();

		glLineWidth(9.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(xojo + 12.1, yojo + 8.35, 0.0);
		glVertex3f(xojo - 2.5*((float)m_iSalud / (float)m_iSaludMax) + 12.1, yojo + 8.35, 0);
		glEnd();
		break;
	}
	case 4:
	{
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		cara.setSize(2.95, 2.95);
		cara.setPos(xojo + 11.56, yojo - 1.6);
		cara.draw();
		glPopMatrix();

		glLineWidth(9.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(xojo + 12.1, yojo + 0.6, 0.0);
		glVertex3f(xojo - 2.5*((float)m_iSalud / (float)m_iSaludMax) + 12.1, yojo + 0.6, 0);
		glEnd();
		break;
	}
	case 5:
	{
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		cara.setSize(2.95, 2.95);
		cara.setPos(xojo + 11.55, yojo - 8.99);
		cara.draw();
		glPopMatrix();

		glLineWidth(9.5);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(xojo + 12.1, yojo - 6.56, 0.0);
		glVertex3f(xojo - 2.5*((float)m_iSalud / (float)m_iSaludMax) + 12.1, yojo - 6.56, 0);
		glEnd();
		break;
	}
	}
}

void CPersonaje::ataque_fis(CPersonaje &p) {
	float danio;
	if (sqrt(pow(m_Pos.x - p.getPos().x, 2) + pow(m_Pos.y - p.getPos().y, 2))<4) {
		danio = m_iAtq_fis*(1 - p.m_iDef_fis);
		p.m_iSalud = p.m_iSalud - danio;
		if (p.m_iSalud <= 0) {
			p.m_iSalud = 0;
			p.m_bDisp = 0;
		}
	}
}


CPersonaje::CPersonaje(char* text, char* careto) :
	textura(text, 3, 4, 50, false, 0, 0, 0, 0, 1),
	cara(careto)
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
