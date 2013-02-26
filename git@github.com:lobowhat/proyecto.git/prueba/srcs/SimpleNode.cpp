/*
 * SNode.cpp
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#include "SimpleNode.h"


SimpleNode::SimpleNode(const int& pData, SimpleNode* pNextNode = NULL) {
	this->_data = pData;
	this->_next = pNextNode;
}


SimpleNode::SimpleNode(SimpleNode* pNextNode = NULL) {
	this->_data = 0;
	this->_next = pNextNode;
}


SimpleNode::~SimpleNode() {
}


void SimpleNode::setNext(SimpleNode* pNode) {
	this->_next = pNode;
}


SimpleNode * SimpleNode::getNext() {
	return this->_next;
}


int SimpleNode::getData() {
	return this->_data;
}
