#include "Nivel.h"
#include <vector>
#include <locale>

Nivel::Nivel(LEVEL nivel)
{
	this->nivel = nivel;
	tubos = new DoubleList<Tubo*>();
	loadMap(nivel);
}

Nivel::Nivel()
{
	tubos = NULL;
	movimientos = NULL;
}

Nivel::~Nivel()
{
	delete tubos;
	delete movimientos;
	tubos = NULL;
	movimientos = NULL;
}

Nivel::Nivel(LEVEL nivel, DoubleList<Tubo*>* tubos)
{
	this->nivel = nivel;
	this->tubos = tubos;
}

void Nivel::setTubos(DoubleList<Tubo*>* tubos)
{
	this->tubos = tubos;
}

void Nivel::setMovimiento(DoubleList<Movimiento*>* movimientos)
{
	this->movimientos = movimientos;
}

DoubleList<Tubo*>* Nivel::getTubos()
{
	return tubos;
}

DoubleList<Movimiento*>* Nivel::getMovimiento()
{
	return movimientos;
}

string Nivel::toString()
{
	stringstream x;
	Iterator<Tubo*>* ite = tubos->iterator();
	while (ite->hasNext())
	{
		x << "Tubo #: " << ite->index() << endl;
		if (ite->object()->empty()) x << "Tubo vacio" << endl;
		else x << ite->object()->toString() << endl;
		ite->next();
	}
	delete ite;
	return x.str();
}

void Nivel::loadMap(LEVEL level)
{
	Tubo* tubo;
	vector<COLOR> colors;
	int cant;
	if (level == L1) cant = level - 1;
	else  cant = level - 2;
	//creando los colores de la bola
	for (int i = 0; i < cant; i++)
	{
		for (int j = 0; j < BALLS_CANT; j++)
		{
			colors.push_back(COLOR(i));//random
		}
	}
	// y barajar
	srand(unsigned(time(NULL)));
	random_shuffle(colors.begin(), colors.end());
	//tamannos de las imagenes
	float x = ini_x, y = ini_y;//esto 
	int id = 0;
	//creando los tubos e insertando las bolas
	for (int i = 0; i < level; i++)
	{	
		tubo = new Tubo(i, x, y - down_tubo);
		tubos->add(tubo);
		//si es nivel 1
		if (level == L1) {
			if (i != level - 1) {
				for (int j = 0; j < BALLS_CANT; j++)
				{
					tubo->push(new Bola(id++,colors.back(), x + add_x_bola, y + add_y_bola));
					colors.pop_back();
					y -= inc_y;
				}
				y = ini_y;
			}
		}
		else
		{
			//sino entonces es nivel 2 o mas
			if (i < level - 2) {
				for (int j = 0; j < BALLS_CANT; j++)
				{
					tubo->push(new Bola(id++,colors.back(), x + add_x_bola, y + add_y_bola));
					colors.pop_back();
					y -= inc_y;
				}
				y = ini_y;
			}
		}
		x += inc_x;
	}
}

LEVEL Nivel::getNivel()
{
	return this->nivel;
}

LEVEL Nivel::nextLevel(LEVEL level)
{
	LEVEL next_level;
	switch (level){
		case L1: next_level = L2; break;
		case L2: next_level = L3; break;
		case L3: next_level = L4; break;
		case L4: next_level = L5; break;
		default: next_level = FIN;
	}
	return next_level;
}
