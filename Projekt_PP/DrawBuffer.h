#pragma once
#include "includes.h"
#include "defines.h"

class DrawBuffer
{
private:
	int number_in_queue;
public:
	rect drawArea;
	int width, height;
	pixel *data = NULL;

	pixel& at(int x,int y);
	void clear();

	void setBgColor(int);

	void setTxtColor(int color);

	void paintFrom(DrawBuffer&);
	void fillRect(rect, pixel);
	void setArea(rect);
	void writeString(const char* str,int x,int y);
	bool setActive(int z_order);
	void setInactive();
	DrawBuffer();
	~DrawBuffer();
	void flip();
};

