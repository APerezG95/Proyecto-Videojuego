#include <stdlib.h>
#include "CEnemigo.h"
#include "CMapa.h"
#include "glut.h"
#include "ETSIDI.h"

CEnemigo::~CEnemigo()
{
}

CEnemigo::CEnemigo(char* text, char* careto) :
	CPersonaje(text, careto)
{
	Inicializa();
}


void CEnemigo::Inicializa()
{
	m_iAtq_fis = 25;
	m_iAtq_hab = 25;
	m_iSaludMax = m_iSalud = 1000;
	m_iDef_fis = 0, 4;
	m_iDef_hab = 0, 4;
	m_iVel = 3;				//constante en todos los enemigos
	m_bBando = false;
	m_iAguante = m_iAguanteMax = 200;
	m_bDisp = true;
}


void CEnemigo::SeleccionObjetivo(CMapa map)
{
	int aux[3] = { 0,0,0 };                              //En este vector se almacenará los personajes
	int z = 0;										 //en orden de preferencia para el ataque
	bool ataque_realizado = false;

	for (int i = 0; i <= 6; i++) {					//Guardo la posicion de los personajes en el tablero
		if (map.m_Board[i]->getm_bBando() == 1) {
			aux[++z] = i;
		}

		for (int i = 0; i < 3; i++)					//Ordeno a los personajes en funcion de su vida, de menor a mayor
			for (int j = 0; j < 2; j++)
				if (map.m_Board[aux[j]]->getm_iSalud() > map.m_Board[aux[j + 1]]->getm_iSalud()) {
					int Temporal = aux[j];
					aux[j] = aux[j + 1];
					aux[j + 1] = Temporal;
				}

		//El ataque fisico se propriza sobre el de habilidad
		//Solo se puede atacar una vez
		for (int i = 0; i < 3; i++) {
			if (!ataque_realizado) {
				bool posible_fis = false;
				bool posible_hab = false;
				if (sqrt(pow(getPos().x - map.m_Board[aux[i]]->getPos().x, 2) + pow(getPos().y - map.m_Board[aux[i]]->getPos().y, 2)) < 3) posible_fis = true;
				if (sqrt(pow(getPos().x - map.m_Board[aux[i]]->getPos().x, 2) + pow(getPos().y - map.m_Board[aux[i]]->getPos().y, 2)) < 10) posible_hab = true;
				if (posible_fis) {
					ataque_fis(*(map.m_Board[aux[i]]));
					ataque_realizado = true;
				}
				if (ataque_realizado) continue;
				if (posible_hab)
					if (ataque_hab(*(map.m_Board[aux[i]]))) ataque_realizado = true;
			}
		}

		//Si ningún personaje se encontraba a rango el enemigo se mueve hacia el personaje que tenga menos vida
		CPosicion pos_aux;

		if (!ataque_realizado) {

			if (map.m_Board[aux[0]]->getPos().x < getPos().x) {								//Si está a la derecha
				if (map.m_Board[aux[0]]->getPos().x > (getPos().x + m_iVel)) pos_aux.x = map.m_Board[aux[0]]->getPos().x;		//compruebo si moviendome el maximo le supero en x. Si le supero me quedo en su coordenada x, si no, me muevo lo maximo posible
				else pos_aux.x = map.m_Board[aux[0]]->getPos().x - m_iVel;
			}

			if (map.m_Board[aux[0]]->getPos().x > getPos().x) {
				if (map.m_Board[aux[0]]->getPos().x < (getPos().x + m_iVel)) pos_aux.x = map.m_Board[aux[0]]->getPos().x;
				else pos_aux.x = map.m_Board[aux[0]]->getPos().x + m_iVel;
			}
			if (map.m_Board[aux[0]]->getPos().y < getPos().y) {
				if (map.m_Board[aux[0]]->getPos().y < (getPos().y + m_iVel)) pos_aux.y = map.m_Board[aux[0]]->getPos().y;
				else pos_aux.y = map.m_Board[aux[0]]->getPos().y - m_iVel;
			}

			if (map.m_Board[aux[0]]->getPos().y > getPos().y) {
				if (map.m_Board[aux[0]]->getPos().y < (getPos().y + m_iVel)) pos_aux.y = map.m_Board[aux[0]]->getPos().y;
				else pos_aux.y = map.m_Board[aux[0]]->getPos().y + m_iVel;
			}
		}
		//M: Aquí un bucle para que vaya moviéndose una a una las posiciones hasta pos_aux desde su posición. Atento a las nuevas variables de posición
		//de CPersonaje y las funciones que metí nuevas, seguro que alguna te facilita estos cálculos
		//if (!ataque_realizado) map.MoverPersonaje(this, pos_aux);

		if (!ataque_realizado) {
			for (int i = 0; i < 3; i++) {
				if (!ataque_realizado) {
					bool posible_fis = false;
					bool posible_hab = false;
					if (sqrt(pow(getPos().x - map.m_Board[aux[i]]->getPos().x, 2) + pow(getPos().y - map.m_Board[aux[i]]->getPos().y, 2)) < 3) posible_fis = true;
					if (sqrt(pow(getPos().x - map.m_Board[aux[i]]->getPos().x, 2) + pow(getPos().y - map.m_Board[aux[i]]->getPos().y, 2)) < 10) posible_hab = true;
					if (posible_fis) {
						ataque_fis(*map.m_Board[aux[i]]);
						ataque_realizado = true;
					}
					if (ataque_realizado) continue;
					if (posible_hab)
						if (ataque_hab(*map.m_Board[aux[i]])) ataque_realizado = true;
				}
			}
		}

	}
}