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
#include "CNada.h"
#include "CInaccesible.h"
#include "CBasket.h"
#include "CCordilleras.h"
#include "CDestruye.h"
#include "CEmpollon.h"
#include "CEnemigo.h"
#include "CEtsidiante.h"
#include "CHippie.h"
#include "CPasota.h"
#include "CTuno.h"
#include "CVoley.h"
#include <cmath>


void CMapa::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)	

	//Impresión del HUD
	hud.setSize(30, 25);
	hud.setPos(x_ojo-15.55, y_ojo-11.4);
	hud.draw();


	//animación
	m_Board[10][10]->setPos(m_Board[10][10]->getPos());
	m_Board[10][10]->dibuja();
	(dynamic_cast <CHippie*>(m_Board[10][10]))->textura.setState(0, false);

}

void CMapa::tecla(unsigned char key)
{
	switch (key)
	{
	case 'i':
		y_ojo += 0.1f;
		break;
	case 'j':
		x_ojo -= 0.1f;
		break;
	case 'k':
		y_ojo -= 0.1f;
		break;
	case 'l':
		x_ojo += 0.1f;
		break;
	case 'd':
	{
		CPosicion aux = m_Board[10][10]->getPos();
		aux.x += 1;
		this->MoverPersonaje(m_Board[10][10], aux);
		break;
	}
	case 'a':
	{
		CPosicion aux = m_Board[10][10]->getPos();
		aux.x -= 1;
		m_Board[10][10]->setPos(aux);
		break;
	}
	}
}

CMapa::CMapa():hud("imagenes/hud.png")
{
	x_ojo = 14;	y_ojo = 10;	z_ojo = 30;
	m_Board[11][10] = new CNada;
	m_Board[10][10] = new CHippie;
}

CMapa::~CMapa()
{
	delete m_Board[11][10];
	delete m_Board[10][10];
}

CEnte* CMapa::ComprobarContenido(int x, int y) 
{
	return m_Board[x][y];
}

bool CMapa::MoverPersonaje(CPersonaje * p, CPosicion nuevaPos)
{

	int mov_max_x = abs((nuevaPos.x) - ((p->getPos()).x));	//movimiento máximo que puede desarrollar
	int mov_max_y = abs((nuevaPos.y) - ((p->getPos()).y));	//el personaje en relativas
	//Se usa la ecuación de un círculo para definir el área máxima de movimiento
	//De este modo el personaje puede moverse su velocidad como combinación de las dos coordenadas
	if (mov_max_x + mov_max_y > (p->getVel())) return false;	//No se puede llegar tan lejos

	//Observamos lo que hay en la nueva posición y actuamos en consecuencia
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
