/*
 * main.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "Player.h"
#include "Parser.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	GetConfig * parser = new GetConfig();
	string file = "Configure.xml";
	parser->readConfigFile(file);
	cout << parser->getInvincible();
	return 0;
}

