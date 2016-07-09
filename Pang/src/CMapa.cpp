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

	//Dibujado de personajes
	for (int i = 0; i < 5; i++)
	{
		m_Board[i]->dibuja();
	}

	//Impresión del mapa
	fondo.setSize(20, 20);
	fondo.setPos(0.5,0.5);
	fondo.draw();

	
}

void CMapa::tecla(unsigned char key)
{
	m_Board[PersonajeActivo]->actualizaPos();
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
		MoverPersonaje('d');
		break;
	}
	case 'a':
	{
		MoverPersonaje('a');
		break;
	}
	case 'w':
	{
		MoverPersonaje('w');
		break;
	}
	case 's':
	{
		MoverPersonaje('s');
		break;
	}
	case ' ':
	{
		if (!CompruebaPos(m_Board[PersonajeActivo]->primeraPos))
		{
			m_Board[PersonajeActivo]->actualizaPosfinal();
		}
		else
		{
			if (PersonajeActivo < 5)
				PersonajeActivo++;
			else
			{
				!turno;
				PersonajeActivo = 0;
			}
		}
	}

	}
}

bool CMapa::CompruebaPos(CPosicion a)
{
	int mov_max_x = abs((a.x) - ((m_Board[PersonajeActivo]->getPos()).x));	//movimiento máximo que puede desarrollar
	int mov_max_y = abs((a.y) - ((m_Board[PersonajeActivo]->getPos()).y));	//el personaje en relativas
																					//Se usa la ecuación de un círculo para definir el área máxima de movimiento
																					//De este modo el personaje puede moverse su velocidad como combinación de las dos coordenadas
	if (mov_max_x + mov_max_y > (m_Board[PersonajeActivo]->getVel())) return false;	//No se puede llegar tan lejos
	else return true;
}

CMapa::CMapa() :
	hud("imagenes/hud.png"),
	fondo("imagenes/mapita.png")
{
	x_ojo = 14;	y_ojo = 10;	z_ojo = 30;
	m_Board[0] = new CHippie;
	m_Board[1] = new CHippie;
	m_Board[2] = new CHippie;
	m_Board[3] = new CHippie;
	m_Board[4] = new CHippie;
	turno = true;
	setPersonajeActivo(0);
	//Definimos el mapa (posible lectura desde fichero)
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				pos_prohib[j] = CPosicion(i, j);
	}
}

CMapa::~CMapa()
{
	delete m_Board[0];
	delete m_Board[1];
	delete m_Board[2];
	delete m_Board[3];
	delete m_Board[4];
}



void CMapa::MoverPersonaje(unsigned char key)
{
	switch(key)
	{
	case 'w':
	{
		CPosicion aux = m_Board[PersonajeActivo]->getPos();
		aux.y += 1;
		bool flag = true;
		for (int i = 0; i < 5; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}
		if (flag)
		{
			m_Board[PersonajeActivo]->setPos(aux);
		}
		break;
	}
	case 's':
	{
		CPosicion aux = m_Board[PersonajeActivo]->getPos();
		aux.y -= 1;
		bool flag = true;
		for (int i = 0; i < 5; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}
		if (flag)
		{
			m_Board[PersonajeActivo]->setPos(aux);
		}
		break;
	}
	case 'a':
	{
		CPosicion aux = m_Board[PersonajeActivo]->getPos();
		aux.x -= 1;
		bool flag = true;
		for (int i = 0; i < 5; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}
		if (flag)
			m_Board[PersonajeActivo]->setPos(aux);
		break;
	}
	case 'd':
	{
		CPosicion aux = m_Board[PersonajeActivo]->getPos();
		aux.x += 1;
		bool flag = true;
		for (int i = 0; i < 5; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}
		if (flag)
			m_Board[PersonajeActivo]->setPos(aux);
		break;
	}
	}
	
}

