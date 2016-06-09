#include "CEnemigo.h"




CEnemigo::CEnemigo(int a, int b, int c, float d, float e, int f, int g)
{
	m_bObjOn = false;
	m_iAtq_fis = a;
	m_iAtq_hab = b;
	m_iSaludMax = m_iSalud = c;
	m_iDef_fis = d;
	m_iDef_hab = e;
	m_iVel = 3;				//constante en todos los enemigos
	m_iBando = false;
	m_iNivel = f;
	m_iAguante = m_iAguanteMax = g;
	m_bDisp = true;
}


CEnemigo::~CEnemigo()
{
}
