#pragma once
#include "includes.h"
#include "drawBuffer.h"
class Renderable;

class CRenderer
{
private:
	DrawBuffer* queue[MAX_BUFFERS];
	DrawBuffer ScreenBuffer1, ScreenBuffer2;
public:
	text_info ti;
	DrawBuffer *currentBuff,*previousBuff;
	int bufferSizeX, bufferSizeY;
	bool b;
	void SwapBuffers();

	void DrawDifferences();

	int AddToQueue(DrawBuffer*,int z_index);
	void RemoveFromQueue(int);

	void RenderFrame();

	CRenderer();
	~CRenderer();
};
extern CRenderer *Renderer;

