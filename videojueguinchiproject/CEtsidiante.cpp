#include "CEtsidiante.h"


void CEtsidiante::Inicializa()
{
	m_bObjOn = false;
	m_iAtq_fis = 20;					//Escala sobre 100
	m_iAtq_hab = 20;
	m_iSaludMax = m_iSalud = 600;		//Escala sobre 1000
	m_iDef_fis = 0.5f;
	m_iDef_hab = 0.5f;
	m_iVel = 4;							//Escala sobre 20
	m_iBando = true;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 120;	//Escala sobre 500
	m_bDisp = true;
}

CEtsidiante::CEtsidiante()
{
	CEtsidiante::Inicializa();
}


CEtsidiante::~CEtsidiante()
{
}
