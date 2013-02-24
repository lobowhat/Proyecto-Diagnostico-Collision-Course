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

template<typename E>
class ListQueue:public Queue<E> {
private:
	SimpleNode<E>* _top; // Pointer to front queue node

	SimpleNode<E>* _tail; // Pointer to rear queue node

	int _size; // Number of elements in queue
public:
	ListQueue();
	virtual ~ListQueue();
	void clear();
	void enqueue(const E& pData);
	E dequeue();
	int length() const;
};

#endif /* LISTQUEUE_H_ */
