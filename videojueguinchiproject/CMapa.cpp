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

#include "CMapa.h"


CMapa::CMapa(int sizex, int sizey):		 //En principio inicializamos todas las casillas a NADA
	m_iSizex(sizex),
	m_iSizey(sizey)
{
	m_Board = new CEnte*[sizey];		 //Ojo puede estar mal esto

	for (int i = 0; i<sizey; i++) 
	{
		m_Board[i] = new CEnte[sizex];
	}

	for (int i = 0; i<sizex; i++) 
	{
		for (int j = 0; j<sizey; j++) 
		{
			m_Board[i][j].m_Type = CEnte::NADA;	 
		}
	}
}

CMapa::~CMapa()
{
	for (int i = 0; i < m_iSizey; i++) 
	{
		delete[] m_Board[i];
	}
	delete[] m_Board;
}

CEnte CMapa::ComprobarContenido(int x, int y) 
{
	return m_Board[x][y];
}

void CMapa::ActualizarMapa(int x, int y, CEnte::m_eTipo estado)
{
	m_Board[x][y].m_Type = estado;
}