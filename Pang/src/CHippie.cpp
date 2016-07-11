#include <stdlib.h>
#include "CHippie.h"
#include "glut.h"
#include "ETSIDI.h"


bool CHippie::ataque_esp(CPersonaje &p, int consumo, bool tipodano, int dano_base)
{
	float danio;
	if (tipodano == 0) {					//Cura al aliado
		if (m_iAguante < consumo) return 0;
		p.setm_iSalud(p.getm_iSalud()+dano_base);
		if (p.getm_iSalud() >= p.getm_iSaludMax()) {
			p.setm_iSalud(p.getm_iSalud());
		}
		m_iAguante -= consumo;
		return 1;
	}
	else                                       //daño habilidad
	{
		danio = dano_base*(1 - p.getm_iDef_hab());
		p.setm_iSalud(p.getm_iSalud()-danio);
		if (p.getm_iSalud() <= 0) {
			p.setm_iSalud(0);
			p.setm_bDisp(false);
		}
		m_iAguante -= consumo;
		return 1;
	}
}

void CHippie::Inicializa()
{
	m_iAtq_fis = 10;					//Escala sobre 100
	m_iAtq_hab = 40;
	m_iSaludMax = m_iSalud = 400;		//Escala sobre 1000
	m_iDef_fis = 0.4f;
	m_iDef_hab = 0.4f;
	m_iVel = 3;							//Escala sobre 20
	m_iBando = true;
	m_iAguante = m_iAguanteMax = 200;	//Escala sobre 500
	m_bDisp = true;
}


CHippie::CHippie(char* text, char* careto) :
	CPersonaje(text, careto)
{
	CHippie::Inicializa();
}


CHippie::~CHippie()
{
}
