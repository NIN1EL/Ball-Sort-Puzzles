#include "Archivos.h"

Archivos::Archivos()
{
	nivel = new Nivel();
}

void Archivos::Guardar(Nivel* nivel)
{
	remove("partida.csv"); //remueve el archivo
	fstream archivo;
	archivo.open("partida.csv", ios::out | ios::app); // crea el archivo
	archivo << nivel->getNivel() << endl; // se guarda el primero el nivel, primera fila;
	Iterator<Tubo*>* ite = nivel->getTubos()->iterator();
	while (ite->hasNext())
	{
		archivo << ite->object()->getI() << ","<< ite->object()->getX() << ","<< ite->object()->getY() << endl;
		archivo << ite->object()->size() << endl;
		if (!ite->object()->empty()) { // se guardan datos de los tubos
			Iterator<Bola*>* it = ite->object()->iterator();
			while (it->hasNext()) {
				archivo << it->object()->getI() << ","
					<< it->object()->getColor_() << ","
					<< it->object()->getX() << ","
					<< it->object()->getY()
					<< endl;// se guradan datos de las bolas color, x, y
				it->next();
			}
		}
		ite->next();
	}
	archivo.close();
}

Nivel* Archivos::Recuperar()
{
	fstream fin;
	fin.open("partida.csv", ios::in);
	string nivel;
	int nivel_;
	getline(fin, nivel);
	nivel_ = getInt(nivel);
	DoubleList<Tubo*>* tubos = new DoubleList<Tubo*>();
	for (int k = 0; k < nivel_; k++) {
		string i, x, y, count;
		int count_;
		getline(fin, i, ',');
		getline(fin, x, ',');
		getline(fin, y);
		Tubo* tubo = new Tubo(getInt(i), getInt(x), getInt(y));
		getline(fin, count);
		count_ = getInt(count);
		for (int j = 0; j < count_; j++)
		{
			string i_, color, x_, y_;
			getline(fin, i_, ',');
			getline(fin, color, ',');
			getline(fin, x_, ',');
			getline(fin, y_);
			Bola* bola = new Bola(getInt(i_), getColor(getInt(color)), getInt(x_), getInt(y_));
			tubo->push(bola);
		}
		tubos->add(tubo);
	}
	return new Nivel(getLevel(nivel_), tubos);
}

int Archivos::getInt(string s) {
	return (int)std::strtol(s.c_str(), nullptr, 10);
}

LEVEL Archivos::getLevel(int level) {
	LEVEL nivel;
	switch (level)
	{
	case 3: // Nivel 1
		nivel = L1;
		break;
	case 5: // Nivel 2
		nivel = L2;
		break;
	case 7: // Nivel 3
		nivel = L3;
		break;
	case 8:// Nivel 4
		nivel = L4;
		break;
	case 9: // Nivel 5
		nivel = L5;
		break;
	default:
		nivel = nulo;
		break;
	}
	return nivel;
}

COLOR Archivos::getColor(int c) {
	COLOR color;
	switch (c)
	{
	case 0:
		color = pink;
		break;
	case 1:
		color = blue;
		break;
	case 2:
		color = green;
		break;
	case 3:
		color = red;
		break;
	case 4:
		color = yellow;
		break;
	case 5:
		color = white;
		break;
	case 6:
		color = brown;
		break;
	}

	return color;
}

void Archivos::LimpiarTubos()
{
	Iterator<Tubo*>* ite = nivel->getTubos()->iterator();
	ite->object()->toString();
	while (ite->hasNext())
	{
		for (int i = 1; i <= 4; i++) {
			if (!ite->object()->empty())
				ite->object()->pop();
		}
		ite->next();
	}
}

