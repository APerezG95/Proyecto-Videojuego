#include <stdlib.h>
#include "glut.h"
#include "ETSIDI.h"
#include "CMapa.h"
#include "CPosicion.h"
#include "CHippie.h"
#include "CEnemigo.h"

CMapa mapa;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void onDraw(void); //esta funcion sera llamada para dibujar
void onTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void onKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y); //cuando se pulse una tecla especial	

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1920,1080);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("En busca del aprobado perdido alpha 0.1.6");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Cosis


	//Registrar los callbacks
	glutDisplayFunc(onDraw);
	glutTimerFunc(25,onTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(onKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void onDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	mapa.dibuja();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void onKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
		mapa.tecla(key);
	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	//mundo.teclaEspecial(key);
}
void onTimer(int value)
{
	//poner aqui el c�digo de animacion

	//no borrar estas lineas
	glutTimerFunc(25,onTimer,0);
	glutPostRedisplay();
}
