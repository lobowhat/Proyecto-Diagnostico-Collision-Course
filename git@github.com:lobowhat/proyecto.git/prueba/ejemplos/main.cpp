/*
 * main.cpp
 *
 *  Created on: 26/02/2013
 *      Author: jose
 */
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

int maxHeight, maxWidth;
int currentX, currentY;
int sec = 0;
char exit, oldalchar;

void moveX();
void scoreDraw();
void screenDraw();

int main(int argc, char **argv) {
	initscr();
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	getmaxyx(stdscr, maxHeight, maxWidth);
	maxHeight -= 2;
	maxWidth -= 10;
	oldalchar = (char) 219;
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	scoreDraw();
	screenDraw();
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	move(1, 1);
	printw("Score: ");
	move(2, 1);
	printw("%d", 10);
	move(3, 1);
	printw("%d", maxHeight);
	move(4, 1);
	printw("%d", maxHeight);
	attroff(COLOR_PAIR(2));
	currentY = (maxHeight / 2);
	currentX = (maxWidth / 2) + 5;
	move(currentY, currentX);
	addch('X');
	refresh();
	while (1) {
		if (sec == 100 || exit == 'q') {
			break;
		}
		sec++;
		moveX();
		usleep(100000);
	}
	endwin();
	return 0;
}

void moveX() {
	int tmp = getch();
	switch (tmp) {
	case 97:
		move(currentY, currentX);
		addch(' ');
		currentX--;
		move(currentY, currentX);
		addch('X');
		break;
	case 115:
		move(currentY, currentX);
		addch(' ');
		currentX++;
		move(currentY, currentX);
		addch('X');
		break;
	case KEY_BACKSPACE:
		exit = 'q';
		break;
	}
}

void scoreDraw() {
	for (int i = 0; i < 9; i++) {
		move(0, i);
		addch('-');
	}
	for (int i = 0; i < 10; ++i) {
		move(i, 0);
		addch('|');
	}
	for (int i = 0; i < 9; ++i) {
		move(10, i);
		addch('_');
	}
	for (int i = 0; i < 10; ++i) {
		move(i, 9);
		addch('|');
	}
}

void screenDraw() {
	for (int i = 10; i < maxWidth; i++) {
		move(0, i);
		addch(oldalchar);
	}
	for (int i = 0; i < maxHeight; ++i) {
		move(i, 10);
		addch(oldalchar);
	}
	for (int i = 10; i < maxWidth; ++i) {
		move(maxHeight, i);
		addch(oldalchar);
	}
	for (int i = 0; i < maxHeight + 1; ++i) {
		move(i, maxWidth);
		addch(oldalchar);
	}
}
