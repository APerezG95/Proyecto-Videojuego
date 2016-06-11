#include "CDestruye.h"

bool CDestruye::ataque_esp(CPersonaje &p, int consumo, bool tipodaño, int daño_base)
{
	float danio;
	if (tipodaño == 0) {					//Debilita al enemigo
		if (m_iAguante < consumo) return 0;
		setm_iAtq_fis(0.4*getm_iAtq_fis());
		setm_iAtq_hab(0.4*getm_iAtq_hab());
		setm_iDef_fis(0.5*getm_iDef_fis());
		setm_iDef_hab(0.5*getm_iDef_hab());
		m_iAguante -= consumo;
		return 1;
		
	}
	else                                       //daño habilidad
	{
		if (m_iAguante < consumo) return 0;
		danio = daño_base*(1 - getm_iDef_hab());
		setm_iSalud(getm_iSalud()-danio;)
		if (getm_iSalud() <= 0) {
			setm_iSalud(0);
			setm_bDisp(false);
		}
		m_iAguante -= consumo;
		return 1;
	}
}

void CDestruye::Inicializa()
{
	m_bObjOn = false;
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
