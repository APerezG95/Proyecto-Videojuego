/*    .----------------------------------------------------------------.   */
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
#include <iostream>

using  namespace std;


void CMapa::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)	




	 //Dibujado de personajes
	for (int i = 0; i < 6; i++)
	{
		m_Board[i]->dibuja(x_ojo, y_ojo);
	}

	//HUD
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	hud.setSize(30, 25);
	hud.setPos(x_ojo - 15.55, y_ojo - 11.4);
	hud.draw();
	glPopMatrix();


	//Impresión del mapa
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	fondo.setSize(20, 20);
	fondo.setPos(-10, 2);
	fondo.draw();
	glPopMatrix();


}

void CMapa::tecla(unsigned char key)
{
	m_Board[PersonajeActivo]->actualizaPos();
	if (m_Board[PersonajeActivo]->m_bDisp) {
		switch (key)
		{
		case '1':
		{
			if (PersonajeActivo < 3 && !turno) {
				m_Board[PersonajeActivo]->ataque_fis(*m_Board[3]);
				PersonajeActivo++;
				turno = true;
			}
			break;
		}
		case '2':
		{
			if (PersonajeActivo < 3 && !turno) {
				m_Board[PersonajeActivo]->ataque_fis(*m_Board[4]);
				PersonajeActivo++;
				turno = true;
			}
			break;
		}
		case '3':
		{
			if (PersonajeActivo < 3 && !turno) {
				m_Board[PersonajeActivo]->ataque_fis(*m_Board[5]);
				PersonajeActivo++;
				turno = true;
			}
			break;
		}
		case '7':
		{
			if (PersonajeActivo > 2 && !turno) {
				m_Board[PersonajeActivo]->ataque_fis(*m_Board[0]);
				PersonajeActivo++;
				turno = true;
			}
			break;
		}
		case '8':
		{
			if (PersonajeActivo > 2 && !turno) {
				m_Board[PersonajeActivo]->ataque_fis(*m_Board[1]);
				PersonajeActivo++;
				turno = true;
			}
			break;
		}
		case '9':
		{
			if (PersonajeActivo > 2 && !turno) {
				m_Board[PersonajeActivo]->ataque_fis(*m_Board[2]);
				PersonajeActivo++;
				turno = true;
			}
			break;
		}
		case 'd':
		{
			if (turno) {
				MoverPersonaje('d');
				break;
			}
		}
		case 'a':
		{
			if (turno) {
				MoverPersonaje('a');
				break;
			}
		}
		case 'w':
		{
			if (turno) {
				MoverPersonaje('w');
				break;
			}
		}
		case 's':
		{
			if (turno) {
				MoverPersonaje('s');
				break;
			}
		}
		case ' ':
		{
			if (CompruebaPos(m_Board[PersonajeActivo]->primeraPos) && turno)
			{
				m_Board[PersonajeActivo]->actualizaPosfinal();
				turno = false;
			}
			break;
		}
		}
	}
	else PersonajeActivo++;

	if (PersonajeActivo == 6)
		PersonajeActivo = 0;

	int flag = 0;

	for (int i = 0; i < 3; i++)
	{
		if (!m_Board[i]->m_bDisp)
			flag++;
	}
	if (flag == 3) m_iVictoria = 2;

	flag = 0;
	for (int i = 3; i < 6; i++)
	{
		if (!m_Board[i]->m_bDisp)
			flag++;
	}
	if (flag == 3) m_iVictoria = 1;

	if (m_iVictoria == 1)
	{
		cout << "Victoria equipo 1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		for (int i = 0; i < 6; i++)
			m_Board[i]->m_bDisp = false;
	}
	if (m_iVictoria == 2)
	{
		cout << "Victoria equipo 2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		for (int i = 0; i < 6; i++)
			m_Board[i]->m_bDisp = false;
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
	m_Board[0] = new CHippie("imagenes/hippie.png", "imagenes/carahippie.png");
	m_Board[1] = new CCordilleras("imagenes/Cordilleras.png", "imagenes/caracordilleras.png");
	m_Board[2] = new CEtsidiante("imagenes/etsidiante.png", "imagenes/caraetsidiante.png");
	m_Board[3] = new CDestruye("imagenes/Destruye.png", "imagenes/caradestruye.png");
	m_Board[4] = new CEnemigo("imagenes/enemigo.png", "imagenes/caraenemigo.png");
	m_Board[5] = new CEmpollon("imagenes/empollonn.png", "imagenes/caraempollon.png");
	m_Board[0]->setPos(CPosicion(2, 5));
	m_Board[0]->primeraPos = m_Board[0]->getPos();
	m_Board[1]->setPos(CPosicion(3, 3));
	m_Board[1]->primeraPos = m_Board[1]->getPos();
	m_Board[2]->setPos(CPosicion(5, 4));
	m_Board[2]->primeraPos = m_Board[2]->getPos();
	m_Board[3]->setPos(CPosicion(16, 16));
	m_Board[3]->primeraPos = m_Board[3]->getPos();
	m_Board[4]->setPos(CPosicion(16, 15));
	m_Board[4]->primeraPos = m_Board[4]->getPos();
	m_Board[5]->setPos(CPosicion(15, 14));
	m_Board[5]->primeraPos = m_Board[5]->getPos();



	m_iVictoria = 0;

	for (int i = 0; i < 6; i++)
		(m_Board[i]->m_iNum) = i;

	turno = true;
	setPersonajeActivo(0);
	{
		pos_prohib[0] = CPosicion(1, 2);
		pos_prohib[1] = CPosicion(1, 3);
		pos_prohib[2] = CPosicion(1, 4);
		pos_prohib[3] = CPosicion(1, 5);
		pos_prohib[4] = CPosicion(1, 8);
		pos_prohib[5] = CPosicion(1, 9);
		pos_prohib[6] = CPosicion(1, 10);
		pos_prohib[7] = CPosicion(1, 11);
		pos_prohib[8] = CPosicion(1, 12);
		pos_prohib[9] = CPosicion(1, 13);
		pos_prohib[10] = CPosicion(1, 15);
		pos_prohib[11] = CPosicion(1, 16);
		pos_prohib[12] = CPosicion(1, 17);
		pos_prohib[13] = CPosicion(2, 2);
		pos_prohib[14] = CPosicion(2, 11);
		pos_prohib[15] = CPosicion(2, 13);
		pos_prohib[16] = CPosicion(2, 18);
		pos_prohib[17] = CPosicion(3, 2);
		pos_prohib[18] = CPosicion(3, 11);
		pos_prohib[19] = CPosicion(3, 13);
		pos_prohib[20] = CPosicion(3, 18);
		pos_prohib[21] = CPosicion(4, 2);
		pos_prohib[22] = CPosicion(4, 11);
		pos_prohib[23] = CPosicion(4, 13);
		pos_prohib[24] = CPosicion(4, 18);
		pos_prohib[25] = CPosicion(5, 2);
		pos_prohib[26] = CPosicion(5, 5);
		pos_prohib[27] = CPosicion(5, 6);
		pos_prohib[28] = CPosicion(5, 7);
		pos_prohib[29] = CPosicion(5, 10);
		pos_prohib[30] = CPosicion(5, 14);
		pos_prohib[31] = CPosicion(5, 15);
		pos_prohib[32] = CPosicion(5, 16);
		pos_prohib[33] = CPosicion(5, 18);
		pos_prohib[34] = CPosicion(6, 2);
		pos_prohib[35] = CPosicion(6, 11);
		pos_prohib[36] = CPosicion(6, 12);
		pos_prohib[37] = CPosicion(6, 13);
		pos_prohib[38] = CPosicion(6, 18);
		pos_prohib[39] = CPosicion(7, 2);
		pos_prohib[40] = CPosicion(7, 18);
		pos_prohib[41] = CPosicion(8, 5);
		pos_prohib[42] = CPosicion(8, 6);
		pos_prohib[43] = CPosicion(8, 7);
		pos_prohib[44] = CPosicion(8, 14);
		pos_prohib[45] = CPosicion(8, 15);
		pos_prohib[46] = CPosicion(8, 16);
		pos_prohib[47] = CPosicion(9, 2);
		pos_prohib[48] = CPosicion(10, 2);
		pos_prohib[49] = CPosicion(10, 18);
		pos_prohib[50] = CPosicion(10, 19);
		pos_prohib[51] = CPosicion(10, 20);
		pos_prohib[52] = CPosicion(7, 19);
		pos_prohib[53] = CPosicion(7, 20);
		pos_prohib[54] = CPosicion(11, 2);
		pos_prohib[55] = CPosicion(11, 5);
		pos_prohib[56] = CPosicion(11, 6);
		pos_prohib[57] = CPosicion(11, 7);
		pos_prohib[58] = CPosicion(11, 14);
		pos_prohib[59] = CPosicion(11, 15);
		pos_prohib[60] = CPosicion(11, 16);
		pos_prohib[61] = CPosicion(11, 18);
		pos_prohib[62] = CPosicion(12, 2);
		pos_prohib[63] = CPosicion(12, 18);
		pos_prohib[64] = CPosicion(13, 2);
		pos_prohib[65] = CPosicion(13, 18);
		pos_prohib[66] = CPosicion(14, 2);
		pos_prohib[67] = CPosicion(14, 5);
		pos_prohib[68] = CPosicion(14, 6);
		pos_prohib[69] = CPosicion(14, 7);
		pos_prohib[70] = CPosicion(14, 10);
		pos_prohib[71] = CPosicion(14, 11);
		pos_prohib[72] = CPosicion(14, 12);
		pos_prohib[73] = CPosicion(14, 14);
		pos_prohib[74] = CPosicion(14, 15);
		pos_prohib[75] = CPosicion(14, 16);
		pos_prohib[76] = CPosicion(14, 18);
		pos_prohib[77] = CPosicion(15, 2);
		pos_prohib[78] = CPosicion(15, 18);
		pos_prohib[79] = CPosicion(16, 2);
		pos_prohib[80] = CPosicion(16, 18);
		pos_prohib[81] = CPosicion(17, 3);
		pos_prohib[82] = CPosicion(17, 18);
		pos_prohib[83] = CPosicion(18, 4);
		pos_prohib[84] = CPosicion(18, 5);
		pos_prohib[85] = CPosicion(18, 6);
		pos_prohib[86] = CPosicion(18, 7);
		pos_prohib[87] = CPosicion(18, 8);
		pos_prohib[88] = CPosicion(18, 13);
		pos_prohib[89] = CPosicion(18, 14);
		pos_prohib[90] = CPosicion(18, 15);
		pos_prohib[91] = CPosicion(18, 16);
		pos_prohib[92] = CPosicion(18, 17);
		pos_prohib[93] = CPosicion(19, 8);
		pos_prohib[94] = CPosicion(19, 13);
		pos_prohib[95] = CPosicion(20, 8);
		pos_prohib[96] = CPosicion(20, 13);
		pos_prohib[97] = CPosicion(0, 6);
		pos_prohib[98] = CPosicion(0, 7);
		pos_prohib[99] = CPosicion(0, 14);
		pos_prohib[100] = CPosicion(8, 21);
		pos_prohib[101] = CPosicion(9, 21);
		pos_prohib[102] = CPosicion(21, 9);
		pos_prohib[103] = CPosicion(21, 10);
		pos_prohib[104] = CPosicion(21, 11);
		pos_prohib[105] = CPosicion(21, 12);
	}
}

CMapa::~CMapa()
{
	delete m_Board[0];
	delete m_Board[1];
	delete m_Board[2];
	delete m_Board[3];
	delete m_Board[4];
	delete m_Board[5];
}


bool CMapa::compruebaPosProhib(CPosicion aux)
{
	for (int i = 0; i < 200; i++)
	{
		if (pos_prohib[i] == aux) return true;
	}
	return false;
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
		for (int i = 0; i < 6; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}

		if (compruebaPosProhib(aux)) 
			flag = false;

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
		for (int i = 0; i < 6; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}

		if (compruebaPosProhib(aux)) 
			flag = false;

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
		for (int i = 0; i < 6; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}

		if (compruebaPosProhib(aux)) 
			flag = false;

		if (flag)
			m_Board[PersonajeActivo]->setPos(aux);
		break;
	}
	case 'd':
	{
		CPosicion aux = m_Board[PersonajeActivo]->getPos();
		aux.x += 1;
		bool flag = true;
		for (int i = 0; i < 6; i++)
		{
			if ((m_Board[i]->getPos()) == aux)
				flag = false;
		}

		if (compruebaPosProhib(aux)) 
			flag = false;

		if (flag)
			m_Board[PersonajeActivo]->setPos(aux);
		break;
	}
	}
	
}


