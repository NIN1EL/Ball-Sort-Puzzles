#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
using namespace sf;

using namespace std;

enum TYPE_OBJECT { BOLA, TUBO, IMAGENINICIO };

class Graphic_Object : public Sprite
{
protected:
	TYPE_OBJECT type;
	float x, y;
	string image;
	Texture* texture = new Texture;
public:
	Graphic_Object(TYPE_OBJECT, float, float, string);
	~Graphic_Object();
	virtual void setX(float);
	virtual float getX();
	virtual void setY(float);
	virtual float getY();
	virtual void setImage(string);
	virtual string getImage();
	virtual Graphic_Object* setPosition_(float, float);
	virtual Graphic_Object* setScale_(int, int);
	virtual Sprite* getSprite();
	virtual TYPE_OBJECT getType();
};
