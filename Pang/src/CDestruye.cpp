#include <stdlib.h>
#include "CDestruye.h"
#include "glut.h"
#include "ETSIDI.h"

void CDestruye::dibuja() {
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
	//textura.draw();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Hippie", -10, -1);

	glPopMatrix();
}

bool CDestruye::ataque_esp(CPersonaje &p, int consumo, bool tipodano, int dano_base)
{
	float danio;
	if (tipodano == 0) {					//Debilita al enemigo
		if (m_iAguante < consumo) return 0;
		p.setm_iAtq_fis(0.4*getm_iAtq_fis());
		p.setm_iAtq_hab(0.4*getm_iAtq_hab());
		p.setm_iDef_fis(0.5*getm_iDef_fis());
		p.setm_iDef_hab(0.5*getm_iDef_hab());
		m_iAguante -= consumo;
		return 1;
		
	}
	else                                       //daño habilidad
	{
		if (m_iAguante < consumo) return 0;
		danio = dano_base*(1 - p.getm_iDef_hab());
		p.setm_iSalud(p.getm_iSalud() - danio);
		if (p.getm_iSalud() <= 0) {
			p.setm_iSalud(0);
			p.setm_bDisp(false);
		}
		m_iAguante -= consumo;
		return 1;
	}
}

void CDestruye::Inicializa()
{
	m_iAtq_fis = 10;					//Escala sobre 100
	m_iAtq_hab = 75;
	m_iSaludMax = m_iSalud = 500;		//Escala sobre 1000
	m_iDef_fis = 0.3f;
	m_iDef_hab = 0.3f;
	m_iVel = 4;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 400;	//Escala sobre 500
	m_bDisp = true;
}

CDestruye::CDestruye()
{
	CDestruye::Inicializa();
}

CDestruye::~CDestruye()
{
}