//void CMapa::IA()
//{
//	int aux[3] = { 0,0,0 };                              //En este vector se almacenará los personajes
//	int z = 0;										 //en orden de preferencia para el ataque
//	bool ataque_realizado = false;
//
//	for (int i = 0; i <= 6; i++) {					//Guardo la posicion de los personajes en el tablero
//		if (m_Board[i]->getm_bBando() == 1) {
//			aux[++z] = i;
//		}
//
//		for (int i = 0; i < 3; i++)					//Ordeno a los personajes en funcion de su vida, de menor a mayor
//			for (int j = 0; j < 2; j++)
//				if (m_Board[aux[j]]->getm_iSalud() > m_Board[aux[j + 1]]->getm_iSalud()) {
//					int Temporal = aux[j];
//					aux[j] = aux[j + 1];
//					aux[j + 1] = Temporal;
//				}
//
//		//El ataque fisico se propriza sobre el de habilidad
//		//Solo se puede atacar una vez
//		for (int i = 0; i < 3; i++) {
//			if (!ataque_realizado) {
//				bool posible_fis = false;
//				bool posible_hab = false;
//				if (sqrt(pow(m_Board[PersonajeActivo]->getPos().x - m_Board[aux[i]]->getPos().x, 2) + pow(m_Board[PersonajeActivo]->getPos().y - m_Board[aux[i]]->getPos().y, 2)) < 3) posible_fis = true;
//				if (sqrt(pow(m_Board[PersonajeActivo]->getPos().x - m_Board[aux[i]]->getPos().x, 2) + pow(m_Board[PersonajeActivo]->getPos().y - m_Board[aux[i]]->getPos().y, 2)) < 10) posible_hab = true;
//				if (posible_fis) {
//					m_Board[PersonajeActivo]->ataque_fis(*(m_Board[aux[i]]));
//					ataque_realizado = true;
//				}
//				if (ataque_realizado) continue;
//				if (posible_hab)
//					if (m_Board[PersonajeActivo]->ataque_hab(*(m_Board[aux[i]]))) ataque_realizado = true;
//			}
//		}
//
//		//Si ningún personaje se encontraba a rango el enemigo se mueve hacia el personaje que tenga menos vida
//		CPosicion pos_aux;
//
//		if (!ataque_realizado) {
//			for (int i = 0; i < 3; i++) {
//				bool pos_ok = false;
//				if (m_Board[aux[i]]->getPos().x < m_Board[PersonajeActivo]->getPos().x) {								//Si está a la derecha
//					if (m_Board[aux[i]]->getPos().x >(m_Board[PersonajeActivo]->getPos().x + m_Board[PersonajeActivo]->m_iVel)) pos_aux.x = m_Board[aux[i]]->getPos().x;			//compruebo si moviendome el maximo le supero en x. Si le supero me quedo en su coordenada x, si no, me muevo lo maximo posible
//					else pos_aux.x = m_Board[aux[i]]->getPos().x - m_Board[PersonajeActivo]->m_iVel;
//				}
//
//				if (m_Board[aux[i]]->getPos().x > m_Board[PersonajeActivo]->getPos().x) {
//					if (m_Board[aux[i]]->getPos().x < (m_Board[PersonajeActivo]->getPos().x + m_Board[PersonajeActivo]->m_iVel)) pos_aux.x = m_Board[aux[i]]->getPos().x;
//					else pos_aux.x = m_Board[aux[i]]->getPos().x + m_Board[PersonajeActivo]->m_iVel;
//				}
//				if (m_Board[aux[i]]->getPos().y < m_Board[PersonajeActivo]->getPos().y) {
//					if (m_Board[aux[i]]->getPos().y < (m_Board[PersonajeActivo]->getPos().y + m_Board[PersonajeActivo]->m_iVel)) pos_aux.y = m_Board[aux[i]]->getPos().y;
//					else pos_aux.y = m_Board[aux[i]]->getPos().y - m_Board[PersonajeActivo]->m_iVel;
//				}
//
//				if (m_Board[aux[i]]->getPos().y > m_Board[PersonajeActivo]->getPos().y) {
//					if (m_Board[aux[i]]->getPos().y < (m_Board[PersonajeActivo]->getPos().y + m_Board[PersonajeActivo]->m_iVel)) pos_aux.y = m_Board[aux[i]]->getPos().y;
//					else pos_aux.y = m_Board[aux[i]]->getPos().y + m_Board[PersonajeActivo]->m_iVel;
//				}
//				if (CompruebaPos(pos_aux)) pos_ok = true;
//				if (pos_ok) break;
//			}
//		}
//
//		//Movimiento cuadrícula a cuadrícula
//		if (!ataque_realizado) {
//			do {
//				bool mov_realizado = false;
//				if (!mov_realizado) {
//					if (pos_aux.x > m_Board[PersonajeActivo]->getPos().x) {
//						MoverPersonaje('d');
//						mov_realizado = true;
//					}
//				}
//				if (!mov_realizado) {
//					if (pos_aux.x < m_Board[PersonajeActivo]->getPos().x) {
//						MoverPersonaje('a');
//						mov_realizado = true;
//					}
//				}
//				if (!mov_realizado) {
//					if (pos_aux.y > m_Board[PersonajeActivo]->getPos().y) {
//						MoverPersonaje('w');
//						mov_realizado = true;
//					}
//				}
//				if (!mov_realizado) {
//					if (pos_aux.y > m_Board[PersonajeActivo]->getPos().y) {
//						MoverPersonaje('s');
//						mov_realizado = true;
//					}
//				}
//			} while ((pos_aux.x != m_Board[PersonajeActivo]->getPos().x) && (pos_aux.y != m_Board[PersonajeActivo]->getPos().y));
//		}
//
//		if (!ataque_realizado) {
//			for (int i = 0; i < 3; i++) {
//				if (!ataque_realizado) {
//					bool posible_fis = false;
//					bool posible_hab = false;
//					if (sqrt(pow(m_Board[PersonajeActivo]->getPos().x - m_Board[aux[i]]->getPos().x, 2) + pow(m_Board[PersonajeActivo]->getPos().y - m_Board[aux[i]]->getPos().y, 2)) < 3) posible_fis = true;
//					if (sqrt(pow(m_Board[PersonajeActivo]->getPos().x - m_Board[aux[i]]->getPos().x, 2) + pow(m_Board[PersonajeActivo]->getPos().y - m_Board[aux[i]]->getPos().y, 2)) < 10) posible_hab = true;
//					if (posible_fis) {
//						m_Board[PersonajeActivo]->ataque_fis(*m_Board[aux[i]]);
//						ataque_realizado = true;
//					}
//					if (ataque_realizado) continue;
//					if (posible_hab)
//						if (m_Board[PersonajeActivo]->ataque_hab(*m_Board[aux[i]])) ataque_realizado = true;
//				}
//			}
//		}
//
//	}
//}