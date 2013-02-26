/*
 * Queue.h
 *
 *  Created on: 14/02/2013
 *      Author: jose
 */

#ifndef QUEUE_H_
#define QUEUE_H_

// Abstract queue class
class Queue {

public:
	Queue() {
	}// Default

	virtual ~Queue() {
	} // Base destructor

	// Reinitialize the queue. The user is responsible for
	// reclaiming the storage used by the queue elements.
	virtual void clear() = 0;

	// Place an element at the rear of the queue.
	// it: The element being enqueued.
	virtual void enqueue(const int&) = 0;

	// Remove and return element at the front of the queue.
	// Return: The element at the front of the queue.
	virtual int dequeue() = 0;

	// Return: The number of elements in the queue.
	virtual int length() const = 0;
};
#endif /* QUEUE_H_ */
