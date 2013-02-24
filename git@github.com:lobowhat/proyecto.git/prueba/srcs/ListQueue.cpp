/*
 * ListQueue.cpp
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#include "ListQueue.h"

template<typename E>
ListQueue<E>::ListQueue() {
	this->_top = this->_tail = new SimpleNode<E>();
	this->_size = 0;
}
template<typename E>
ListQueue<E>::~ListQueue() {
	clear();
	delete this->_top;
}
template<typename E>
void ListQueue<E>::clear() { // Clear queue
	while (this->_top->getNext() != NULL) { // Elimina todos los nodos.
		this->_tail = this->_top;
		delete this->_tail;
	}
	this->_tail = this->_top;
	this->_size = 0;
}

template<typename E>
void ListQueue<E>::enqueue(const E& pData) {
	this->_tail->setNext(new SimpleNode<E>(pData, NULL));
	this->_tail = this->_tail->getNext();
	this->_size++;
}

template<typename E>
E ListQueue<E>::dequeue() {
	if (this->_size == 0) {
		std::cout << "Queue is empty" << std::endl;
	}
	E data = this->_top->getNext()->getData();
	SimpleNode<E> *ltemp = this->_top->getNext();
	this->_top->setNext(ltemp->getNext()); // Avanza al top
	if (this->_tail == ltemp)
		this->_tail = this->_top; // Desencola
	delete ltemp; // Nodo eliminado
	this->_size--;
	return data; // Retorno del valor;
}

template<typename E>
int ListQueue<E>::length() const {
	return this->_size;
}
