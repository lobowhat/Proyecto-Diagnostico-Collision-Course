/*
 * SNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef SNODE_H_
#define SNODE_H_
#include <iostream>

class SimpleNode {
private:
	int _data;
	// Valor del nodo.
	SimpleNode *_next;
	// Puntero al nodo siguiente.
public:
	SimpleNode(const int& pData, SimpleNode* pNextNode);
	SimpleNode(SimpleNode* pNextNode);
	virtual ~SimpleNode();
	void setNext(SimpleNode* pNode);
	SimpleNode * getNext();
	int getData();
};

#endif /* SNODE_H_ */
