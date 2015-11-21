#include "Renderer.h"
#include "DrawBuffer.h"
#include "includes.h"
using namespace std;

int CRenderer::AddToQueue(DrawBuffer *db,int z_index)
{
	if (z_index < MAX_BUFFERS && z_index >= 0) {
		if (queue[z_index] == NULL) {
			queue[z_index] = db;
			return z_index;
		}
	}
	return ERR_QUEUE_FULL;
}
void CRenderer::RemoveFromQueue(int num)
{
	if (num < MAX_BUFFERS && num >= 0) {
		queue[num] = NULL; 
	}
}

void CRenderer::SwapBuffers() {
	if (b) {
		currentBuff = &ScreenBuffer1;
		previousBuff = &ScreenBuffer2;
	}
	else {
		currentBuff = &ScreenBuffer2;
		previousBuff = &ScreenBuffer1;
	}
	for (int x = 1; x <= SCREEN_WIDTH; x++) {
		for (int y = 1; y <= SCREEN_HEIGHT; y++) {
			currentBuff->at(x, y).ch = ' ';
			currentBuff->at(x, y).bgColor = DEFAULT_BG_COLOR;
			currentBuff->at(x, y).txtColor = DEFAULT_TXT_COLOR;
		}
	}
	b ^= 1;
}
void CRenderer::DrawDifferences() {
	int txtColor = DEFAULT_TXT_COLOR;
	int bgColor = DEFAULT_BG_COLOR;
	textcolor(DEFAULT_TXT_COLOR);
	textbackground(DEFAULT_BG_COLOR);
	bool mustChange = false;
	for (int y = 1; y <= SCREEN_HEIGHT; y++) {
		for (int x = 1; x <= SCREEN_WIDTH; x++) {
			mustChange = false;
			if (currentBuff->at(x, y).bgColor != previousBuff->at(x, y).bgColor) {
				mustChange = true;
			}
			else if (currentBuff->at(x, y).ch != previousBuff->at(x, y).ch) {
				mustChange = true;
			}
			else if (currentBuff->at(x, y).txtColor != previousBuff->at(x, y).txtColor) {
				mustChange = true;
			}
			if (mustChange) {
				gotoxy(x, y);
				if (currentBuff->at(x, y).bgColor != bgColor) {
					textbackground(currentBuff->at(x, y).bgColor); bgColor = currentBuff->at(x, y).bgColor;
				}
				if (currentBuff->at(x, y).txtColor != txtColor) {
					textcolor(currentBuff->at(x, y).txtColor); txtColor = currentBuff->at(x, y).txtColor;
				}
				putchar(currentBuff->at(x, y).ch);
			}
		}
	};
}
void CRenderer::RenderFrame(){
	SwapBuffers();
	
	for (int i = 0; i < MAX_BUFFERS; i++) {
		if (queue[i] != NULL) {
			currentBuff->paintFrom(*queue[i]);
		}
	}
	DrawDifferences();
}
CRenderer::CRenderer()
{
	memset(queue,NULL,MAX_BUFFERS*sizeof(DrawBuffer*));
	ScreenBuffer1.setArea({1,1,SCREEN_WIDTH+1,SCREEN_HEIGHT+1});
	ScreenBuffer2.setArea({1,1,SCREEN_WIDTH+1,SCREEN_HEIGHT+1});
}


CRenderer::~CRenderer()
{

}
