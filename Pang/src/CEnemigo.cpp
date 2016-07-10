#include <stdlib.h>
#include "CEnemigo.h"
#include "CMapa.h"
#include "glut.h"
#include "ETSIDI.h"


void CEnemigo::dibuja(int i, int j) {
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1); glVertex3f(-10, 0, -0.1);

	glTexCoord2d(1, 1); glVertex3f(10, 0, -0.1);

	glTexCoord2d(1, 0); glVertex3f(10, 15, -0.1);

	glTexCoord2d(0, 0); glVertex3f(-10, 15, -0.1);

	glEnd();

	glEnable(GL_LIGHTING);

	glDisable(GL_TEXTURE_2D);
}


CEnemigo::~CEnemigo()
{
}

CEnemigo::CEnemigo(char* text):
	CPersonaje(text)
{
	m_iAtq_fis = 25;
	m_iAtq_hab = 25;
	m_iSaludMax = m_iSalud = 1000;
	m_iDef_fis = 0,4;
	m_iDef_hab = 0,4;
	m_iVel = 3;				//constante en todos los enemigos
	m_iBando = false;
	m_iNivel = 1;
	m_iAguante = m_iAguanteMax = 200;
	m_bDisp = true;
}

/*void CEnemigo::SeleccionObjetivo(CMapa map) {
=======
void CEnemigo::SeleccionObjetivo(CMapa map) {
>>>>>>> origin/master:videojueguinchiproject/CEnemigo.cpp
	CPosicion aux;
	bool ataquerealizado = false;
	int num_pers = 0, vidas[5];
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {										//Primero un barrido en el que miro cuantos
			if ((map.m_Board[i][j])->m_Type == (CEnte::PERSONAJE)) {			//personajes hay y copio sus vidas
				CPersonaje* aux = dynamic_cast <CPersonaje *>(map.m_Board[i][j]);
				vidas[num_pers] = aux->getm_iSalud();
				num_pers++;
			}
		}
	}
	for (int i = 0; i < num_pers; i++)
		for (int j = 0; j < num_pers - 1; j++)
			if (vidas[j] > vidas[j + 1]) {
				int Temp = vidas[j];										//ordeno las vidas de menor a mayor
				vidas[j] = vidas[j + 1];
				vidas[j + 1] = Temp;
			}

	//Intento atacar primero a los de vida mas baja
	//El ataque fisico se propriza sobre el de habilidad
	//Si se ha atacado se fuerza a salir para que no pueda atacar más
	for (int z=0; z < num_pers; z++)
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				if ((map.m_Board[i][j])->m_Type == (CEnte::PERSONAJE)) {
					if (((dynamic_cast <CPersonaje *>(map.m_Board[i][j]))->getm_iSalud()) == vidas[z]) {
						bool posible_fis = false;
						bool posible_hab = false;
						if (sqrt(pow(i - getPos().x, 2) + pow(j - getPos().y, 2)) < 3) posible_fis = true;
						if (sqrt(pow(i - getPos().x, 2) + pow(j - getPos().y, 2)) < 10) posible_hab = true;
						if (posible_fis) {
							CPersonaje& aux = dynamic_cast <CPersonaje&> (*(map.m_Board[i][j]));
							ataque_fis(aux);
							posible_hab = false;
							ataquerealizado = true;
						}
						if (posible_hab)
						{
							CPersonaje& aux = dynamic_cast <CPersonaje&> (*(map.m_Board[i][j]));
							if (ataque_hab(aux)) ataquerealizado = true;
						}
						if (ataquerealizado) j = 30;
					}
					if (ataquerealizado) i = 30;
				}
				if (ataquerealizado)	z = 30;
			}
		}
	//Decision si no se ha atacado. El enemigo se moverá hacia el personaje
	//cercano con menos vida.
	if (!ataquerealizado) {
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				if ((map.m_Board[i][j])->m_Type == (CEnte::PERSONAJE)) {
					if (((dynamic_cast <CPersonaje*>(map.m_Board[i][j])->getm_iSalud())) == vidas[0]) {
						if (i < getPos().x) {									//Si estoy a la derecha del objetivo
							if (i > (getPos().x + m_iVel)) aux.x = i;			//compruebo si moviendome el maximo le supero en x
							else aux.x = i - m_iVel;							//Si le supero, me quedo en su coordenada x
						}														//Si no le supero, me muevo el maximo posible
						if (i > getPos().x) {
							if (i <(getPos().x + m_iVel)) aux.x = i;
							else aux.x = i + m_iVel;
						}
						if (j < getPos().y) {
							if (j >(getPos().y + m_iVel)) aux.y = j;
							else aux.y = j - m_iVel;
						}
						if (j > getPos().y) {
							if (j <(getPos().y + m_iVel)) aux.y = j;
							else aux.y = j + m_iVel;
						}
					}
				}
			}
		}
		map.MoverPersonaje(this, aux);
	}

	//Intento atacar de nuevo
	if(!ataquerealizado){
	for (int z = 0; z < num_pers; z++)
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				if ((map.m_Board[i][j])->m_Type == (CEnte::PERSONAJE)) {
					if ((dynamic_cast <CPersonaje*>(map.m_Board[i][j])->getm_iSalud()) == vidas[z]) {
						bool posible_fis = false;
						bool posible_hab = false;
						if (sqrt(pow(i - getPos().x, 2) + pow(j - getPos().y, 2)) < 3) posible_fis = true;
						if (sqrt(pow(i - getPos().x, 2) + pow(j - getPos().y, 2)) < 10) posible_hab = true;
						if (posible_fis) {
							CPersonaje& aux = dynamic_cast <CPersonaje&> (*(map.m_Board[i][j]));
							ataque_fis(aux);
							posible_hab = false;
							ataquerealizado = true;
						}
						if (posible_hab)
						{
							CPersonaje& aux = dynamic_cast <CPersonaje&> (*(map.m_Board[i][j]));
							if (ataque_hab(aux)) ataquerealizado = true;
						}
						if (ataquerealizado) j = 30;
					}
					if (ataquerealizado) i = 30;
				}
				if (ataquerealizado)	z = 30;
			}
		}
	}
}*/
