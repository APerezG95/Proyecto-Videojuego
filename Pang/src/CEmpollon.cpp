#include <stdlib.h>
#include "CEmpollon.h"
#include "glut.h"
#include "ETSIDI.h"


bool CEmpollon::ataque_esp(CPersonaje &p, int consumo, bool tipodano, int dano_base)
{
	float danio;
	if (tipodano == 0) {					//Buffa al aliado
		if (m_iAguante < consumo) return 0;
		p.setm_iAtq_hab(p.getm_iAtq_hab()+dano_base);
		p.setm_iAtq_fis(p.getm_iAtq_fis()+dano_base);
		m_iAguante -= consumo;
		return 1;
	}
	else                                       //daño fisico
	{
		if (m_iAguante < consumo) return 0;
		danio = dano_base*(1 - p.getm_iDef_fis());
		p.setm_iSalud(p.getm_iSalud()-danio);
		if (p.getm_iSalud() <= 0) {
			p.setm_iSalud(0);
			p.setm_bDisp(false);
		}
		m_iAguante -= consumo;
		return 1;
	}
}

void CEmpollon::Inicializa()
{
	m_iAtq_fis = 40;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 300;		//Escala sobre 1000
	m_iDef_fis = 0.3f;
	m_iDef_hab = 0.3f;
	m_iVel = 4;							//Escala sobre 20
	m_bBando = true;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CEmpollon::CEmpollon(char* text, char* careto) :
	CPersonaje(text, careto)
{
	CEmpollon::Inicializa();
}

CEmpollon::~CEmpollon()
{
}
