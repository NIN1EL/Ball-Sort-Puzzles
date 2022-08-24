#include "Utiles.h"

string Utiles::getImageToColor(COLOR color)
{
	string name;
	switch (color)
	{
	case COLOR::pink:
		name = "Recursos/pink.png";
		break;
	case COLOR::blue:
		name = "Recursos/blue.png";
		break;
	case COLOR::green:
		name = "Recursos/green.png";
		break;
	case COLOR::red:
		name = "Recursos/red.png";
		break;
	case COLOR::yellow:
		name = "Recursos/yellow.png";
		break;
	case COLOR::white:
		name = "Recursos/white.png";
		break;
	case COLOR::brown:
		name = "Recursos/brown.png";
		break;
	default:
		name = "Recursos/error.png";
		break;
	}
	return name;
}

string Utiles::getImage()
{
	return "Recursos/COHETE 6.png";
}

String Utiles::getFondoPantalla(FONDO_PANTALLA fondo)
{
	string image;
	switch (fondo)
	{
	case inicio: image = "Recursos/Fondo de pantalla.jpg"; break;
	case metalico: image = "Recursos/fondo metalico.JPG"; break;
	case acercaDe: image = "Recursos/Fondo de pantalla Acerca de.jpg"; break;
	case repeticion: image = "Recursos/fondo repeticion.jpg"; break;
	case gano: image = "Recursos/Fondo Gano.jpg"; break;
	case guardar: image = "Recursos/fondo Guardar.jpg"; break;
	default: image = "Recursos/font.jpeg"; break;
	}
	return image;
}

String Utiles::getImageMetalica()
{
	return "Recursos/fondo metalico.JPG";
}

String Utiles::getImageBoton(BOTON boton) {
	string image;
	switch (boton)
	{
		case jugar: image = "Recursos/Jugar.png"; break;
		case niveles: image = "Recursos/Niveles.png"; break;
		case salir: image = "Recursos/Salir.png"; break;
		case nueva_partida: image = "Recursos/Nueva partida.png"; break;
		case anterior: image = "Recursos/anterior.png"; break;
	    case check: image = "Recursos/comprobado.png"; break;
		case btnGuardar: image = "Recursos/Guardar.png"; break;
		case reiniciar: image = "Recursos/reiniciar.png"; break;
		case botonX: image = "Recursos/cerrar.png"; break;
		case nivel1 : image = "Recursos/uno.png"; break;
		case nivel2: image = "Recursos/dos.png"; break;
		case nivel3: image = "Recursos/tres.png"; break;
		case nivel4: image = "Recursos/cuatro.png"; break;
		case nivel5: image = "Recursos/cinco.png"; break;
		case bloqueado: image = "Recursos/bloquear.png"; break;
		default: image = "Recursos/Acerca de.png"; break;
	}
	return image;
}
