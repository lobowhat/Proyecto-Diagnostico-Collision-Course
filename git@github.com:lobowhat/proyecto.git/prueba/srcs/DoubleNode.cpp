/*
 * DNode.cpp
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#include "DoubleNode.h"


DoubleNode::DoubleNode(const int& pData, DoubleNode* pNextNode, DoubleNode* pPreviosNode) {
	this->_data = pData;
	this->_next = pNextNode;
	this->_previous = pPreviosNode;
}

DoubleNode::DoubleNode(DoubleNode* pNextNode, DoubleNode* pPreviousNode) {
	this->_data = 0;
	this->_next = pNextNode;
	this->_previous = pPreviousNode;
}

DoubleNode::~DoubleNode() {
}

DoubleNode * DoubleNode::getNext() {
	return this->_next;
}

DoubleNode * DoubleNode::getPrevious() {
	return this->_previous;
}

void DoubleNode::setNext(DoubleNode* pNode) {
	this->_next = pNode;
}

void DoubleNode::setPrevious(DoubleNode* pNode) {
	this->_previous = pNode;
}


int DoubleNode::getData() {
	return this->_data;
}

