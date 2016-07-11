#include <stdlib.h>
#include "CCordilleras.h"
#include "glut.h"
#include "ETSIDI.h"


void CCordilleras::Inicializa()
{
	m_iAtq_fis = 20;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 1000;		//Escala sobre 1000
	m_iDef_fis = 0.7f;
	m_iDef_hab = 0.7f;
	m_iVel = 1;							//Escala sobre 20
	m_iBando = true;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CCordilleras::CCordilleras(char* text, char* careto) :
	CPersonaje(text, careto)
{
	CCordilleras::Inicializa();
}


CCordilleras::~CCordilleras()
{
}
