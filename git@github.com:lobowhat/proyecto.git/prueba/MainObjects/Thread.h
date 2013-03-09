/*
 * Thread.h
 *
 *  Created on: 09/03/2013
 *      Author: jose
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include <unistd.h>
#include "GUI.h"
#include "ListQueue.h"
#include "Matrix.h"
#include "Player.h"

class Thread {
private:
	pthread_t execute;
	Player* player_1;
	Player* player_2;
	Matrix* mainMatrix;
	ListQueue<int>* queuePos;
	GUI* gui;
	int _player1;
	int _player2;
	int _EM;
	int _EA;
	int _TA;
	int _VA;
	int _BA;
	int _TERR;
	int _INVE;

public:
	Thread();
	virtual ~Thread();
	static void* functionThread(void* var);
	void fThread();
	void start();
};

#endif /* THREAD_H_ */
