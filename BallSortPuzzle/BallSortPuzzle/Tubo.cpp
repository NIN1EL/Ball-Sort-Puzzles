#include "Tubo.h"
//O(1); for(int i = 0; i < n; i++) = O(n)
Tubo::Tubo(int i, float x, float y) : Graphic_Object(TYPE_OBJECT::TUBO, x, y, Utiles::getImage())
{
	this->i = i;
}

Tubo::Tubo(Tubo& tubo) : Graphic_Object(tubo.getType(), tubo.getX(), tubo.getY(), tubo.getImage())
{
	this->i = tubo.getI();
	for (int i = 0; i < tubo.tam; i++)
	{
		push( new Bola(*tubo.get(i)) );
	}
}

Tubo::~Tubo()
{
	while (!this->empty())
	{
		delete pop();
	}
}
int Tubo::getI()
{
	return i;
}

void Tubo::setI(int i)
{
	this->i = i;
}

Bola* Tubo::pop()
{
	return this->removeLast();
}

Bola* Tubo::top()
{
	return this->getLast();
}

void Tubo::push(Bola* b)
{
	(DoubleList<Bola*>*)this->add(b);
}

int Tubo::search(Bola*)//falta
{
	return 0;
}

const int Tubo::size()
{
	return this->tam;
}

const bool Tubo::empty()
{
	return this->tam == 0;
}
Iterator<Bola*>* Tubo::iterator()
{
	return DoubleList::iterator();
}
const string Tubo::toString()
{
	stringstream x;
	
	Tubo* aux = new Tubo(*this);

	for (int i = this->tam - 1; i >= 0; i--)
	{
		x << i+1 << " ) " << aux->get(i)->toString() << endl;
	}

	return x.str();
}


