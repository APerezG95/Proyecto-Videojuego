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
	int m_iDolor;		//da�o recibido antes de la reducci�n por los stats de defensa
	enum m_eBonus{};	//Bonuses por definir
	int m_iVel;			//numero de movimientos por turno
	int m_iBando;		//aliados=1 enemigos=0                       
	int m_iNivel;
	CPosicion m_Pos;
	int m_iAguante;		//aguante es equivalente al man�
	bool m_bDisp;		//disponibilidad. muerto=0 vivo=1

public:
	CPersonaje(); //Requiere inicializaci�n expl�cita en funci�n del tipo
	int Atacar(int consumo=0, bool tipoda�o=0, int proporcion=1);	//Tipoda�o 0 para f�sico y 1 para habilidad. Proporci�n es el da�o de la habilidad
	int Defender(int dmg, bool tipoda�o=0);
	void Actualizar();
	bool Moverse(CPosicion input);

};