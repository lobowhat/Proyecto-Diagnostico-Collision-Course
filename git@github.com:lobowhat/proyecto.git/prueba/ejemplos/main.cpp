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
int currentX_J1, currentY_J1, currentX_J2, currentY_J2;
int sec = 0;
char exit, oldalchar, direction_J1, direction_J2;

void moveAndActiveKeyPad();
bool collision();
void boxDraw(int beginX, int beginY, int maxX, int maxY, char pChar);
void initColor();
void initPosGamers();

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
	direction_J1 = 'u';
	direction_J2 = 'u';
	initColor();
	boxDraw(15, 0, 24, 4, oldalchar);
	boxDraw(25, 0, 34, 4, oldalchar);
	boxDraw(35, 0, 44, 4, oldalchar);
	boxDraw(45, 0, 54, 4, oldalchar);
	boxDraw(55, 0, 64, 4, oldalchar);
	boxDraw(65, 0, 74, 4, oldalchar);
	boxDraw(75, 0, 84, 4, oldalchar);
	boxDraw(85, 0, 94, 4, oldalchar);
	boxDraw(95, 0, 104, 4, oldalchar);
	boxDraw(105, 0, 114, 4, oldalchar);
	boxDraw(115, 0, 124, 4, oldalchar);
	boxDraw(125, 0, 134, 4, oldalchar);
	boxDraw(15, 4, 24, 8, oldalchar);
	boxDraw(25, 4, 34, 8, oldalchar);
	boxDraw(35, 4, 44, 8, oldalchar);
	boxDraw(45, 4, 54, 8, oldalchar);
	boxDraw(55, 4, 64, 8, oldalchar);
	boxDraw(65, 4, 74, 8, oldalchar);
	boxDraw(75, 4, 84, 8, oldalchar);
	boxDraw(85, 4, 94, 8, oldalchar);
	boxDraw(95, 4, 104, 8, oldalchar);
	boxDraw(105, 4, 114, 8, oldalchar);
	boxDraw(115, 4, 124, 8, oldalchar);
	boxDraw(125, 4, 134, 8, oldalchar);
	boxDraw(15, 8, 24, 12, oldalchar);
	boxDraw(25, 8, 34, 12, oldalchar);
	boxDraw(35, 8, 44, 12, oldalchar);
	boxDraw(45, 8, 54, 12, oldalchar);
	boxDraw(55, 8, 64, 12, oldalchar);
	boxDraw(65, 8, 74, 12, oldalchar);
	boxDraw(75, 8, 84, 12, oldalchar);
	boxDraw(85, 8, 94, 12, oldalchar);
	boxDraw(95, 8, 104, 12, oldalchar);
	boxDraw(105, 8, 114, 12, oldalchar);
	boxDraw(115, 8, 124, 12, oldalchar);
	boxDraw(125, 8, 134, 12, oldalchar);
	boxDraw(15, 12, 24, 16, oldalchar);
	boxDraw(25, 12, 34, 16, oldalchar);
	boxDraw(35, 12, 44, 16, oldalchar);
	boxDraw(45, 12, 54, 16, oldalchar);
	boxDraw(55, 12, 64, 16, oldalchar);
	boxDraw(65, 12, 74, 16, oldalchar);
	boxDraw(75, 12, 84, 16, oldalchar);
	boxDraw(85, 12, 94, 16, oldalchar);
	boxDraw(95, 12, 104, 16, oldalchar);
	boxDraw(105, 12, 114, 16, oldalchar);
	boxDraw(115, 12, 124, 16, oldalchar);
	boxDraw(125, 12, 134, 16, oldalchar);
	boxDraw(15, 16, 24, 20, oldalchar);
	boxDraw(25, 16, 34, 20, oldalchar);
	boxDraw(35, 16, 44, 20, oldalchar);
	boxDraw(45, 16, 54, 20, oldalchar);
	boxDraw(55, 16, 64, 20, oldalchar);
	boxDraw(65, 16, 74, 20, oldalchar);
	boxDraw(75, 16, 84, 20, oldalchar);
	boxDraw(85, 16, 94, 20, oldalchar);
	boxDraw(95, 16, 104, 20, oldalchar);
	boxDraw(105, 16, 114, 20, oldalchar);
	boxDraw(115, 16, 124, 20, oldalchar);
	boxDraw(125, 16, 134, 20, oldalchar);
	boxDraw(15, 20, 24, 24, oldalchar);
	boxDraw(25, 20, 34, 24, oldalchar);
	boxDraw(35, 20, 44, 24, oldalchar);
	boxDraw(45, 20, 54, 24, oldalchar);
	boxDraw(55, 20, 64, 24, oldalchar);
	boxDraw(65, 20, 74, 24, oldalchar);
	boxDraw(75, 20, 84, 24, oldalchar);
	boxDraw(85, 20, 94, 24, oldalchar);
	boxDraw(95, 20, 104, 24, oldalchar);
	boxDraw(105, 20, 114, 24, oldalchar);
	boxDraw(115, 20, 124, 24, oldalchar);
	boxDraw(125, 20, 134, 24, oldalchar);
	boxDraw(15, 24, 24, 28, oldalchar);
	boxDraw(25, 24, 34, 28, oldalchar);
	boxDraw(35, 24, 44, 28, oldalchar);
	boxDraw(45, 24, 54, 28, oldalchar);
	boxDraw(55, 24, 64, 28, oldalchar);
	boxDraw(65, 24, 74, 28, oldalchar);
	boxDraw(75, 24, 84, 28, oldalchar);
	boxDraw(85, 24, 94, 28, oldalchar);
	boxDraw(95, 24, 104, 28, oldalchar);
	boxDraw(105, 24, 114, 28, oldalchar);
	boxDraw(115, 24, 124, 28, oldalchar);
	boxDraw(125, 24, 134, 28, oldalchar);
	boxDraw(15, 28, 24, 32, oldalchar);
	boxDraw(25, 28, 34, 32, oldalchar);
	boxDraw(35, 28, 44, 32, oldalchar);
	boxDraw(45, 28, 54, 32, oldalchar);
	boxDraw(55, 28, 64, 32, oldalchar);
	boxDraw(65, 28, 74, 32, oldalchar);
	boxDraw(75, 28, 84, 32, oldalchar);
	boxDraw(85, 28, 94, 32, oldalchar);
	boxDraw(95, 28, 104, 32, oldalchar);
	boxDraw(105, 28, 114, 32, oldalchar);
	boxDraw(115, 28, 124, 32, oldalchar);
	boxDraw(125, 28, 134, 32, oldalchar);
	boxDraw(15, 32, 24, 36, oldalchar);
	boxDraw(25, 32, 34, 36, oldalchar);
	boxDraw(35, 32, 44, 36, oldalchar);
	boxDraw(45, 32, 54, 36, oldalchar);
	boxDraw(55, 32, 64, 36, oldalchar);
	boxDraw(65, 32, 74, 36, oldalchar);
	boxDraw(75, 32, 84, 36, oldalchar);
	boxDraw(85, 32, 94, 36, oldalchar);
	boxDraw(95, 32, 104, 36, oldalchar);
	boxDraw(105, 32, 114, 36, oldalchar);
	boxDraw(115, 32, 124, 36, oldalchar);
	boxDraw(125, 32, 134, 36, oldalchar);
	attron(COLOR_PAIR(1));
	boxDraw(0, 0, 14, 15, '*');
	move(1, 2);
	printw("Jugador 1");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(4));
	boxDraw(135, 0, 150, 15, '*');
	move(1, 137);
	printw("Jugador 2");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(2));
	move(3, 1);
	printw("Puntuacion:");
	move(5, 1);
	printw("Traccion:");
	move(7, 1);
	printw("Estela Media:");
	move(9, 1);
	printw("Estela Alta:");
	move(11, 1);
	printw("Invensible:");
	move(13, 1);
	printw("Velocidad:");
	move(3, 136);
	printw("Puntuacion:");
	move(5, 136);
	printw("Traccion:");
	move(7, 136);
	printw("Estela Media:");
	move(9, 136);
	printw("Estela Alta:");
	move(11, 136);
	printw("Invensible:");
	move(13, 136);
	printw("Velocidad:");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(1));
	move(17, 0);
	printw("Derecha: S");
	move(19, 0);
	printw("Izquierda: A");
	move(21, 0);
	printw("Traccion: Q");
	move(23, 0);
	printw("Estela Media: W");
	move(25, 0);
	printw("Estela Alta: E");
	move(27, 0);
	printw("Invensible: R");
	move(29, 0);
	printw("Velocidad: T");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(4));
	move(17, 136);
	printw("Flecha Der.");
	move(19, 136);
	printw("Flecha Izq.");
	move(21, 136);
	printw("Traccion: I");
	move(23, 136);
	printw("Estela Media: J");
	move(25, 136);
	printw("Estela Alta: K");
	move(27, 136);
	printw("Invensible: O");
	move(29, 136);
	printw("Velocidad: L");
	attroff(COLOR_PAIR(4));

	initPosGamers();
	refresh();

	while (collision() == false) {
		sec++;
		moveAndActiveKeyPad();
		usleep(100000);
	}
	move(maxHeight / 2, maxWidth / 2);
	printw("Game Over");
	endwin();
	return 0;
}

