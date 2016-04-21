#pragma once

class CPosicion
{
private:

	//TU MARIO TT HASME EL CONSTRUCTOR SIN ARGUMENTOS. VAMOS, UNO DE PODEMOS DEFENDIENDO SUS POLITICAS

public:	//De momento pongo todo público para quitarnos de líos

	int x;
	int y;

	CPosicion(int i, int j) :x(i), y(j) {};
	void setPos(int i, int j) 
	{
		x = i;	y = j;
	}
	void getPos(int& i, int& j)	//Ojo, retocar esto que no me fio de que funsione
	{
		i = x;	j = y;
	}
};