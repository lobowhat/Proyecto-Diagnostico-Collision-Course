/*
 * Random.cpp
 *
 *  Created on: 08/03/2013
 *      Author: jose
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int *getRandomPos(int minWidth, int maxWidth, int minHeight, int maxHeight);

int *getRandomPos(int minWidth, int maxWidth, int minHeight, int maxHeight) {
	srand(time(NULL));
	int * tmp = (int*) malloc(sizeof(int) * 2);
	int tmpX = minWidth + (rand() % (maxWidth - minWidth));
	int tmpY = minHeight + (rand() % (maxHeight - minHeight));
	tmp[0] = tmpX;
	tmp[1] = tmpY;
	return tmp;
}
