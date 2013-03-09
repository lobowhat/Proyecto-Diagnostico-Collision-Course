/*
 * main.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "Player.h"
#include "Parser.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv) {
	Player* player = new Player();
	cout << "Score: " << player->getScore() << endl;
	cout << "Speed: " << player->getHighSpeed() << endl;
	cout << "High Track: " << player->getHighTrack() << endl;
	cout << "Invincible: " << player->getInvincible() << endl;
	cout << "Medium Track: " << player->getMediumTrack() << endl;
	cout << "High Traction: " << player->getHighTraction() << endl;
	return 0;
}

