/*
 * ListQueue.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_
#include "Queue.h"
#include "SimpleNode.h"
#include <iostream>

template<typename E>
class ListQueue: public Queue<E> {
private:
	SimpleNode<E> * _top; // Puntero al primer nodo.

	SimpleNode<E> * _tail; // Puntero al ultimo nodo.

	int _size; // Numero de elementos en la cola.
public:
	ListQueue();
	virtual ~ListQueue();
	void clear();
	void enqueue(const E& pData);
	E dequeue();
	int length() const;
};

#endif /* LISTQUEUE_H_ */
