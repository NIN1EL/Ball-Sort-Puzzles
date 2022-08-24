#include "Imagen.h"

Imagen::Imagen() {
	textura = new Texture;
	sprite = new Sprite;
}
void Imagen::CargarImagen(string direccion,int x, int y) {
	textura->loadFromFile(direccion);
	sprite->setTexture(*textura);
	sprite->setPosition(x,y);
	sprite->setPosition(sprite->getTexture()->getSize().x / 2.f, sprite->getTexture()->getSize().y / 2.f);
}
Sprite* Imagen::getSprite() {
	return sprite;
}
