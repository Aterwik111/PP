#pragma once


#define SCREEN_HEIGHT (50)
#define SCREEN_WIDTH (100)

#define MAX_BUFFERS (20)
#define MAX_MODULES (20)
#define KEY_BUFFER_SIZE (5)

#define RESIZABLE_CONSOLE TRUE

#define DEFAULT_LABIRYNTH_NAME "D://default.lab"

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3


#define BLOCK_EMPTY 0
#define BLOCK_WALL 1

#define Z_INDEX_FPS_COUNTER 15
#define Z_INDEX_HELP 10
#define Z_INDEX_LAB_3D 3
#define Z_INDEX_LAB_2D 2
#define Z_INDEX_MAIN_MENU 0

#define LVL_MENU 0
#define LVL_GAME 1
#define LVL_EDITOR 2

#define DEFAULT_TXT_COLOR BLACK
#define DEFAULT_BG_COLOR WHITE


#define ERR_QUEUE_FULL (-1)
#define NOT_IN_QUEUE (-1)


struct key_buffer {
	int number_of_keys;
	char keys[KEY_BUFFER_SIZE];
};
struct rect{
	int left, top, right, bottom;
};
struct pixel {
	char ch;
	int txtColor;
	int bgColor;
};
