/*
 * DCL.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef DCL_H_
#define DCL_H_

#include "DoubleNode.h"
#include "ListADT.h"
#include <iostream>

template<typename E>
class DoubleCircularList:public ListADT<E> {
private:
	DoubleNode<E>* _head; //Puntero al nodo inicial
	DoubleNode<E>* _tail; //Puntero al nodo final
	int _size;
public:
	DoubleCircularList();
	virtual ~DoubleCircularList();
	void insert(const E& pData);
	void insertInOrder(const E& pData);
	E deleteNode(const E& pData);
	int length() const;
};

#endif /* DCL_H_ */
