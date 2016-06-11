#include "CHippie.h"

bool CHippie::ataque_esp(CPersonaje &p, int consumo, bool tipodaño, int daño_base)
{
	float danio;
	if (tipodaño == 0) {					//Cura al aliado
		if (m_iAguante < consumo) return 0;
		p.m_iSalud = p.m_iSalud + daño_base;
		if (p.m_iSalud >= p.m_iSaludMax) {
			p.m_iSalud = p.m_iSaludMax;
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

void CHippie::Inicializa()
{
	m_bObjOn = false;
	m_iAtq_fis = 10;					//Escala sobre 100
	m_iAtq_hab = 40;
	m_iSaludMax = m_iSalud = 400;		//Escala sobre 1000
	m_iDef_fis = 0.4f;
	m_iDef_hab = 0.4f;
	m_iVel = 3;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 200;	//Escala sobre 500
	m_bDisp = true;
}


CHippie::CHippie()
{
	CHippie::Inicializa();
}


CHippie::~CHippie()
{
}
