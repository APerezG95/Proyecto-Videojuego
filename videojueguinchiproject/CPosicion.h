#pragma once

class CPosicion
{
private:

	

public:	//De momento pongo todo p�blico para quitarnos de l�os

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