void moveAndActiveKeyPad() {
	int tmp = getch();
	switch (tmp) {
	case 115:
		if (direction_J1 == 'l') {
			direction_J1 = 'u';
		} else if (direction_J1 == 'u') {
			direction_J1 = 'r';
		} else if (direction_J1 == 'r') {
			direction_J1 = 'd';
		} else if (direction_J1 == 'd') {
			direction_J1 = 'l';
		}
		break;
	case 97:
		if (direction_J1 == 'l') {
			direction_J1 = 'd';
		} else if (direction_J1 == 'd') {
			direction_J1 = 'r';
		} else if (direction_J1 == 'r') {
			direction_J1 = 'u';
		} else if (direction_J1 == 'u') {
			direction_J1 = 'l';
		}
		break;
	case KEY_RIGHT:
		if (direction_J2 == 'l') {
			direction_J2 = 'u';
		} else if (direction_J2 == 'u') {
			direction_J2 = 'r';
		} else if (direction_J2 == 'r') {
			direction_J2 = 'd';
		} else if (direction_J2 == 'd') {
			direction_J2 = 'l';
		}
		break;
	case KEY_LEFT:
		if (direction_J2 == 'l') {
			direction_J2 = 'd';
		} else if (direction_J2 == 'd') {
			direction_J2 = 'r';
		} else if (direction_J2 == 'r') {
			direction_J2 = 'u';
		} else if (direction_J2 == 'u') {
			direction_J2 = 'l';
		}
		break;
	case KEY_BACKSPACE:
		exit = 'q';
		break;
	}
	move(currentY_J1, currentX_J1);
	addch(' ');
	if (direction_J1 == 'l') {
		currentX_J1--;
	} else if (direction_J1 == 'r') {
		currentX_J1++;
	} else if (direction_J1 == 'u') {
		currentY_J1--;
	} else if (direction_J1 == 'd') {
		currentY_J1++;
	}
	move(currentY_J1, currentX_J1);
	addch('X');
	refresh();

	move(currentY_J2, currentX_J2);
	addch(' ');
	if (direction_J2 == 'l') {
		currentX_J2--;
	} else if (direction_J2 == 'r') {
		currentX_J2++;
	} else if (direction_J2 == 'u') {
		currentY_J2--;
	} else if (direction_J2 == 'd') {
		currentY_J2++;
	}
	move(currentY_J2, currentX_J2);
	addch('Y');
	refresh();
}


void boxDraw(int beginX, int beginY, int maxX, int maxY, char pChar) {
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
}

bool collision() {
	if (currentX_J1 == 15 || currentX_J1 == maxWidth - 7 || currentY_J1 == 0
			|| currentY_J1 == maxHeight) {
		return true;
	} else {
		return false;
	}
}

void initPosGamers() {
	currentY_J1 = 33;
	currentX_J1 = 35;
	move(currentY_J1, currentX_J1);
	addch('X');
	currentY_J2 = 33;
	currentX_J2 = 100;
	move(currentY_J2, currentX_J2);
	addch('Y');
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
