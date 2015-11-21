#pragma once


#define SCREEN_HEIGHT (50)
#define SCREEN_WIDTH (140)

#define MAX_BUFFERS (20)
#define MAX_MODULES (20)

#define KEY_BUFFER_SIZE (20)

#define RESIZABLE_CONSOLE TRUE

#define ERR_QUEUE_FULL (-1)
#define NOT_IN_QUEUE (-1)
#define DEFAULT_TXT_COLOR WHITE
#define DEFAULT_BG_COLOR BLACK


struct rect{
	int left, top, right, bottom;
};
struct pixel {
	char ch;
	int txtColor;
	int bgColor;
};
