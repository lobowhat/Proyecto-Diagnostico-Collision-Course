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
void scoreDraw(int beginX, int beginY, int maxX, int maxY);
void screenDraw(int beginX, int beginY, int maxX, int maxY);
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
	scoreDraw(0, 0, 14, 15);
	scoreDraw(135, 0, 150, 15);
	screenDraw(15, 0, 24, 4);
	screenDraw(25, 0, 34, 4);
	screenDraw(35, 0, 44, 4);
	screenDraw(45, 0, 54, 4);
	screenDraw(55, 0, 64, 4);
	screenDraw(65, 0, 74, 4);
	screenDraw(75, 0, 84, 4);
	screenDraw(85, 0, 94, 4);
	screenDraw(95, 0, 104, 4);
	screenDraw(105, 0, 114, 4);
	screenDraw(115, 0, 124, 4);
	screenDraw(125, 0, 134, 4);
	screenDraw(15, 4, 24, 8);
	screenDraw(25, 4, 34, 8);
	screenDraw(35, 4, 44, 8);
	screenDraw(45, 4, 54, 8);
	screenDraw(55, 4, 64, 8);
	screenDraw(65, 4, 74, 8);
	screenDraw(75, 4, 84, 8);
	screenDraw(85, 4, 94, 8);
	screenDraw(95, 4, 104, 8);
	screenDraw(105, 4, 114, 8);
	screenDraw(115, 4, 124, 8);
	screenDraw(125, 4, 134, 8);
	screenDraw(15, 8, 24, 12);
	screenDraw(25, 8, 34, 12);
	screenDraw(35, 8, 44, 12);
	screenDraw(45, 8, 54, 12);
	screenDraw(55, 8, 64, 12);
	screenDraw(65, 8, 74, 12);
	screenDraw(75, 8, 84, 12);
	screenDraw(85, 8, 94, 12);
	screenDraw(95, 8, 104, 12);
	screenDraw(105, 8, 114, 12);
	screenDraw(115, 8, 124, 12);
	screenDraw(125, 8, 134, 12);
	screenDraw(15, 12, 24, 16);
	screenDraw(25, 12, 34, 16);
	screenDraw(35, 12, 44, 16);
	screenDraw(45, 12, 54, 16);
	screenDraw(55, 12, 64, 16);
	screenDraw(65, 12, 74, 16);
	screenDraw(75, 12, 84, 16);
	screenDraw(85, 12, 94, 16);
	screenDraw(95, 12, 104, 16);
	screenDraw(105, 12, 114, 16);
	screenDraw(115, 12, 124, 16);
	screenDraw(125, 12, 134, 16);
	screenDraw(15, 16, 24, 20);
	screenDraw(25, 16, 34, 20);
	screenDraw(35, 16, 44, 20);
	screenDraw(45, 16, 54, 20);
	screenDraw(55, 16, 64, 20);
	screenDraw(65, 16, 74, 20);
	screenDraw(75, 16, 84, 20);
	screenDraw(85, 16, 94, 20);
	screenDraw(95, 16, 104, 20);
	screenDraw(105, 16, 114, 20);
	screenDraw(115, 16, 124, 20);
	screenDraw(125, 16, 134, 20);
	screenDraw(15, 20, 24, 24);
	screenDraw(25, 20, 34, 24);
	screenDraw(35, 20, 44, 24);
	screenDraw(45, 20, 54, 24);
	screenDraw(55, 20, 64, 24);
	screenDraw(65, 20, 74, 24);
	screenDraw(75, 20, 84, 24);
	screenDraw(85, 20, 94, 24);
	screenDraw(95, 20, 104, 24);
	screenDraw(105, 20, 114, 24);
	screenDraw(115, 20, 124, 24);
	screenDraw(125, 20, 134, 24);
	screenDraw(15, 24, 24, 28);
	screenDraw(25, 24, 34, 28);
	screenDraw(35, 24, 44, 28);
	screenDraw(45, 24, 54, 28);
	screenDraw(55, 24, 64, 28);
	screenDraw(65, 24, 74, 28);
	screenDraw(75, 24, 84, 28);
	screenDraw(85, 24, 94, 28);
	screenDraw(95, 24, 104, 28);
	screenDraw(105, 24, 114, 28);
	screenDraw(115, 24, 124, 28);
	screenDraw(125, 24, 134, 28);
	screenDraw(15, 28, 24, 32);
	screenDraw(25, 28, 34, 32);
	screenDraw(35, 28, 44, 32);
	screenDraw(45, 28, 54, 32);
	screenDraw(55, 28, 64, 32);
	screenDraw(65, 28, 74, 32);
	screenDraw(75, 28, 84, 32);
	screenDraw(85, 28, 94, 32);
	screenDraw(95, 28, 104, 32);
	screenDraw(105, 28, 114, 32);
	screenDraw(115, 28, 124, 32);
	screenDraw(125, 28, 134, 32);
	screenDraw(15, 32, 24, 36);
	screenDraw(25, 32, 34, 36);
	screenDraw(35, 32, 44, 36);
	screenDraw(45, 32, 54, 36);
	screenDraw(55, 32, 64, 36);
	screenDraw(65, 32, 74, 36);
	screenDraw(75, 32, 84, 36);
	screenDraw(85, 32, 94, 36);
	screenDraw(95, 32, 104, 36);
	screenDraw(105, 32, 114, 36);
	screenDraw(115, 32, 124, 36);
	screenDraw(125, 32, 134, 36);
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	move(1, 1);
	printw("Puntuación:");
	move(3, 1);
	printw("Tracción:");
	move(5, 1);
	printw("Estela Media:");
	move(7, 1);
	printw("Estela Alta:");
	move(9, 1);
	printw("Invensible:");
	move(11, 1);
	printw("Velocidad:");
	move(1, 136);
	printw("Puntuación:");
	move(3, 136);
	printw("Tracción:");
	move(5, 136);
	printw("Estela Media:");
	move(7, 136);
	printw("Estela Alta:");
	move(9, 136);
	printw("Invensible:");
	move(11, 136);
	printw("Velocidad:");
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

void scoreDraw(int beginX, int beginY, int maxX, int maxY) {
	for (int i = beginX; i < maxX; i++) {
		move(beginY, i);
		addch('*');
	}
	for (int i = beginY; i < maxY + 1; ++i) {
		move(i, beginX);
		addch('*');
	}
	for (int i = beginX; i < maxX; ++i) {
		move(maxY, i);
		addch('*');
	}
	for (int i = beginY; i < maxY + 1; ++i) {
		move(i, maxX);
		addch('*');
	}
}

void screenDraw(int beginX, int beginY, int maxX, int maxY) {
	for (int i = beginX; i < maxX; i++) {
		move(beginY, i);
		addch(oldalchar);
	}
	for (int i = beginY; i < maxY; ++i) {
		move(i, beginX);
		addch(oldalchar);
	}
	for (int i = beginX; i < maxX; ++i) {
		move(maxY, i);
		addch(oldalchar);
	}
	for (int i = beginY; i < maxY + 1; ++i) {
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
