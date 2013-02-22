/*
 * DNode.h
 *
 *  Created on: 20/02/2013
 *      Author: jose
 */

#ifndef DNODE_H_
#define DNODE_H_
#include <iostream>

template<typename E> class DNode {
private:
	E _data;
	// Valor del nodo
	DNode *_next;
	// Puntero al nodo anterior
	DNode *_previous;
	//Puntero al nodo anterior

public:
	// Constructors
	DNode(const E& pData, DNode* pNextNode = NULL, DNode* pPreviosNode = NULL) {
		this->_data = pData;
		this->_next = pNextNode;
		this->_previous = pPreviosNode;

	}

	DNode(DNode* pNextNode = NULL, DNode* pPreviousNode = NULL) {
		this->_next = pNextNode;
		this->_previous = pPreviousNode;
	}

	DNode<E>* getNext() {
		return this->_next;
	}

	DNode<E>* getPrevious() {
		return this->_previous;
	}

	void setNext(DNode<E>* pNode) {
		this->_next = pNode;
	}

	void setPrevious(DNode<E>* pNode) {
		this->_previous = pNode;
	}

	E getData(){
		return this->_data;
	}
};

#endif /* DNODE_H_ */
