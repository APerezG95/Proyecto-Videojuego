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

#include "CMapa.h"
#include "CNada.h"
#include "CInaccesible.h"
#include "CBasket.h"
#include "CCordilleras.h"
#include "CDestruye.h"
#include "CEmpollon.h"
#include "CEnemigo.h"
#include "CEtsidiante.h"
#include "CHippie.h"
#include "CJefe.h"
#include "CPasota.h"
#include "CTuno.h"
#include "CVoley.h"
#include <cmath>


CMapa::CMapa()	 //Construcci�n
{

}

CMapa::~CMapa()
{
	for (int i = 0; i < m_iSizey; i++) 
	{
		delete[] m_Board[i];
	}
	delete[] m_Board;
}

CEnte* CMapa::ComprobarContenido(int x, int y) 
{
	return m_Board[x][y];
}

bool CMapa::MoverPersonaje(CPersonaje * p, CPosicion nuevaPos)
{

	int mov_max_x = abs((nuevaPos.x) - ((p->getPos()).x));	//movimiento m�ximo que puede desarrollar
	int mov_max_y = abs((nuevaPos.y) - ((p->getPos()).y));	//el personaje en relativas
	//Se usa la ecuaci�n de un c�rculo para definir el �rea m�xima de movimiento
	//De este modo el personaje puede moverse su velocidad como combinaci�n de las dos coordenadas
	if (mov_max_x + mov_max_y > (p->getVel())) return false;	//No se puede llegar tan lejos

	//Observamos lo que hay en la nueva posici�n y actuamos en consecuencia
	if ((m_Board[nuevaPos.x][nuevaPos.y]->m_Type) == CEnte::NADA)
	{
		//Intercambiamos posiciones de ambos objetos
		CEnte* aux=m_Board[nuevaPos.x][nuevaPos.y];
		m_Board[nuevaPos.x][nuevaPos.y] = p;
		m_Board[(p->getPos()).x][(p->getPos()).y] = aux;
		p->setPos(nuevaPos);
		return true;
	}
	if ((m_Board[nuevaPos.x][nuevaPos.y]->m_Type) == CEnte::INACCESIBLE)
		return false;
	if ((m_Board[nuevaPos.x][nuevaPos.y]->m_Type) == CEnte::PERSONAJE)
		return false;
	return false;
}


bool CMapa::inicializaMapa(int** input)
{
	/*Se trata de un decodificador para matrices de enteros. Se utiliza para conseguir una construcci�n
	generalizada de mapas a partir de una matriz, de modo que la leyenda de n�meros es la siguiente:
	0	->		Inaccesible
	1	->		Nada (accesible pero vac�o)
	2	->		Basket
	3	->		Cordilleras
	4	->		Destruye
	5	->		Empoll�n
	6	->		Enemigo
	7	->		Etsidiante
	8	->		Hippie
	9	->		Jefe
	10	->		Pasota
	11	->		Tuno
	12	->		Voley
	Adem�s, se fuerza el casteo din�mico de los punteros para poder meterlos como CEnte en la matriz
	del mapa, pero se conservan como clases polim�rficas.*/

	for (int i = 0; i < m_iSizex; i++)	//Por comprobar
		for (int j = 0; j < m_iSizey; j++)
		{
			switch (input[i][j])
			{
			case 0:
				//m_Board[i][j] = new CInaccesible;
				break;
			case 1:
				//m_Board[i][j] = new CNada;
				break;
			case 2:
				m_Board[i][j] = new CBasket;
				break;
			case 3:
				m_Board[i][j] = new CCordilleras;
				break;
			case 4:
				m_Board[i][j] = new CDestruye;
				break;
			case 5:
				m_Board[i][j] = new CEmpollon;
				break;
			case 6:
			//	m_Board[i][j] = new CEnemigo;
				break;
			case 7:
				m_Board[i][j] = new CEtsidiante;
				break;
			case 8:
				m_Board[i][j] = new CHippie;
				break;
			case 9:
			//	m_Board[i][j] = new CJefe;
				break;
			case 10:
				m_Board[i][j] = new CPasota;
				break;
			case 11:
				m_Board[i][j] = new CTuno;
				break;
			case 12:
				m_Board[i][j] = new CVoley;
				break;

			}
		}
	return true;
}