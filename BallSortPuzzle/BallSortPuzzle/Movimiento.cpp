#include "Movimiento.h"

Movimiento::Movimiento(Tubo* tuboOrigen, Bola *bola)
{
	this->tuboOrigen = new Tubo(*tuboOrigen);
	this->tuboDestino = NULL;
	this->bola = new Bola(*bola);
}

Movimiento::~Movimiento()
{
	delete tuboOrigen;
	delete tuboDestino;
	delete bola;
	tuboOrigen = NULL;
	tuboDestino = NULL;
	bola = NULL;
}

void Movimiento::setTuboOrigen(Tubo*tuboOrigen)
{
	this->tuboOrigen = tuboOrigen;
}

void Movimiento::setTuboDestino(Tubo* tuboDestino)
{
	this->tuboDestino = new Tubo(*tuboDestino);
}

void Movimiento::setBola(Bola *bolas)
{
	this->bola = bola;
}

Tubo* Movimiento::getTuboOrigen()
{
	return tuboOrigen;
}

Tubo* Movimiento::getTuboDestino()
{
	return tuboDestino;
}

Bola* Movimiento::getBola()
{
	return bola;
}

string Movimiento::toString()
{
	stringstream out;
	out << "{\norigen: \n" << tuboOrigen->toString() << ",  destino:  \n" << ((tuboDestino)?tuboDestino->toString():"NULL") << ", bola: \n " << bola->toString() << " \n}" << endl;
	return out.str();
}
