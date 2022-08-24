#include "Imagenes.h"

Imagenes::Imagenes()
{
	this->texture_base = new Texture;
	Sprite* sprite_base = new Sprite;
}

Sprite Imagenes::Imagen_Fondo_Pantalla(FONDO_PANTALLA fondo)
{
	Sprite sprite;
	switch (fondo)
	{
	case inicio: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::inicio), VENTANA::x, VENTANA::y, 1400, 600, false); break;
	case metalico: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::metalico), 1270, 0, 200, 600, false); break;
	case acercaDe: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::acercaDe), VENTANA::x, VENTANA::y, 1400, 600, false); break;
	case repeticion: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::repeticion), VENTANA::x, VENTANA::y, 1400, 600, false); break;
	case gano: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::gano), VENTANA::x, VENTANA::y, 1400, 600, false); break;
	case guardar: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::guardar), VENTANA::x, VENTANA::y, 1400, 600, false); break;
	default: sprite = getImage(Utiles::getFondoPantalla(FONDO_PANTALLA::juego), VENTANA::x, VENTANA::y, 1400, 600, false); break;
	}
	return sprite;
}

Sprite Imagenes::Imagen_Boton(BOTON boton)
{
	Sprite sprite;
	switch (boton)
	{
		case jugar: sprite = getImage(Utiles::getImageBoton(BOTON::jugar), 700, 300,100, 94,true); break;
		case niveles: sprite = getImage(Utiles::getImageBoton(BOTON::niveles), 400, 400, 100, 94, true); break;
		case salir: sprite = getImage(Utiles::getImageBoton(BOTON::salir), 1340, 550, 100, 94, true); break;
		case nueva_partida: sprite = getImage(Utiles::getImageBoton(BOTON::nueva_partida), 1000, 400, 100, 94, true); break;
		case anterior: sprite = getImage(Utiles::getImageBoton(BOTON::anterior), 1340, 50, 100, 94, true); break;
		case check: sprite = getImage(Utiles::getImageBoton(BOTON::check), 400, 400, 100, 94, true); break;
		case btnGuardar:sprite = getImage(Utiles::getImageBoton(BOTON::btnGuardar), 1340, 180, 100, 94, true); break;
		case reiniciar:sprite = getImage(Utiles::getImageBoton(BOTON::reiniciar), 1340, 310, 100, 94, true); break;
		case botonX: sprite = getImage(Utiles::getImageBoton(BOTON::botonX), 1000, 400, 100, 94, true); break;
		case nivel1: sprite = getImage(Utiles::getImageBoton(BOTON::nivel1), x, 320, 100, 94, true);  x += 150; break;
		case nivel2: sprite = getImage(Utiles::getImageBoton(BOTON::nivel2), x, 320, 100, 94, true);  x += 150; break;
		case nivel3: sprite = getImage(Utiles::getImageBoton(BOTON::nivel3), x, 320, 100, 94, true);  x += 150; break;
		case nivel4: sprite = getImage(Utiles::getImageBoton(BOTON::nivel4), x, 320, 100, 94, true);  x += 150; break;
		case nivel5: sprite = getImage(Utiles::getImageBoton(BOTON::nivel5), x, 320, 100, 94, true);  x += 150; break;
		case bloqueado: sprite = getImage(Utiles::getImageBoton(BOTON::bloqueado), x, 320, 100, 94, true); x += 150; break;
		default: sprite = getImage(Utiles::getImageBoton(BOTON::acerca_de), 50, 550,100, 94, true); break;
	}
	return sprite;
}

Sprite Imagenes::getImage(String url, float x, float y, float scale_x, float scale_y, bool origin)
{
	sprite_base = new Sprite;
	texture_base->loadFromFile(url);
	texture_base->isSmooth();
	sprite_base->setTexture(*texture_base);
	sprite_base->setPosition(x, y);
	if (origin) {
		sprite_base->setOrigin(sprite_base->getTexture()->getSize().x / 2.f, sprite_base->getTexture()->getSize().y / 2.f);
	}
	sprite_base->setScale((float)scale_x / (float)sprite_base->getTexture()->getSize().x, (float)scale_y / (float)sprite_base->getTexture()->getSize().y );
	return *sprite_base;
}

void Imagenes::setX(int x)
{
	this->x = x;
}
