#include "Partida.h"


Partida::Partida(DoubleList<Nivel*>* niveles)
{
	this->niveles = niveles;
}

Partida::Partida()
{
	this->niveles = NULL;
}

void Partida::setNivel(DoubleList<Nivel*>* niveles)
{
	this->niveles = niveles;
}

DoubleList<Nivel*>* Partida::getNivel()
{
	return niveles;
}

Partida::~Partida()
{
}
