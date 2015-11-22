#pragma once


#define SCREEN_HEIGHT (50)
#define SCREEN_WIDTH (140)

#define MAX_BUFFERS (20)
#define MAX_MODULES (20)

#define RESIZABLE_CONSOLE TRUE

#define Z_INDEX_FPS_COUNTER 15
#define Z_INDEX_HELP 10
#define Z_INDEX_LAB_3D 3
#define Z_INDEX_LAB_2D 2
#define Z_INDEX_MAIN_MENU 0

#define DEFAULT_TXT_COLOR WHITE
#define DEFAULT_BG_COLOR BLACK


#define ERR_QUEUE_FULL (-1)
#define NOT_IN_QUEUE (-1)



struct rect{
	int left, top, right, bottom;
};
struct pixel {
	char ch;
	int txtColor;
	int bgColor;
};
