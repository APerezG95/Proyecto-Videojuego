/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 22/04/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#include "CMapa.h"


CMapa::CMapa(int sizex, int sizey) //En principio inicializamos todas las casillas a NADA
	:m_iSizex(sizex),
	m_iSizey(sizey)
{
	m_eBoard = new m_eEnte*[sizey];		//Ojo puede estar mal esto

	for (int i = 0; i<sizey; i++) 
	{
		m_eBoard[i] = new m_eEnte[sizex];
	}

	for (int i = 0; i<sizex; i++) 
	{
		for (int j = 0; j<sizey; j++) 
		{
			m_eBoard[i][j] = NADA;
		}
	}
}

CMapa::~CMapa()
{
	for (int i = 0; i<m_iSizey; i++) {
		delete[] m_eBoard[i];
	}
	delete[] m_eBoard;
}

CMapa::m_eEnte CMapa::ComprobarContenido(int x, int y) {
	return m_eBoard[x][y];
}

void CMapa::ActualizarMapa(int x, int y, CMapa::m_eEnte estado){
	
	m_eBoard[x][y] = estado;

}