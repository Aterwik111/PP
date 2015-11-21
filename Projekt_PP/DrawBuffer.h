#pragma once
#include "includes.h"
#include "defines.h"

class DrawBuffer
{
private:
	int number_in_queue;
public:
	rect drawArea;
	int z_order = 0;
	int width, height;
	pixel *data;

	pixel& at(int x,int y);
	void clear();

	void setBgColor(int);

	void setTxtColor(int color);

	void paintFrom(DrawBuffer&);
	void setArea(rect);
	void writeString(char* str,int x,int y);
	bool setActive();
	void setInactive();
	DrawBuffer();
	~DrawBuffer();
};

