#include "CVoley.h"

void CVoley::Inicializa()
{
	m_bObjOn = false;
	m_iAtq_fis = 40;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 750;		//Escala sobre 1000
	m_iDef_fis = 0.3f;
	m_iDef_hab = 0.5f;
	m_iVel = 4;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CVoley::CVoley()
{
	CVoley::Inicializa();
}


CVoley::~CVoley()
{
}
