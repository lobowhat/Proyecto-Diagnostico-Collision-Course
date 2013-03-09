/*
 * SNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef SNODE_H_
#define SNODE_H_
#include <iostream>

template<typename E>
class SimpleNode {
private:
	E _data;
	// Valor del nodo.
	SimpleNode *_next;
	// Puntero al nodo siguiente.
public:
	SimpleNode(const E& pData, SimpleNode* pNextNode);
	SimpleNode(SimpleNode* pNextNode);
	virtual ~SimpleNode();
	void setNext(SimpleNode* pNode);
	SimpleNode * getNext();
	E getData();
};

#endif /* SNODE_H_ */


template<typename E>
SimpleNode<E>::SimpleNode(const E& pData, SimpleNode* pNextNode = NULL) {
	this->_data = pData;
	this->_next = pNextNode;
}


template<typename E>
SimpleNode<E>::SimpleNode(SimpleNode* pNextNode = NULL) {
	this->_data = 0;
	this->_next = pNextNode;
}

template<typename E>
SimpleNode<E>::~SimpleNode() {
}

template<typename E>
void SimpleNode<E>::setNext(SimpleNode* pNode) {
	this->_next = pNode;
}

template<typename E>
SimpleNode<E> * SimpleNode<E>::getNext() {
	return this->_next;
}

template<typename E>
E SimpleNode<E>::getData() {
	return this->_data;
}
