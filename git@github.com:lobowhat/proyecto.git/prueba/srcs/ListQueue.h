/*
 * ListQueue.h
 *
 *  Created on: 20/02/2013
 *      Author: jose
 */

#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_
#include "Queue.h"
#include "SNode.h"

// SNodeed queue implementation
template<typename E> class ListQueue: public Queue<E> {

private:
	SNode<E>* _top; // Pointer to front queue node

	SNode<E>* _tail; // Pointer to rear queue node

	int _size; // Number of elements in queue

public:
	ListQueue() { // Constructor
		this->_top = this->_tail = new SNode<E>();
		this->_size = 0;
	}

	virtual ~ListQueue() {
		clear();
		delete this->_top;
	}// Destructor

	void clear() { // Clear queue
		while (this->_top->getNext() != NULL) { // Elimina todos los nodos.
			this->_tail = this->_top;
			delete this->_tail;
		}
		this->_tail = this->_top;
		this->_size = 0;
	}

	void enqueue(const E& it) { // Pone el elemento al final de la cola.
		this->_tail->setNext(new SNode<E>(it, NULL));
		this->_tail = this->_tail->getNext();
		this->_size++;
	}

	E dequeue() { // Elimina el elemento del inicio.
		if (this->_size == 0){
			std::cout << "Queue is empty" << std::endl;
		}
		E data = this->_top->getNext()->getData();
		SNode<E> *ltemp = this->_top->getNext();
		this->_top->setNext(ltemp->getNext()); // Avanza al top
		if (this->_tail == ltemp)
			this->_tail = this->_top; // Desencola
		delete ltemp; // Nodo eliminado
		this->_size--;
		return data; // Retorno del valor;
	}

	virtual int length() const {
		return this->_size;
	}
};

#endif /* LISTQUEUE_H_ */
