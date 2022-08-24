#pragma once
#include "Nivel.h"
#include "Imagenes.h"
#include "Archivos.h"
#include "Objeto_Grafico.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
using namespace sf;
using namespace std;
class Juego
{
public:
	Juego(int dimencion_x, int dimencion_y, string titulo);
	void Dibujar(int opcion, bool nuevo );
	void VentanaCargar();
	void VentanaInicio();
	void VentanaNiveles();
	void VentanaAcercaDe();
	void VentanaRep();
	void VentanaGano();
	void CargarNivel();
	void Refrescar(int controlador_ventana, bool nuevo);
	void ProcesarMouse(int);
	void controladorMouseVentanaRep();
	void controladorMouseVentanaAcercaDe();
	void controladorMouseVentanaNivel();
	void CordenadasMouse();
	void cargarTubos();
	void nuevo_nivel(bool rep);
	void controladorMouseVentanaInicio();
	void controladorMouseVentanaCargarPartida();
	void controladorMouseVentanaNiveles();
	void controladorMouseVentanaGano();
	void tuboRange();
	void agregar_movimientos(Movimiento*);
	bool gano();
	void movimientoAutomatico(Tubo* origen, Tubo* Destino, bool dibujar);
	void controladorMousePause();
	void repeticion();

	void retroceder();

private:
	DoubleList<Movimiento*>* lista_movimientos;
	DoubleList<Movimiento*>* movimientos_rep;
	RenderWindow* ventana1;
	bool hubo_movimiento;
	Vector2i cordenadas;
	Bola* bola_a_mover;
	Imagenes* imagenes;
	Event* evento;
	Nivel *nivel;
	Iterator<Tubo*>* ite;
	Archivos* arc;
	Nivel nivelAux;
	int nivelesDesbloqueados;
	int movimientosRealizados;
};


