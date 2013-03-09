/*
 * Thread.h
 *
 *  Created on: 09/03/2013
 *      Author: jose
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class Thread {
private:
	pthread_t execute;
	Player* player_1;
	Player* player_2;
	Matrix* mainMatrix;
	ListQueue<int>* queuePos;

public:
	Thread();
	virtual ~Thread();
	static void* functionThread(void* var);
	void fThread();
	void start();
};

#endif /* THREAD_H_ */
