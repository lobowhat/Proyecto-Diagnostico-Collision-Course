/*
 * Thread.h
 *
 *  Created on: 09/03/2013
 *      Author: jose
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include <GUI.h>
#include <ListQueue.h>
#include <Matrix.h>
#include <Player.h>
class Thread {
private:
	pthread_t execute;
public:
	Thread();

	virtual ~Thread();
	static void* functionThread(void* var);
	void fThread();
	void start();
};

#endif /* THREAD_H_ */
