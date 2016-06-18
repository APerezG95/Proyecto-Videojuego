#include <stdlib.h>
#include "CCordilleras.h"
#include "glut.h"
#include "ETSIDI.h"

void CCordilleras::dibuja()
{
	glPushMatrix();
	glTranslatef((this->getPos()).x, (this->getPos()).y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	//gestion de direccion y animacion
	//if(velocidad.x>0.01)sprite.flip(false,false);
	//if(velocidad.x<-0.01)sprite.flip(true,false);
	//if((velocidad.x<0.01)&&(velocidad.x>-0.01))
	//	sprite.setState(0);
	//else if (sprite.getState()==0)
	//	sprite.setState(1,false);
	textura.draw();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Cordilleras", -8, -1);

	glPopMatrix();
}


void CCordilleras::Inicializa()
{
	m_iAtq_fis = 20;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 1000;		//Escala sobre 1000
	m_iDef_fis = 0.7f;
	m_iDef_hab = 0.7f;
	m_iVel = 1;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CCordilleras::CCordilleras():
	textura("imagenes/Cordilleras.png",3,4,50,false,-7.8,0,0,0,1)
{
	textura.setCenter(0, 0);
	textura.setSize(2, 2);
	CCordilleras::Inicializa();
}


CCordilleras::~CCordilleras()
{
}
