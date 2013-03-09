/*
 * main.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "GUI.h"
#include "ListQueue.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv) {
	GUI* main = new GUI();
	main->randomBumpPos();
	main->randomZonesPos();
	main->start();
	return 0;
}
