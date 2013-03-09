/*
 * Thread.cpp
 *
 *  Created on: 09/03/2013
 *      Author: jose
 */

#include "Thread.h"
#include <iostream>
using namespace std;
Thread::Thread() {
	this->mainMatrix = new Matrix();
	this->mainMatrix->creationmatrix();
//	this->queuePos = new ListQueue<int>();
	this->gui = new GUI();
//	this->player_1 = this->gui->getPlayer_1();
//	this->player_2 = this->gui->getPlayer_2();
	this->_player1=1;
	this->_player2=2;
	this->_EM=3;
	this->_EA=4;
	this->_TA=5;
	this->_VA=6;
	this->_BA=7;
	this->_TERR=8;
	this->_INVE=9;
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
	gui->start();

  while(!gui->collision()){
	  int _positionX=this->player_1->getPosX();
	  int _positionY=this->player_1->getPosY();
	  int _positionX2=this->player_2->getPosX();
	  int _positionY2=this->player_2->getPosY();
	  int j_1=mainMatrix->Graphiccontrolgame(_positionX,_positionY);
	  int j_2=mainMatrix->Graphiccontrolgame(_positionX2,_positionY2);
	  mainMatrix->changereference(j_1,this->_player1);
	  mainMatrix->changereference(j_2,this->_player2);
	  mainMatrix->showMatrix();
      gui->drawBumps(56,89);
	  usleep(500000);
  }
}
