#pragma once
#include "Movimiento.h"
#include "Tubo.h"
#include "Bola.h"
#include "Utiles.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>

using namespace std;

enum LEVEL
{
	L1 = 3, //C2, 1
	L2 = 5, //C3, 2
	L3 = 7, //C5, 2
	L4 = 8, //C6, 2
	L5 = 9,  //C7, 2
	FIN = -1,
	nulo = NULL
};

const int BALLS_CANT = 4;

class Nivel
{
private:
	LEVEL nivel;
	DoubleList<Tubo*>* tubos;
	DoubleList<Movimiento*>* movimientos;//los 5 ultimos movimientos

public:
	Nivel(LEVEL);
	Nivel();
	~Nivel();
	Nivel(LEVEL nivel, DoubleList<Tubo*>* tubos);
	void setTubos(DoubleList<Tubo*>*);
	void setMovimiento(DoubleList<Movimiento*>*);
	DoubleList<Tubo*>* getTubos();
	DoubleList<Movimiento*>* getMovimiento();
	string toString();
	void loadMap(LEVEL);
	void converter(int);
	LEVEL getNivel();
	static LEVEL nextLevel(LEVEL);
};
