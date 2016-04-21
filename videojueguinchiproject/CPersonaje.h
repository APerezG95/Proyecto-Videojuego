#pragma once
#include "CPosicion.h"

class CPersonaje
{
private:
	enum m_eTipo{BASKET,VOLEY,HIPPIE,DESTRUYE,TUNO,EMPOLLON,PASOTA,CORDILLERAS,ETSIDIANTE,PROFSTANDARD,BOSS,OTROS};
	int m_iAtq_fis;
	int m_iAtq_hab;
	int m_iSalud;
	int m_iDef_fis;
	int m_iDef_hab;
	int m_iDolor;		//daño recibido antes de la reducción por los stats de defensa
	enum m_eBonus{};	//Bonuses por definir
	int m_iVel;			//numero de movimientos por turno
	int m_iBando;		//aliados=1 enemigos=0                       
	int m_iNivel;
	CPosicion m_Pos;
	int m_iAguante;		//aguante es equivalente al maná
	bool m_bDisp;		//disponibilidad. muerto=0 vivo=1

public:
	CPersonaje(); //Requiere inicialización explícita en función del tipo
	int Atacar(int consumo=0, bool tipodaño=0, int proporcion=1);	//Tipodaño 0 para físico y 1 para habilidad. Proporción es el daño de la habilidad
	int Defender(int dmg, bool tipodaño=0);
	void Actualizar();
	bool Moverse(CPosicion input);

};