/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 07/05/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#pragma once
#include "CPersonaje.h"
#include "CHippie.h"
#include "ETSIDI.h"

class CMapa	//Esta clase gestiona la construcción y destrucción de objetos en el mapa
{
public:

	CMapa();
	~CMapa();
	void MoverPersonaje(unsigned char key);
	void setPersonajeActivo(int t) { PersonajeActivo = t; }
	void dibuja();
	void tecla(unsigned char key);
	int PersonajeActivo;
	bool turno;
	bool CompruebaPos(CPosicion a);
	void setPosAntigua() { posAntigua = m_Board[PersonajeActivo]->getPos(); }

	CPosicion pos_prohib[160];
	CPersonaje *m_Board[5];		//Definimos la matriz que contiene el mapa
	CPosicion posAntigua;
private:
	
	float x_ojo, y_ojo, z_ojo;
	ETSIDI::Sprite hud;
};