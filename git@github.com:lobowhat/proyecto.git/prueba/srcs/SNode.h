/*
 * SNode.h
 *
 *  Created on: 20/02/2013
 *      Author: jose
 */

#ifndef SNODE_H_
#define SNODE_H_
#include <iostream>

template<typename E> class SNode {
private:
	E _data;
	// Valor del nodo.
	SNode *_next;
	// Puntero al nodo siguiente.
public:
	// Constructores
	SNode(const E& pData, SNode* pNextNode = NULL) {
		_data = pData;
		_next = pNextNode;
	}

	SNode(SNode* pNextNode = NULL) {
		_next = pNextNode;
	}


	void setNext(SNode* pNode){
		this->_next = pNode;
	}

	SNode<E>* getNext(){
		return this->_next;
	}

	E getData(){
		return this->_data;
	}
};

#endif /* SNODE_H_ */
