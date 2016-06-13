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

class CEnte
{
public:
	enum  m_eTipo { PERSONAJE, ITEM, NADA, INACCESIBLE };
	CEnte(m_eTipo t) :m_Type(t) {};	//Hay que rellenar el constructor
	~CEnte();
	m_eTipo m_Type;

	CPosicion getPos(){ return m_Pos; }
	void setPos(CPosicion pos){ m_Pos = pos; }
	virtual void foo() = 0;
	

protected:
	CPosicion m_Pos;
	
};

