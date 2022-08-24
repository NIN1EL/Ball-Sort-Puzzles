#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "Objeto_Grafico.h"
#include "Utiles.h"

using namespace std;


class Bola : public Graphic_Object
{
protected:
	int i;
	COLOR color;
public:
	Bola(int,COLOR, float = 0, float = 0);
	Bola(Bola&);
	~Bola();
	int getI();
	void setI(int);
	void setColor(COLOR);
	COLOR getColor_();
	virtual string toString();
};