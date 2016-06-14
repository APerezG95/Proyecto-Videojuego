#include <stdlib.h>
#include "CBasket.h"
#include "glut.h"
#include "ETSIDI.h"

void CBasket::dibuja(int i, int j) {
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1); glVertex3f(-10, 0, -0.1);

	glTexCoord2d(1, 1); glVertex3f(10, 0, -0.1);

	glTexCoord2d(1, 0); glVertex3f(10, 15, -0.1);

	glTexCoord2d(0, 0); glVertex3f(-10, 15, -0.1);

	glEnd();

	glEnable(GL_LIGHTING);

	glDisable(GL_TEXTURE_2D);
}

void CBasket::Inicializa()
{
	m_iAtq_fis = 25;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 750;		//Escala sobre 1000
	m_iDef_fis = 0.5f;
	m_iDef_hab = 0.5f;
	m_iVel = 4;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CBasket::CBasket()
{
	CBasket::Inicializa();
	
}


CBasket::~CBasket()
{
}
