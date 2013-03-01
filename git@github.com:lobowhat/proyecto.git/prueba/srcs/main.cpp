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
void screenDraw(int beginX, int maxX, int maxY);
void initColor();

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
	initColor();
	attron(COLOR_PAIR(1));
	scoreDraw();
	screenDraw(10, 19, 4);
	screenDraw(20, 29, 4);
	screenDraw(30, 39, 4);
	screenDraw(40, 49, 4);
	screenDraw(50, 59, 4);
	screenDraw(60, 69, 4);
	screenDraw(70, 79, 4);
	screenDraw(80, 89, 4);
	screenDraw(90, 99, 4);
	screenDraw(100, 109, 4);
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	move(1, 1);
	printw("Score: ");
	attroff(COLOR_PAIR(2));
	currentY = (maxHeight / 2);
	currentX = (maxWidth / 2) + 5;
	move(currentY, currentX);
	addch('X');
	refresh();
	while (1) {
		if (sec == 2000 || exit == 'q') {
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
		addch('_');
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

void screenDraw(int beginX, int maxX, int maxY) {
	for (int i = beginX; i < maxX; i++) {
		move(0, i);
		addch(oldalchar);
	}
	for (int i = 0; i < maxY; ++i) {
		move(i, beginX);
		addch(oldalchar);
	}
	for (int i = beginX; i < maxX; ++i) {
		move(maxY, i);
		addch(oldalchar);
	}
	for (int i = 0; i < maxY+1; ++i) {
		move(i, maxX);
		addch(oldalchar);
	}
}

void initColor() {
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}
