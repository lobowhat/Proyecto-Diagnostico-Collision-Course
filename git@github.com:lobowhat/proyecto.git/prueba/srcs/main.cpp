/*
 * main.cpp
 *
 *  Created on: 25/02/2013
 *      Author: jose
 */

#include <iostream>
#include <unistd.h>
#include "DoubleCircularList.h"
#include "ListQueue.h"

using namespace std;


int main(int argc, char **argv) {
	DoubleCircularList<int> * list = new DoubleCircularList<int>();
	list->insert(81);
	list->insert(99);
	list->insert(74);
	list->insert(39);
	list->insert(57);
	cout << "El tamaño actual es: ";
	cout << list->length() << endl;
	cout << "Dato eliminado: ";
	cout << list->deleteNode(99) << endl;
	cout << "El tamaño actual es: ";
	cout << list->length() << endl;

	usleep(100000);

	ListQueue<char>* queue = new ListQueue<char>();
	queue->enqueue('e');
	queue->enqueue('r');
	queue->enqueue('o');
	queue->enqueue('v');
	cout << "El tamaño actual es: ";
	cout << queue->length() << endl;
	cout << "Dato eliminado: ";
	cout << (char)queue->dequeue() << endl;
	cout << "El tamaño actual es: ";
	cout << queue->length() << endl;
	return 0;
}
