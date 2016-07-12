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
#include "ETSIDI.h"

class CPersonaje
{
protected:
	int m_iAtq_fis;		//Ataque directo o físico. Estadística base del personaje
	int m_iAtq_hab;		//Ataque de habilidad
	int m_iSaludMax;	//Puntos de daño total que es capaz de soportar
	int m_iSalud;		//Puntos de salud actuales
	float m_iDef_fis;	//Valor porcentual de reducción de daño físico recibido
	float m_iDef_hab;	//Valor porcentual de reducción de daño de habilidad recibido
	int m_iVel;			//Número de casillas máximo que es capaz de moverse el personaje
	bool m_bBando;		//aliados=1 enemigos=0                       
	int m_iNum;			//Número que el personaje ocupa en la partida (representación de su cara en HUD)
	int m_iAguante;		//Puntos de aguante actuales
	int m_iAguanteMax;	//Puntos máximos de aguante, permiten lanzar ataques de habilidad
	bool m_bDisp;		//disponibilidad. muerto=0 vivo=1
	CPosicion m_Pos;	//Posición
	CPosicion posAntigua;
	CPosicion primeraPos;
	ETSIDI::SpriteSequence textura;
	ETSIDI::Sprite cara;
	friend class CMapa;

public:
	CPosicion getPos() { return m_Pos; }
	virtual void setPos(CPosicion pos) { m_Pos = pos; }
	virtual void Inicializa() {;};	//Requiere inicialización explícita en función del tipo
	void dibuja(float xojo, float yojo);
	void actualizaPosfinal() { primeraPos = getPos(); }
	void actualizaPos() { posAntigua = getPos(); }
	CPersonaje(char* text, char* careto);
	void ataque_fis(CPersonaje &p); //si p muere, actualiza su estado a no disponible
	bool ataque_hab(CPersonaje &p); //si p muere, actualiza su estado a no disponible. retorna 0 si no habia aguante suficiente
	virtual bool ataque_esp(CPersonaje &p, int consumo = 0, bool tipodano = 0, int dano_base = 1);	//Tipodaño 0 para físico y 1 para habilidad. daño_base es el daño de la habilidad. Consumo es para el gasto de Aguante.
	int getm_iAtq_fis() { return m_iAtq_fis; }
	int getm_iAtq_hab() { return m_iAtq_hab; }
	int getm_iSalud() { return m_iSalud; }
	int getm_iSaludMax() { return m_iSaludMax; }
	float getm_iDef_fis() { return m_iDef_fis; }
	float getm_iDef_hab() { return m_iDef_hab; }
	int getm_iAguante() { return m_iAguante; }
	int getm_iAguanteMax() { return m_iAguanteMax; }
	void setm_iAtq_fis(int a) { m_iAtq_fis = a; }
	void setm_iAtq_hab(int a) { m_iAtq_hab = a; }
	void setm_iSalud(int a) { m_iSalud = a; }
	void setm_iDef_fis(float a) { m_iDef_fis = a; }
	void setm_iDef_hab(float a) { m_iDef_hab = a; }
	void setm_iAguante(int a) { m_iAguante = a; }
	void setm_bDisp(bool a) { m_bDisp = a; }
	bool getm_bBando() { return m_bBando; }
	int getVel() {return m_iVel;};
	int orientacion();
};
