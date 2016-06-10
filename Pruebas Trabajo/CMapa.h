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
#include "CItem.h"
#include "CEnte.h"

class CMapa
{
public:
	CMapa(int sizex, int sizey);
	~CMapa();
	CEnte ComprobarContenido(int x, int y);
	void ActualizarMapa(int x, int y, CEnte::m_eTipo estado);

private:
	CEnte ** m_Board;		//Definimos la matriz que contiene el mapa
	int m_iSizey, m_iSizex;	//Maximas dimensiones del mapa

};