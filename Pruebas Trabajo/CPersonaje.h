/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 18/05/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#pragma once
#include "CPosicion.h"
#include "CItem.h"
#include "CMapa.h"
#include "CEnte.h"

class CPersonaje: public CEnte
{
protected:
	CItem m_Obj;		//Variable para almacenar las características del objeto
	bool m_bObjDisp;	//Variable para saber si tengo un objeto o no. 0 para tengo objeto, 1 para no tengo objeto
	bool m_bObjOn;		//Variable de comprobación. 0 para buff no aplicado, 1 para buff aplicado
	int m_iAtq_fis;		//Ataque directo o físico. Estadística base del personaje
	int m_iAtq_hab;		//Ataque de habilidad
	int m_iSaludMax;	//Puntos de daño total que es capaz de soportar
	int m_iSalud;		//Puntos de salud actuales
	float m_iDef_fis;	//Valor porcentual de reducción de daño físico recibido
	float m_iDef_hab;	//Valor porcentual de reducción de daño de habilidad recibido
	int m_iVel;			//Número de casillas máximo que es capaz de moverse el personaje
	bool m_iBando;		//aliados=1 enemigos=0                       
	int m_iNivel;		//Número que representa la cantidad de experiencia recibida y determina sus atributos
	int m_iAguante;		//Puntos de aguante actuales
	int m_iAguanteMax;	//Puntos máximos de aguante, permiten lanzar ataques de habilidad
	bool m_bDisp;		//disponibilidad. muerto=0 vivo=1

public:
	virtual void Inicializa()=0;								//Requiere inicialización explícita en función del tipo
	virtual int Atacar(int consumo=0, bool tipodaño=0, int daño_base=1);	//Tipodaño 0 para físico y 1 para habilidad. daño_base es el daño de la habilidad. Consumo es para el gasto de Aguante.
	virtual int Defender(int dmg, bool tipodaño=0);
	void Actualizar();
	bool Moverse(CPosicion input, CMapa* map);
	virtual void Añadir_Buff(CBonus bonus);
	virtual void Recoger_Objeto(CEnte* item);
	CPersonaje();

};
