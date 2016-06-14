#include <stdlib.h>
#include "CEnemigo.h"
#include "glut.h"
#include "ETSIDI.h"


void CEnemigo::dibuja(int i, int j) {
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

void CEnemigo::Inicializa()
{
}

CEnemigo::CEnemigo(int a, int b, int c, float d, float e, int f, int g)
{
	m_iAtq_fis = a;
	m_iAtq_hab = b;
	m_iSaludMax = m_iSalud = c;
	m_iDef_fis = d;
	m_iDef_hab = e;
	m_iVel = 3;				//constante en todos los enemigos
	m_iBando = false;
	m_iNivel = f;
	m_iAguante = m_iAguanteMax = g;
	m_bDisp = true;
}


CEnemigo::~CEnemigo()
{
}
