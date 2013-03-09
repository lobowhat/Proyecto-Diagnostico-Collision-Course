/*
 * TrackPos.h
 *
 *  Created on: 08/03/2013
 *      Author: jose
 */

#ifndef TRACKPOS_H_
#define TRACKPOS_H_

class TrackPos {

private:
	int _posX;
	int _posY;

public:
	TrackPos(int X, int Y);
	TrackPos();
	virtual ~TrackPos();
	int getPosX();
	int getPosY();
	void setPosX(int posX);
	void setPosY(int posY);
};

#endif /* TRACKPOS_H_ */
