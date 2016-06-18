#pragma once

class CPosicion
{
public:

	int x;
	int y;

	CPosicion():x(0),y(0){}
	CPosicion(int i, int j) :x(i), y(j) {}
	void setPos(int i, int j) 
	{
		x = i;	y = j;
	}
	CPosicion getPos(int i, int j)
	{
		i = x;	j = y;
	}
};