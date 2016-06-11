#include "CEmpollon.h"

bool CEmpollon::ataque_esp(CPersonaje &p, int consumo, bool tipodaño, int daño_base)
{
	float danio;
	if (tipodaño == 0) {					//Buffa al aliado
		if (m_iAguante < consumo) return 0;
		setm_iAtq_hab(getm_iAtq_hab()+daño_base);
		setm_iAtq_fis(getm_iAtq_fis()+daño_base);
		m_iAguante -= consumo;
		return 1;
	}
	else                                       //daño fisico
	{
		if (m_iAguante < consumo) return 0;
		danio = daño_base*(1 - getm_iDef_fis());
		setm_iSalud(getm_iSalud()-danio);
		if (getm_iSalud() <= 0) {
			setm_iSalud(0);
			setm_bDisp(false);
		}
		m_iAguante -= consumo;
		return 1;
	}
}

void CEmpollon::Inicializa()
{
	m_bObjOn = false;
	m_iAtq_fis = 40;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 300;		//Escala sobre 1000
	m_iDef_fis = 0.3f;
	m_iDef_hab = 0.3f;
	m_iVel = 4;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CEmpollon::CEmpollon()
{
	CEmpollon::Inicializa();
}

CEmpollon::~CEmpollon()
{
}
