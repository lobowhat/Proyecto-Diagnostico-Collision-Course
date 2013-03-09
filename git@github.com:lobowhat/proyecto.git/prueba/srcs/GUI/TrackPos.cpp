/*
 * TrackPos.cpp
 *
 *  Created on: 08/03/2013
 *      Author: jose
 */

#include "TrackPos.h"
#include <iostream>

using namespace std;

TrackPos::TrackPos(int X, int Y) {
	this->_posX = X;
	this->_posY = Y;
}

TrackPos::TrackPos() {
	this->_posX = 0;
	this->_posY = 0;
}

TrackPos::~TrackPos() {
}

int TrackPos::getPosX() {
	return this->_posX;
}

int TrackPos::getPosY() {
	return this->_posY;
}

void TrackPos::setPosX(int posX) {
	_posX = posX;
}

void TrackPos::setPosY(int posY) {
	_posY = posY;
}
