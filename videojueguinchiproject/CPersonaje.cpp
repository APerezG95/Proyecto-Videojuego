#include "CPersonaje.h"

int CPersonaje::Atacar(int consumo, bool tipodaño, int proporcion)
{
	if (tipodaño == 0)
		return m_iAtq_fis;

	else
	{
		m_iAguante -= consumo;
		return m_iAtq_hab*proporcion;
	}
}

int CPersonaje::Defender(int dmg, bool tipodaño)
{
	if (tipodaño == 0)
		return (dmg-dmg*m_iDef_fis);

	else
		return (dmg - dmg*m_iDef_hab);

}

bool CPersonaje::Moverse(CPosicion input)
{
	int pos_max_x = m_iVel + m_Pos.x;
	int pos_max_y = m_iVel + m_Pos.y;

	if ((pos_max_x < input.x) || (pos_max_y < input.y))	//posible sobrecarga de operador <
		return -1;

	m_Pos = input;
	return 0;


}
