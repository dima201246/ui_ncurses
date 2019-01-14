#include <unistd.h>
#include <locale.h>

#include "include/ui_ncurses.h"
#include "third_party/iniparser/src/iniparser.h"

void initColor() {
	/*HOS code*/
	init_pair(TEXT_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(TEXT_WHITE_YELLOW, COLOR_WHITE, COLOR_YELLOW);
	init_pair(TEXT_WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(TEXT_WHITE_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(TEXT_WHITE_RED, COLOR_WHITE, COLOR_RED);
	init_pair(TEXT_WHITE_MAGENTA, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(TEXT_WHITE_CYAN, COLOR_WHITE, COLOR_CYAN);

	init_pair(TEXT_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(TEXT_BLACK_YELLOW, COLOR_BLACK, COLOR_YELLOW);
	init_pair(TEXT_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair(TEXT_BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(TEXT_BLACK_RED, COLOR_BLACK, COLOR_RED);
	init_pair(TEXT_BLACK_MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(TEXT_BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);

	init_pair(TEXT_YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(TEXT_BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(TEXT_GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(TEXT_RED_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(TEXT_MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(TEXT_CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);

	init_pair(TEXT_YELLOW_WHITE, COLOR_YELLOW, COLOR_WHITE);
	init_pair(TEXT_BLUE_WHITE, COLOR_BLUE, COLOR_WHITE);
	init_pair(TEXT_GREEN_WHITE, COLOR_GREEN, COLOR_WHITE);
	init_pair(TEXT_RED_WHITE, COLOR_RED, COLOR_WHITE);
	init_pair(TEXT_MAGENTA_WHITE, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(TEXT_CYAN_WHITE, COLOR_CYAN, COLOR_WHITE);

	init_pair(TEXT_BLUE_YELLOW, COLOR_BLUE, COLOR_YELLOW);
	init_pair(TEXT_GREEN_YELLOW, COLOR_GREEN, COLOR_YELLOW);
	init_pair(TEXT_RED_YELLOW, COLOR_RED, COLOR_YELLOW);
	init_pair(TEXT_MAGENTA_YELLOW, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(TEXT_CYAN_YELLOW, COLOR_CYAN, COLOR_YELLOW);

	init_pair(TEXT_YELLOW_BLUE, COLOR_YELLOW, COLOR_BLUE);
	init_pair(TEXT_GREEN_BLUE, COLOR_GREEN, COLOR_BLUE);
	init_pair(TEXT_RED_BLUE, COLOR_RED, COLOR_BLUE);
	init_pair(TEXT_MAGENTA_BLUE, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(TEXT_CYAN_BLUE, COLOR_CYAN, COLOR_BLUE);

	init_pair(TEXT_YELLOW_GREEN, COLOR_YELLOW, COLOR_GREEN);
	init_pair(TEXT_BLUE_GREEN, COLOR_BLUE, COLOR_GREEN);
	init_pair(TEXT_RED_GREEN, COLOR_RED, COLOR_GREEN);
	init_pair(TEXT_MAGENTA_GREEN, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(TEXT_CYAN_GREEN, COLOR_CYAN, COLOR_GREEN);

	init_pair(TEXT_YELLOW_RED, COLOR_YELLOW, COLOR_RED);
	init_pair(TEXT_BLUE_RED, COLOR_BLUE, COLOR_RED);
	init_pair(TEXT_GREEN_RED, COLOR_GREEN, COLOR_RED);
	init_pair(TEXT_MAGENTA_RED, COLOR_MAGENTA, COLOR_RED);
	init_pair(TEXT_CYAN_RED, COLOR_CYAN, COLOR_RED);

	init_pair(TEXT_YELLOW_MAGENTA, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(TEXT_BLUE_MAGENTA, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(TEXT_GREEN_MAGENTA, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(TEXT_RED_MAGENTA, COLOR_RED, COLOR_MAGENTA);
	init_pair(TEXT_CYAN_MAGENTA, COLOR_CYAN, COLOR_MAGENTA);

	init_pair(TEXT_YELLOW_CYAN, COLOR_YELLOW, COLOR_CYAN);
	init_pair(TEXT_BLUE_CYAN, COLOR_BLUE, COLOR_CYAN);
	init_pair(TEXT_GREEN_CYAN, COLOR_GREEN, COLOR_CYAN);
	init_pair(TEXT_RED_CYAN, COLOR_RED, COLOR_CYAN);
	init_pair(TEXT_MAGENTA_CYAN, COLOR_MAGENTA, COLOR_CYAN);
}

bool initDisplay() {
	setlocale(LC_ALL, "");
	initscr();
	initColor();
	clear();
	refresh();
	return true;
}

bool closeDisplay() {
	endwin();
	return true;
}

void getNormalInvColor(char const *color_str, color_t *color, color_t *sel_color) { // Получение кода цвета из имени и его инвертированной состовляющей
	/*HOS code*/
	if (strcmp(color_str, "cyan") == 0)
	{
		*color = TEXT_CYAN_BLACK;
		*sel_color = TEXT_WHITE_CYAN;
	}
	else
	{
		if (strcmp(color_str, "blue") == 0)
		{
			*color = TEXT_BLUE_BLACK;
			*sel_color = TEXT_WHITE_BLUE;
		}
		else
		{
			if (strcmp(color_str, "red") == 0)
			{
				*color = TEXT_RED_BLACK;
				*sel_color = TEXT_WHITE_RED;
			}
			else
			{
				if (strcmp(color_str, "yellow") == 0)
				{
					*color = TEXT_YELLOW_BLACK;
					*sel_color = TEXT_WHITE_YELLOW;
				}
				else
				{
					if (strcmp(color_str, "magenta") == 0)
					{
						*color = TEXT_MAGENTA_BLACK;
						*sel_color = TEXT_WHITE_MAGENTA;
					}
					else
					{
						if (strcmp(color_str, "green") == 0)
						{
							*color = TEXT_GREEN_BLACK;
							*sel_color = TEXT_WHITE_GREEN;
						}
						else
						{
							*color = TEXT_WHITE_BLACK;
							*sel_color = TEXT_BLACK_WHITE;
						}
					}
				}
			}
		}
	}
}

color_t getInvColor(color_t color) { // Получение кода инвертированного цвета
	if (color == TEXT_CYAN_BLACK)
	{
		return TEXT_WHITE_CYAN;
	}
	else
	{
		if (color == TEXT_BLUE_BLACK)
		{
			return TEXT_WHITE_BLUE;
		}
		else
		{
			if (color == TEXT_RED_BLACK)
			{
				return TEXT_WHITE_RED;
			}
			else
			{
				if (color == TEXT_YELLOW_BLACK)
				{
					return TEXT_WHITE_YELLOW;
				}
				else
				{
					if (color == TEXT_MAGENTA_BLACK)
					{
						return TEXT_WHITE_MAGENTA;
					}
					else
					{
						if (color == TEXT_GREEN_BLACK)
						{
							return TEXT_WHITE_GREEN;
						}
						else
						{
							return TEXT_BLACK_WHITE;
						}
					}
				}
			}
		}
	}
}

color_t getColorOnColor(color_t color_top, color_t color_bot) {
	/*HOS code*/
	// Если это белый цвет на белом фоне, то вывести чёрным на белом
	if ((color_top == 0) && (color_bot == 0))
	{
		return TEXT_BLACK_WHITE;
	}

	// Если одинаковые,  или цвет вывода белый
	if ((color_top == color_bot) || (color_top == TEXT_WHITE_BLACK))
	{
		// то писать белым, по выбранному цвету
		return ((color_bot + 1) * 7) + TEXT_WHITE_BLACK;
	}

	// А тут я беспонятия как это работает, главное не трогать дифайны цветов!
	if (color_bot > color_top)
	{
		return ((color_bot + 1) * 7) + (color_top + 1);
	}
	else
	{
		return ((color_bot + 1) * 7) + color_top;
	}

	return 0;
}

uint64_t creatTextBox(struct displayObject *display_objects, uint64_t size_x, uint64_t size_y, struct objProperties *properties) {

	return 0;
}
