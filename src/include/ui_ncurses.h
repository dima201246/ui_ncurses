#ifndef UI_NCURSES_H
#define UI_NCURSES_H
	#include <stdint.h>
	#include <ncurses.h>

	#define false	0
	#define true	1

	enum objType {
		obj_text_box,
		obj_button
	};

	enum objColor {
		color_black
	};

	struct objProperties {
		uint64_t size_x;
		uint64_t size_y;

		enum objColor back_color;
		enum objColor color;
	};

	struct displayObject
	{
		enum objType obj_type;
		uint64_t position_x;
		uint64_t position_y;
	};

	bool initDisplay();
	bool closeDisplay();

	uint64_t creatTextBox(struct displayObject *display_objects, uint64_t size_x, uint64_t size_y, struct objProperties *properties);

#endif