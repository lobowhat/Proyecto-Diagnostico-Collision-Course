/*
 * ListQueue.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_
#include "Queue.h"
#include "SimpleNode.h"
#include <iostream>

class ListQueue:public Queue {
private:
	SimpleNode * _top; // Pointer to front queue node

	SimpleNode * _tail; // Pointer to rear queue node

	int _size; // Number of elements in queue
public:
	ListQueue();
	virtual ~ListQueue();
	void clear();
	void enqueue(const int& pData);
	int dequeue();
	int length() const;
};

#endif /* LISTQUEUE_H_ */
