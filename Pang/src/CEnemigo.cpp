#include <stdlib.h>
#include "CEnemigo.h"
#include "CMapa.h"
#include "glut.h"
#include "ETSIDI.h"

CEnemigo::~CEnemigo()
{
}

CEnemigo::CEnemigo(char* text, char* careto) :
	CPersonaje(text, careto)
{
	Inicializa();
}


void CEnemigo::Inicializa()
{
	m_iAtq_fis = 25;
	m_iAtq_hab = 25;
	m_iSaludMax = m_iSalud = 1000;
	m_iDef_fis = 0, 4;
	m_iDef_hab = 0, 4;
	m_iVel = 3;				//constante en todos los enemigos
	m_bBando = false;
	m_iAguante = m_iAguanteMax = 200;
	m_bDisp = true;
}


