#pragma once
#include "Tubo.h"
#include "Bola.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Movimiento
{
private:
	Tubo* tuboOrigen;
	Tubo* tuboDestino;
	Bola *bola;

public:
	Movimiento(Tubo*,Bola*);
	~Movimiento();
	void setTuboOrigen(Tubo*);
	void setTuboDestino(Tubo*);
	void setBola(Bola*);
	Tubo* getTuboOrigen();
	Tubo* getTuboDestino();
	Bola* getBola();
	string toString();
};
