/*
 * GUI.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "GUI.h"

GUI::GUI() {
	initscr();
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	getmaxyx(stdscr, maxHeight, maxWidth);
	this->sec = 0;
	this->player_1 = new Player();
	this->player_2 = new Player();
	queueTrack_1 = new ListQueue<TrackPos*>();
	queueTrack_2 = new ListQueue<TrackPos*>();
	wallChar = (char) 219;
	direction_P1 = 'u';
	direction_P2 = 'u';
	charPlayer_1 = charPlayer_2 = '^';
	_bump = 'O';
	_surprises = '@';
	_surprise_2 = '$';
	_highZones = 'M';
	initColor();
	initPosGamers();
	gameManual();
}

GUI::~GUI() {
	getch();
	refresh();
	endwin();
}

void* GUI::movement(void* obj) {
	reinterpret_cast<GUI *>(obj)->functionCronometer();
	return 0;
}

void* GUI::crono(void* obj) {
	reinterpret_cast<GUI *>(obj)->moveAndActiveKeyPad();
	return 0;
}

void* GUI::updateScores(void* obj) {
	reinterpret_cast<GUI *>(obj)->updateHabilities();
	return 0;
}

void GUI::start() {
	pthread_create(&this->_clock, NULL, GUI::crono, this);
	pthread_create(&this->_movement, NULL, GUI::movement, this);
	pthread_create(&this->_update, NULL, GUI::updateScores, this);

	pthread_join(this->_clock, NULL);
	pthread_join(this->_movement, NULL);
	pthread_join(this->_update, NULL);
}

void GUI::gameOver() {
	move(maxHeight / 2, maxWidth / 2);
	printw("Game Over");
	refresh();
	usleep(2000000);
	endwin();
}

void GUI::updateHabilities() {
	while (!collision()) {
		move(4, 1);
		printw("%d", this->player_1->getScore());
		move(6, 1);
		printw("%d", this->player_1->getMediumTrack());
		move(8, 1);
		printw("%d", this->player_1->getHighTrack());
		move(10, 1);
		printw("%d", this->player_1->getHighTrack());
		move(12, 1);
		printw("%d", this->player_1->getInvincible());
		move(14, 1);
		printw("%d", this->player_1->getHighSpeed());
		refresh();

		move(4, 136);
		printw("%d", this->player_2->getScore());
		move(6, 136);
		printw("%d", this->player_2->getMediumTrack());
		move(8, 136);
		printw("%d", this->player_2->getHighTrack());
		move(10, 136);
		printw("%d", this->player_2->getHighTrack());
		move(12, 136);
		printw("%d", this->player_2->getInvincible());
		move(14, 136);
		printw("%d", this->player_2->getHighSpeed());
		refresh();

		usleep(500000);
	}
}

void GUI::functionCronometer() {
	int sec = 0;
	while (!collision()) {
		usleep(1000000);
		sec++;
		move(34, 1);
		printw("Time: %d", sec);
		move(34, 136);
		printw("Time: %d", sec);
		refresh();
	}
}

void GUI::moveAndActiveKeyPad() {
	while (!collision()) {
		usleep(220000);
		int tmp = getch();
		switch (tmp) {
		case 115:
			if (direction_P1 == 'l') {
				direction_P1 = 'u';
				charPlayer_1 = '^';
			} else if (direction_P1 == 'u') {
				direction_P1 = 'r';
				charPlayer_1 = '>';
			} else if (direction_P1 == 'r') {
				direction_P1 = 'd';
				charPlayer_1 = 'v';
			} else if (direction_P1 == 'd') {
				direction_P1 = 'l';
				charPlayer_1 = '<';
			}
			break;
		case 97:
			if (direction_P1 == 'l') {
				direction_P1 = 'd';
				charPlayer_1 = 'v';
			} else if (direction_P1 == 'd') {
				direction_P1 = 'r';
				charPlayer_1 = '>';
			} else if (direction_P1 == 'r') {
				direction_P1 = 'u';
				charPlayer_1 = '^';
			} else if (direction_P1 == 'u') {
				direction_P1 = 'l';
				charPlayer_1 = '<';
			}
			break;
		case KEY_RIGHT:
			if (direction_P2 == 'l') {
				direction_P2 = 'u';
				charPlayer_2 = '^';
			} else if (direction_P2 == 'u') {
				direction_P2 = 'r';
				charPlayer_2 = '>';
			} else if (direction_P2 == 'r') {
				direction_P2 = 'd';
				charPlayer_2 = 'v';
			} else if (direction_P2 == 'd') {
				direction_P2 = 'l';
				charPlayer_2 = '<';
			}
			break;
		case KEY_LEFT:
			if (direction_P2 == 'l') {
				direction_P2 = 'd';
				charPlayer_2 = 'v';
			} else if (direction_P2 == 'd') {
				direction_P2 = 'r';
				charPlayer_2 = '>';
			} else if (direction_P2 == 'r') {
				direction_P2 = 'u';
				charPlayer_2 = '^';
			} else if (direction_P2 == 'u') {
				direction_P2 = 'l';
				charPlayer_2 = '<';
			}
			break;
		}
		attron(COLOR_PAIR(1));
		move(currentY_P1, currentX_P1);
		this->queueTrack_1->enqueue(new TrackPos(currentX_P1, currentY_P1));
		addch('x');
		attroff(COLOR_PAIR(1));
		if (direction_P1 == 'l') {
			currentX_P1--;
		} else if (direction_P1 == 'r') {
			currentX_P1++;
		} else if (direction_P1 == 'u') {
			currentY_P1--;
		} else if (direction_P1 == 'd') {
			currentY_P1++;
		}
		attron(COLOR_PAIR(6));
		move(currentY_P1, currentX_P1);
		addch(charPlayer_1);
		refresh();
		attroff(COLOR_PAIR(6));

		attron(COLOR_PAIR(4));
		move(currentY_P2, currentX_P2);
		addch('x');
		this->queueTrack_2->enqueue(new TrackPos(currentX_P2, currentY_P2));
		attroff(COLOR_PAIR(4));
		if (direction_P2 == 'l') {
			currentX_P2--;
		} else if (direction_P2 == 'r') {
			currentX_P2++;
		} else if (direction_P2 == 'u') {
			currentY_P2--;
		} else if (direction_P2 == 'd') {
			currentY_P2++;
		}
		attron(COLOR_PAIR(5));
		move(currentY_P2, currentX_P2);
		addch(charPlayer_2);
		attroff(COLOR_PAIR(5));
		refresh();
	}
}

void GUI::boxDraw(int beginX, int beginY, int maxX, int maxY, char pChar) {
	attron(COLOR_PAIR(7));
	for (int i = beginX; i < maxX; i++) {
		move(beginY, i);
		addch(pChar);
	}
	for (int i = beginY; i < maxY; ++i) {
		move(i, beginX);
		addch(pChar);
	}
	for (int i = beginX; i < maxX; ++i) {
		move(maxY, i);
		addch(pChar);
	}
	for (int i = beginY; i < maxY + 1; ++i) {
		move(i, maxX);
		addch(pChar);
	}
	attroff(COLOR_PAIR(7));
}

bool GUI::collision() {
	if (currentX_P1 == 15 || currentX_P1 == maxWidth - 17 || currentY_P1 == 0
			|| currentY_P1 == maxHeight - 1) {
		return true;
	} else if (currentX_P2 == 15 || currentX_P2 == maxWidth - 17
			|| currentY_P2 == 0 || currentY_P2 == maxHeight - 1) {
		return true;
	} else {
		return false;
	}
}

void GUI::initPosGamers() {
	attron(COLOR_PAIR(6));
	currentY_P1 = 33;
	currentX_P1 = 35;
	move(currentY_P1, currentX_P1);
	addch(charPlayer_1);
	attroff(COLOR_PAIR(6));
	attron(COLOR_PAIR(5));
	currentY_P2 = 33;
	currentX_P2 = 100;
	move(currentY_P2, currentX_P2);
	addch(charPlayer_2);
	attroff(COLOR_PAIR(5));
	refresh();
}

void GUI::initColor() {
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_GREEN);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLUE);
	init_pair(6, COLOR_RED, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_BLUE);
	init_pair(8, COLOR_YELLOW, COLOR_WHITE);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
}

void GUI::gameManual() {
	attron(COLOR_PAIR(1));
	boxDraw(0, 0, 14, 15, '*');
	move(1, 2);
	printw("Player 1");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(4));
	boxDraw(135, 0, 150, 15, '*');
	move(1, 137);
	printw("Player 2");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(2));
	move(3, 1);
	printw("Score:");
	move(5, 1);
	printw("Traction:");
	move(7, 1);
	printw("Medium Track:");
	move(9, 1);
	printw("High Track:");
	move(11, 1);
	printw("Invincible:");
	move(13, 1);
	printw("Speed:");
	move(3, 136);
	printw("Score:");
	move(5, 136);
	printw("Traction:");
	move(7, 136);
	printw("Medium Track:");
	move(9, 136);
	printw("High Track:");
	move(11, 136);
	printw("Invincible:");
	move(13, 136);
	printw("Speed:");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(1));
	move(17, 0);
	printw("Right: S");
	move(19, 0);
	printw("Left: A");
	move(21, 0);
	printw("Traction: Q");
	move(23, 0);
	printw("Medium Track: W");
	move(25, 0);
	printw("High Track: E");
	move(27, 0);
	printw("Invincible: R");
	move(29, 0);
	printw("Speed: T");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(4));
	move(17, 136);
	printw("Arrow Right");
	move(19, 136);
	printw("Arrow Left");
	move(21, 136);
	printw("Traction: I");
	move(23, 136);
	printw("Medium Track: J");
	move(25, 136);
	printw("High Track: K");
	move(27, 136);
	printw("Invincible: O");
	move(29, 136);
	printw("Speed: L");
	attroff(COLOR_PAIR(4));
}

void GUI::drawBumps(int x, int y) {
	attron(COLOR_PAIR(8));
	for (int i = x; i < x + 3; ++i) {
		for (int j = y; j < y + 2; ++j) {
			move(j, i);
			addch(_bump);
			refresh();
		}
	}
	attroff(COLOR_PAIR(8));
}

void GUI::drawHighZones(int x, int y) {
	attron(COLOR_PAIR(9));
	for (int i = x; i < x + 3; ++i) {
		for (int j = y; j < y + 2; ++j) {
			move(j, i);
			addch(_highZones);
			refresh();
		}
	}
	attroff(COLOR_PAIR(9));
}

void GUI::drawSurprises(int x, int y, int color) {
	attron(COLOR_PAIR(color));
	move(y, x);
	addch(_surprises);
	move(y, x + 1);
	addch(_surprise_2);
	attroff(COLOR_PAIR(color));
}
