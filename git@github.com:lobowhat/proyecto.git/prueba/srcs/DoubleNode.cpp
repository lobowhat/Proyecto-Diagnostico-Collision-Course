/*
 * DNode.cpp
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#include "DoubleNode.h"

template<typename E>
DoubleNode<E>::DoubleNode(const E& pData, DoubleNode* pNextNode, DoubleNode* pPreviosNode) {
	this->_data = pData;
	this->_next = pNextNode;
	this->_previous = pPreviosNode;
}

template<typename E>
DoubleNode<E>::DoubleNode(DoubleNode* pNextNode, DoubleNode* pPreviousNode) {
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

