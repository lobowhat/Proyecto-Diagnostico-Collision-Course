/*
 * GUI.h
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#ifndef GUI_H_
#define GUI_H_

#include <pthread.h>
#include <ncurses.h>
#include <unistd.h>
#include "Player.h"
#include "TrackPos.h"
#include "ListQueue.h"
#include "Matrix.h"

class GUI {
private:
	Player* player_1;
	Player* player_2;
	Matrix* mainmatrix;
	pthread_t _clock, _movement, _trackPlayer1, _trackPayer2, _update,_controlMatrix, _surpriseThread; //Hilos de ejecución
	int sec; // Segundos de ejecución
	int maxHeight, maxWidth; // Tamaños maximos de la ventana
	int currentX_P1, currentY_P1, currentX_P2, currentY_P2; // Variables enteras que representan posiciones.
	char wallChar, direction_P1, direction_P2, charPlayer_1, charPlayer_2; // Variables que almacenan los caracteres que representan a los distintos objetos.
	char _surprises, _surprise_2; // Los caracteres que representan las sorpresas
	char _highZones, _bump; // Caracteres que representan las zonas altas y baches.
	int _player1;
	int _player2;
	int _EM;
	int _EA;
	int _TA;
	int _VA;
	int _BA;
	int _TERR;
	int _INVE;

public:
	GUI(); // Constructor
	virtual ~GUI(); // Destructor
	static void* movement(void* obj); // Funcion ejecutora del hilo de movimiento
	static void* crono(void* obj); // Funcion ejecutora del hilo del cronometro
	static void* updateScores(void*);
	static void* Controlall(void*);
	static void* putSurprise(void*);
	void surpriseGraphic();
	void updateHabilities();
	void moveAndActiveKeyPad(); // Funcion del movimiento
	void functionCronometer();//Funcion del cronometro
	void funtionMatrix();
	bool collision(); //Verificador de colisiones con paredes
	void boxDraw(int beginX, int beginY, int maxX, int maxY, char pChar); //Dibuja un borde con un caracter determinado
	void initColor(); //Inicializa los colores a usarse
	void initPosGamers(); //Inicializa las posiciones de los jugadores
	void gameOver();
	void gameManual(); // Dibuja los Manuales
	void start(); // Inicia la ejecucion
	void drawBumps(int x, int y); // Dibuja los baches
	void drawSurprises(int x, int y, int color); // Dibuja las sorpresas
	void drawHighZones(int x, int y); // Dibuja las zonas altas
};

#endif /* GUI_H_ */
