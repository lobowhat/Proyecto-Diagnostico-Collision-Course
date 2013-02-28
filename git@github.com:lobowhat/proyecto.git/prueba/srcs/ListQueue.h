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
	int dequeue();
	int length() const;
};

#endif /* LISTQUEUE_H_ */

template<typename E>
ListQueue<E>::ListQueue() {
	this->_top = this->_tail = NULL;
	this->_size = 0;
}

template<typename E>
ListQueue<E>::~ListQueue() {
	clear();
	delete this->_top;
}

template<typename E>
void ListQueue<E>::clear() { // Limpia la cola
	while (this->_top->getNext() != NULL) { // Elimina todos los nodos.
		this->_tail = this->_top;
		delete this->_tail;
	}
	this->_tail = this->_top;
	this->_size = 0;
}

template<typename E>
void ListQueue<E>::enqueue(const E& pData) {
	SimpleNode<E> * nNode = new SimpleNode<E>(pData, NULL);
	if (this->_top == NULL) {
		this->_top = this->_tail = nNode;
		this->_size++;
	} else {
		_tail->setNext(nNode);
		_tail = nNode;
		this->_size++;
	}
}

template<typename E>
int ListQueue<E>::dequeue() {
	if (this->_size == 0) {
		std::cout << "Queue is empty" << std::endl;
		return 0;
	}
	int data = this->_top->getData();
	SimpleNode<E> * tmp = this->_top->getNext();
	this->_top = this->_top->getNext();
	if (this->_top == NULL) {
		this->_tail = this->_top; // Desencola
	}
	delete tmp; // Nodo eliminado
	this->_size--;
	return data; // Retorno del valor;
}

template<typename E>
int ListQueue<E>::length() const {
	return this->_size;
}

