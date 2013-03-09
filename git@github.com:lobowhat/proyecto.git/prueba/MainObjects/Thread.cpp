/*
 * Thread.cpp
 *
 *  Created on: 09/03/2013
 *      Author: jose
 */

#include "Thread.h"

Thread::Thread() {
	this->mainMatrix = new Matrix();
	this->mainMatrix->creationmatrix();
//	this->queuePos = new ListQueue<int>();
	this->gui = new GUI();
	this->player_1 = this->gui->getPlayer_1();
	this->player_2 = this->gui->getPlayer_2();
}

Thread::~Thread() {
	pthread_exit(NULL);
}

void Thread::start() {
	pthread_create(&this->execute, NULL, Thread::functionThread, this);

	pthread_join(this->execute, NULL);
}

void* Thread::functionThread(void* var) {
	reinterpret_cast<Thread*>(var)->fThread();
	return 0;
}

void Thread::fThread() {

}
