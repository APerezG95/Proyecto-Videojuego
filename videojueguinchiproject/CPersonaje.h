/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Inform�tica             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha �ltima Modificaci�n: 22/04/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#pragma once
#include "CPosicion.h"
#include "CItem.h"

class CPersonaje
{
protected:
	CItem m_Obj;		//Variable para almacenar las caracter�sticas del objeto
	bool m_bObjOn;		//Variable de comprobaci�n
	int m_iAtq_fis;		//Ataque directo o f�sico. Estad�stica base del personaje
	int m_iAtq_hab;		//Ataque de habilidad
	int m_iSaludMax;	//Puntos de da�o total que es capaz de soportar
	int m_iSalud;		//Puntos de salud actuales
	float m_iDef_fis;	//Valor porcentual de reducci�n de da�o f�sico recibido
	float m_iDef_hab;	//Valor porcentual de reducci�n de da�o de habilidad recibido
	int m_iVel;			//N�mero de casillas m�ximo que es capaz de moverse el personaje
	bool m_iBando;		//aliados=1 enemigos=0                       
	int m_iNivel;		//N�mero que representa la cantidad de experiencia recibida y determina sus atributos
	CPosicion m_Pos;	//Posici�n actual del personaje
	int m_iAguante;		//Puntos de aguante actuales
	int m_iAguanteMax;	//Puntos m�ximos de aguante, permiten lanzar ataques de habilidad
	bool m_bDisp;		//disponibilidad. muerto=0 vivo=1

public:
	virtual void Inicializa(CPersonaje&) {};								//Requiere inicializaci�n expl�cita en funci�n del tipo
	virtual int Atacar(int consumo=0, bool tipoda�o=0, int da�o_base=1);	//Tipoda�o 0 para f�sico y 1 para habilidad. da�o_base es el da�o de la habilidad. Consumo es para el gasto de Aguante.
	virtual int Defender(int dmg, bool tipoda�o=0);
	void Actualizar();
	bool Moverse(CPosicion input);
	void A�adir_Buff();

};