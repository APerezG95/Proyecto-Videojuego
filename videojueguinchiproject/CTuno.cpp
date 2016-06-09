#include "CTuno.h"


void CTuno::Inicializa()
{
	m_bObjOn = false;
	m_iAtq_fis = 5;					//Escala sobre 100
	m_iAtq_hab = 5;
	m_iSaludMax = m_iSalud = 50;		//Escala sobre 1000
	m_iDef_fis = 0.1f;
	m_iDef_hab = 0.1f;
	m_iVel = 20;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 20;	//Escala sobre 500
	m_bDisp = true;
}

CTuno::CTuno()
{
	CTuno::Inicializa;
}


CTuno::~CTuno()
{
}
