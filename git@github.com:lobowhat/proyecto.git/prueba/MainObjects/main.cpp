/*
 * main.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "GUI.h"
#include "DoubleCircularList.h"
#include <iostream>
//#include "Thread.h"

using namespace std;


int main(int argc, char **argv) {
	GUI* main = new GUI();
	main->start();
	return 0;
}
