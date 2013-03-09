/*
 * ListQueue.cpp
 *
 *  Created on: 09/03/2013
 *      Author: jose
 */

#include "ListQueue.h"

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
E ListQueue<E>::dequeue() {
	if (this->_size == 0) {
		std::cout << "Queue is empty" << std::endl;
		return 0;
	}
	E data = this->_top->getData();
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

