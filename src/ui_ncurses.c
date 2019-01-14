#include <unistd.h>
#include <locale.h>

#include "include/ui_ncurses.h"
#include "third_party/iniparser/src/iniparser.h"

bool initDisplay() {
	setlocale(LC_ALL, "");
	initscr();
	clear();
	refresh();
	return true;
}

bool closeDisplay() {
	endwin();
	return true;
}

uint64_t creatTextBox(struct displayObject *display_objects, uint64_t size_x, uint64_t size_y, struct objProperties *properties) {

	return 0;
}