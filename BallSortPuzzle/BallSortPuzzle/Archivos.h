#pragma once

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include "Nivel.h"
using namespace std;

class Archivos
{
private:
	Nivel* nivel;
public:
	Archivos();
	static void Guardar(Nivel*);
	static Nivel* Recuperar();
	void LimpiarTubos();

private:
	static int getInt(string);
	static LEVEL getLevel(int);
	static COLOR getColor(int);
};