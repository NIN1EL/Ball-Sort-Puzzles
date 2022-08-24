#include "Bola.h"

Bola::Bola(int i,COLOR color, float x, float y) : Graphic_Object(TYPE_OBJECT::BOLA, x, y, Utiles::getImageToColor(color))
{
	this->i = i;
	this->color = color;
}

Bola::Bola(Bola& bola) : Graphic_Object(TYPE_OBJECT::BOLA, bola.getX(), bola.getY(), bola.getImage())
{
	this->i = bola.getI();
	this->color = bola.getColor_();
}

Bola::~Bola()
{
	
}

int Bola::getI()
{
	return i;
}

void Bola::setI(int i)
{
	this->i = i;
}

void Bola::setColor(COLOR color)
{
	this->color = color;
}

COLOR Bola::getColor_()
{
	return color;
}

string Bola::toString()
{
	stringstream out;
	out << "{ id: " << i << ", color: " << color << ", ( X: " << x << ", Y: " << y << "), img: " << image << " }" << endl;
	return out.str();
}
