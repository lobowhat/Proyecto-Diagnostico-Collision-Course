/*
 * ListQueue.cpp
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#include "ListQueue.h"

ListQueue::ListQueue() {
	this->_top = this->_tail = NULL;
	this->_size = 0;
}

ListQueue::~ListQueue() {
	clear();
	delete this->_top;
}

void ListQueue::clear() { // Limpia la cola
	while (this->_top->getNext() != NULL) { // Elimina todos los nodos.
		this->_tail = this->_top;
		delete this->_tail;
	}
	this->_tail = this->_top;
	this->_size = 0;
}

void ListQueue::enqueue(const int& pData) {
	SimpleNode * nNode = new SimpleNode(pData, NULL);
	if (this->_top == NULL) {
		this->_top = this->_tail = nNode;
		this->_size++;
	} else {
		_tail->setNext(nNode);
		_tail = nNode;
		this->_size++;
	}
}

int ListQueue::dequeue() {
	if (this->_size == 0) {
		std::cout << "Queue is empty" << std::endl;
		return 0;
	}
	int data = this->_top->getData();
	SimpleNode * tmp = this->_top->getNext();
	this->_top = this->_top->getNext();
	if (this->_top == NULL){
		this->_tail = this->_top; // Desencola
	}
	delete tmp; // Nodo eliminado
	this->_size--;
	return data; // Retorno del valor;
}

int ListQueue::length() const {
return this->_size;
}

