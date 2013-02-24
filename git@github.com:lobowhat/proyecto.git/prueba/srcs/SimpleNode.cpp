/*
 * SNode.cpp
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#include "SimpleNode.h"

template<typename E>
SimpleNode<E>::SimpleNode(const E& pData, SimpleNode* pNextNode = NULL) {
	_data = pData;
	_next = pNextNode;
}

template<typename E>
SimpleNode<E>::SimpleNode(SimpleNode* pNextNode = NULL) {
	_next = pNextNode;
}

template<typename E>
SimpleNode<E>::~SimpleNode() {
}

template<typename E>
void SimpleNode<E>::setNext(SimpleNode* pNode){
	this->_next = pNode;
}

template<typename E>
SimpleNode<E> * SimpleNode<E>::getNext(){
	return this->_next;
}

template<typename E>
E SimpleNode<E>::getData(){
	return this->_data;
}
