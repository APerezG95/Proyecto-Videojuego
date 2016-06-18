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
#include "CEnte.h"
#include "CNada.h"
#include "CInaccesible.h"
#include "CHippie.h"
#include "ETSIDI.h"

class CMapa	//Esta clase gestiona la construcción y destrucción de objetos en el mapa
{
public:

	CMapa();
	~CMapa();
	CEnte* ComprobarContenido(int x, int y);
	bool MoverPersonaje(CPersonaje* p, CPosicion nuevaPos);
	void dibuja();
	void tecla(unsigned char key);

	CPersonaje * m_Board[20][20];		//Definimos la matriz que contiene el mapa
private:
	float x_ojo, y_ojo, z_ojo;
	ETSIDI::Sprite hud;
};