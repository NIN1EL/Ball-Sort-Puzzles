#include "Objeto_Grafico.h"

Graphic_Object::Graphic_Object(TYPE_OBJECT type, float x, float y, string image)
{
	this->x = x;
	this->y = y;
	this->setPosition(x, y);
	this->image = image;
	texture->loadFromFile(image);
	texture->isSmooth();
	this->setTexture(*texture);
}

Graphic_Object::~Graphic_Object()
{
	delete texture;
}

void Graphic_Object::setX(float x)
{
	this->x = x;
	this->setPosition(x, y);
}

float Graphic_Object::getX()
{
	return x;
}

void Graphic_Object::setY(float y)
{
	this->y = y;
	this->setPosition(x, y);
}

float Graphic_Object::getY()
{
	return y;
}

void Graphic_Object::setImage(string image)
{
	this->image = image;
	texture->loadFromFile(image);
	texture->isSmooth();
	this->setTexture(*texture);
}

string Graphic_Object::getImage()
{
	return image;
}

Graphic_Object* Graphic_Object::setPosition_(float x, float y)
{
	this->x = x;
	this->y = y;
	this->setPosition(x, y);
	return this;
}

Graphic_Object* Graphic_Object::setScale_(int x, int y)
{
	this->setScale(((float)x / (float)this->getTexture()->getSize().x), ((float)y / (float)this->getTexture()->getSize().y));
	return this;
}

Sprite* Graphic_Object::getSprite()
{
	return this;
}

TYPE_OBJECT Graphic_Object::getType()
{
	return type;
}
