/*
 * Random.cpp
 *
 *  Created on: 08/03/2013
 *      Author: jose
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int * getRandomPos(int minWidth, int maxWidth, int minHeight, int maxHeight);

int main(int argc, char **argv) {
	int * tmp;
	tmp = getRandomPos(15, 24, 8, 12);
	cout << tmp[0] << endl;
	cout << tmp[1] << endl;

	return 0;
}

int *getRandomPos(int minWidth, int maxWidth, int minHeight, int maxHeight) {
	srand(time(NULL));
	int * tmp = (int*) malloc(sizeof(int) * 2);
	int tmpX = minWidth + (rand() % (maxWidth - minWidth));
	int tmpY = minHeight + (rand() % (maxHeight - minHeight));
	tmp[0] = tmpX;
	tmp[1] = tmpY;
	return tmp;
}
