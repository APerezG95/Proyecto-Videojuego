/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Inform�tica             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha �ltima Modificaci�n: 07/05/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#pragma once
#include "CPersonaje.h"
#include "CHippie.h"
#include "ETSIDI.h"

class CMapa	//Esta clase gestiona la construcci�n y destrucci�n de objetos en el mapa
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

	CPosicion pos_prohib[400];
	CPersonaje *m_Board[5];		//Definimos la matriz que contiene el mapa

private:
	
	float x_ojo, y_ojo, z_ojo;
	ETSIDI::Sprite hud;
	ETSIDI::Sprite fondo;
};