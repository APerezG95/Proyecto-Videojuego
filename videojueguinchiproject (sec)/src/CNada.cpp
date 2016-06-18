#include <stdlib.h>
#include "CNada.h"
#include "glut.h"
#include "ETSIDI.h"

void CNada::dibuja()
{
	glPushMatrix();
	glTranslatef((this->getPos()).x, (this->getPos()).y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	//gestion de direccion y animacion
	/*if (velocidad.x>0.01)sprite.flip(false, false);
	if (velocidad.x<-0.01)sprite.flip(true, false);
	if ((velocidad.x<0.01) && (velocidad.x>-0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);*/
	textura.draw();

	glPopMatrix();
}

CNada::~CNada()
{

}
