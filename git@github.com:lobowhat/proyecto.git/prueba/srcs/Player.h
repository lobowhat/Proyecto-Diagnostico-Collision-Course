/*
 * Player.h
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#ifndef PLAYER_H_
#define PLAYER_H_

/**
 * Clase jugador
 */
class Player {

private:
	int score; // Puntuacion del jugador
	int highSpeed; // Segundos de velocidad alta
	int highTraction; // Segundos de tracción alta
	int highTrack; // Segundos de estela alta
	int mediumTrack; // Segundos de estela media
	int invincible; // Segundos de invencibilidad
	bool destroy; // Booleano si chocó para reiniciar
	int posX, posY; // Posición x y del jugador
	bool reset; //Verifica si chocó y tiene que reiniciar para dar 5 segundos para recuperarse.

public:
	Player(); // Constructor de la clase
	virtual ~Player(); // Destructor de la clase
	/*
	 * Establece el valor del puntaje
	 */
	void setScore(int pScore);
	/*
	 * Establece el valor de los segundos en tracción alta
	 */
	void setHighTraction(int pTraction);
	/*
	 * Establece el valor de los segundos en velocidad alta
	 */
	void setHighSpeed(int pSpeed);
	/*
	 * Establece el valor de los segundos en estela media
	 */
	void setMediumTrack(int pTrack);
	/*
	 * Establece el valor de los segundos en estela alta
	 */
	void setHighTrack(int pTrack);
	/*
	 * Establece el valor de los segundos en invencible
	 */
	void setInvincible(int pInv);
	/*
	 * Establece el valor de la posicion X del jugador
	 */
	void setPosX(int pPos);
	/*
	 * Establece el valor de la posicion Y del jugador
	 */
	void setPosY(int pPos);
	/*
	 * Se obtiene el puntaje del jugador
	 */
	int getScore() const;
	/*
	 * Se obtienen los segundos de traccion alta
	 */
	int getHighTraction() const;
	/*
	 * Se obtienen los segundos de velocidad alta
	 */
	int getHighSpeed() const;
	/*
	 * Se obtienen los segundos de la estela media
	 */
	int getMediumTrack() const;
	/*
	 * Se obtienen los segundos de la estela alta
	 */
	int getHighTrack() const;
	/*
	 * Se obtienen los segundos de invencible
	 */
	int getInvincible() const;
	/*
	 * Se obtienen la posicion X del jugador
	 */
	int getPosX() const;
	/*
	 * Se obtienen la posicion Y del jugador
	 */
	int getPosY() const;
	/*
	 * Se obtienen un valor booleano indicando se fue destruido el jugador
	 */
	bool playerDestroy() const;
	/*
	 * Se obtienen un valor booleano indicando si posee segundos de tracción alta
	 */
	bool HighTraction() const;
	/*
	 * Se obtienen un valor booleano indicando si posee segundos de invencible
	 */
	bool Invincible() const;
	/*
	 * Se obtienen un valor booleano indicando si posee segundos de velocidad alta
	 */
	bool HighSpeed() const;
	/*
	 * Se obtienen un valor booleano indicando si posee segundos de estela media
	 */
	bool MediumTrack() const;
	/*
	 * Se obtienen un valor booleano indicando si posee segundos de estela alta
	 */
	bool HighTrack() const;
	/*
	 * Se obtienen un valor booleano indicando si el jugador esta en recuperacion
	 */
	bool resetPlayer() const;
	/*
	 * Se obtienen un valor entero de la posicion X aleatoria para reiniciar al jugador
	 */
	int resetPosX() const;
	/*
	 * Se obtienen un valor entero de la posicion Y aleatoria para reiniciar al jugador
	 */
	int resetPosY() const;

};

#endif /* PLAYER_H_ */
