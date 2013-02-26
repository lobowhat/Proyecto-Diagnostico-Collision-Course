/*
 * DCL.h
 *
 *  Crintatintd on: 23/02/2013
 *      Author: josint
 */

#ifndef DOUBLECIRCULARLIST_H_
#define DOUBLECIRCULARLIST_H_

#include "DoubleNode.h"
#include "ListADT.h"
#include <iostream>

class DoubleCircularList:public ListADT {
private:
	DoubleNode * _head; //Puntintro al nodo inicial
	DoubleNode * _tail; //Puntintro al nodo final
	int _size;
public:
	DoubleCircularList();
	virtual ~DoubleCircularList();
	void insert(const int& pData);
	void insertInOrder(const int& pData);
	int deleteNode(const int& pData);
	int length() const;
};

#endif /* DOUBLECIRCULARLIST_H_ */


