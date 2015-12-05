#pragma once


#define SCREEN_HEIGHT (50)
#define SCREEN_WIDTH (100)

#define MAX_BUFFERS (20)
#define MAX_MODULES (20)
#define KEY_BUFFER_SIZE (5)

#define RESIZABLE_CONSOLE TRUE

#define DEFAULT_LABIRYNTH_NAME "default.lab"

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3


#define BLOCK_EMPTY 0
#define BLOCK_RED 1
#define BLOCK_GREEN 2
#define BLOCK_DARK 3

#define BLOCK_TYPES_AMOUNT 6

#define Z_INDEX_FPS_COUNTER 15
#define Z_INDEX_DIALOG 14
#define Z_INDEX_HELP 10
#define Z_INDEX_LAB_COUNTERS 4
#define Z_INDEX_LAB_3D 3
#define Z_INDEX_LAB_2D 2
#define Z_INDEX_MAIN_MENU 0



#define TXT_FIELD_WIDTH (40)

#define DEFAULT_TXT_COLOR BLACK
#define DEFAULT_BG_COLOR BLACK


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
