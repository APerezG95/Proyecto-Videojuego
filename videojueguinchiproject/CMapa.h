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

class CMapa	//Esta clase gestiona la construcción y destrucción de objetos en el mapa
{
public:
	CMapa();
	~CMapa();
	CEnte* ComprobarContenido(int x, int y);
	bool MoverPersonaje(CPersonaje * p, CPosicion nuevaPos);
	bool inicializaMapa(int** input);	//Creación dinámica del mapa a partir de la matriz diseñada de nivel. Codificación en cpp

private:
	CEnte *** m_Board;		//Definimos la matriz que contiene el mapa
	int m_iSizey, m_iSizex;	//Maximas dimensiones del mapa
	CEnte** m_repuesto;	//Vector que almacena los item recogidos y los que no
	int m_iSizeRep;		//Máxima dimensión del repuesto (función del tamaño del mapa)
};