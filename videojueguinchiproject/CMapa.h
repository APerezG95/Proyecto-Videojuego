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
#include "CEnte.h"

class CMapa	//Esta clase gestiona la construcci�n y destrucci�n de objetos en el mapa
{
public:
	CMapa();
	~CMapa();
	CEnte* ComprobarContenido(int x, int y);
	bool MoverPersonaje(CPersonaje * p, CPosicion nuevaPos);
	bool inicializaMapa(int** input);	//Creaci�n din�mica del mapa a partir de la matriz dise�ada de nivel. Codificaci�n en cpp

private:
	CEnte *** m_Board;		//Definimos la matriz que contiene el mapa
	int m_iSizey, m_iSizex;	//Maximas dimensiones del mapa
	CEnte** m_repuesto;	//Vector que almacena los item recogidos y los que no
	int m_iSizeRep;		//M�xima dimensi�n del repuesto (funci�n del tama�o del mapa)
};