#include <stdlib.h>
#include "CPasota.h"
#include "glut.h"
#include "ETSIDI.h"

void CPasota::Inicializa()
{
	m_iAtq_fis = 25;					//Escala sobre 100
	m_iAtq_hab = 0;
	m_iSaludMax = m_iSalud = 650;		//Escala sobre 1000
	m_iDef_fis = 0.5f;
	m_iDef_hab = 0.5f;
	m_iVel = 8;							//Escala sobre 20
	m_bBando = true;
	m_iAguante = m_iAguanteMax = 100;	//Escala sobre 500
	m_bDisp = true;
}

CPasota::CPasota(char* text, char* careto) :
	CPersonaje(text, careto)
{
	CPasota::Inicializa();
}


CPasota::~CPasota()
{
}
