/*
 * DNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef DNODE_H_
#define DNODE_H_
#include <iostream>

class DoubleNode {
private:
	int _data;
	// Valor del nodo
	DoubleNode *_next;
	// Puntero al nodo anterior
	DoubleNode *_previous;
	//Puntero al nodo anterior
public:
	DoubleNode(const int& pData, DoubleNode* pNextNode = NULL, DoubleNode* pPreviosNode = NULL);
	DoubleNode(DoubleNode* pNextNode = NULL, DoubleNode* pPreviousNode = NULL);
	virtual ~DoubleNode();
	DoubleNode * getNext();
	DoubleNode * getPrevious();
	void setNext(DoubleNode* pNode);
	void setPrevious(DoubleNode* pNode);
	int getData();
};

#endif /* DNODE_H_ */
