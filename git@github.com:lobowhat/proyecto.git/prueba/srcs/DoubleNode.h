/*
 * DNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef DNODE_H_
#define DNODE_H_
#include <iostream>

template<typename E>
class DoubleNode {
private:
	E _data;
	// Valor del nodo
	DoubleNode<E> *_next;
	// Puntero al nodo anterior
	DoubleNode<E> *_previous;
	//Puntero al nodo anterior
public:
	DoubleNode(const E& pData, DoubleNode* pNextNode = NULL, DoubleNode* pPreviosNode = NULL);
	DoubleNode(DoubleNode* pNextNode = NULL, DoubleNode* pPreviousNode = NULL);
	virtual ~DoubleNode();
	DoubleNode<E> * getNext();
	DoubleNode<E> * getPrevious();
	void setNext(DoubleNode<E>* pNode);
	void setPrevious(DoubleNode<E>* pNode);
	E getData();
};

#endif /* DNODE_H_ */



template<typename E>
DoubleNode<E>::DoubleNode(const E& pData, DoubleNode* pNextNode, DoubleNode* pPreviosNode) {
	this->_data = pData;
	this->_next = pNextNode;
	this->_previous = pPreviosNode;
}

template<typename E>
DoubleNode<E>::DoubleNode(DoubleNode* pNextNode, DoubleNode* pPreviousNode) {
	this->_data = 0;
	this->_next = pNextNode;
	this->_previous = pPreviousNode;
}

template<typename E>
DoubleNode<E>::~DoubleNode() {
}

template<typename E>
DoubleNode<E> * DoubleNode<E>::getNext() {
	return this->_next;
}

template<typename E>
DoubleNode<E> * DoubleNode<E>::getPrevious() {
	return this->_previous;
}

template<typename E>
void DoubleNode<E>::setNext(DoubleNode* pNode) {
	this->_next = pNode;
}

template<typename E>
void DoubleNode<E>::setPrevious(DoubleNode* pNode) {
	this->_previous = pNode;
}

template<typename E>
E DoubleNode<E>::getData() {
	return this->_data;
}

