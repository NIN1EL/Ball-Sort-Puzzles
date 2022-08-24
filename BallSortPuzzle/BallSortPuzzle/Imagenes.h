#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Utiles.h"

using namespace sf;
using namespace std;

class Imagenes
{
public:
	Imagenes();
	Sprite Imagen_Fondo_Pantalla(FONDO_PANTALLA);
	Sprite Imagen_Boton(BOTON boton);
	Sprite getImage(String, float, float, float = 80, float = 40, bool = true);
	void setX(int x);
private:
	Sprite* sprite_base;
	Texture* texture_base;
	int x = 300;
};

