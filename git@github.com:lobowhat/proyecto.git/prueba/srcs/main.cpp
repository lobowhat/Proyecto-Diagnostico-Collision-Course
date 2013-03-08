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
	cout << player->getScore();
	return 0;
}

