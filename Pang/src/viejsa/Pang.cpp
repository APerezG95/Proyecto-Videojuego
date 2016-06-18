#include <stdlib.h>
#include "glut.h"
#include "ETSIDI.h"
#include "CMapa.h"
#include "CPosicion.h"
#include "CHippie.h"

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
	CMapa mapa(20, 20);
	int matrix[20][20] =
	{ { 1,1,1,1,1,2,1,1,1,1,8,1,1,1,1,7,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,6,1,1,1,1,6,1,1,1,1,6,1,1,1,1 } };

	mapa.inicializaMapa(matrix);
	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

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
	/*ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("En busca del aprobado perdido", 0, 20);*/
	
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void onKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mapa.tecla(key);

	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	//mundo.teclaEspecial(key);
}
void onTimer(int value)
{
//poner aqui el código de animacion
	//mundo.mueve();

	//no borrar estas lineas
	glutTimerFunc(25,onTimer,0);
	glutPostRedisplay();
}
