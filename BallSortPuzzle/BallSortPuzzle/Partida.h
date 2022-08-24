#pragma once
#include "Nivel.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Partida
{
private:
	DoubleList<Nivel*>* niveles;
public:
	Partida(DoubleList<Nivel*>*);
	Partida();
	void setNivel(DoubleList<Nivel*>*);
	DoubleList<Nivel*>* getNivel();
	~Partida();
};