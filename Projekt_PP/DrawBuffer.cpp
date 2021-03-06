#include "DrawBuffer.h"
#include "Renderer.h"
#include "includes.h"



bool DrawBuffer::setActive(int z_order)
{
	number_in_queue = Renderer->AddToQueue(this,z_order);
	if(number_in_queue == ERR_QUEUE_FULL) {
		return false;
	}
	return true;
}
pixel& DrawBuffer::at(int x,int y) {
	return data[(y*width +x)];
}
void DrawBuffer::clear()
{
	for (int i = 0; i < width*height; i++) {
		data[i].ch = ' ';
	}
}
void DrawBuffer::setBgColor(int color) {
	for (int i = 0; i < width*height; i++) {
		data[i].bgColor = color;
	}
}
void DrawBuffer::setTxtColor(int color) {
	for (int i = 0; i < width*height; i++) {
		data[i].txtColor = color;
	}
}
void DrawBuffer::setInactive() {
	if (number_in_queue != NOT_IN_QUEUE) {
		Renderer->RemoveFromQueue(number_in_queue);
	}
}
void DrawBuffer::setArea(rect r){
	drawArea = r;
	width = r.right - r.left +1;
	height = r.bottom - r.top + 1;
	if (data != NULL) {
		free(data);
	}
	data = (pixel*) malloc(sizeof(pixel)*(width)*(height));
	for (int i = 0; i < width*height;i++) {
		data[i] = { ' ',DEFAULT_TXT_COLOR,DEFAULT_BG_COLOR};
	}
}
void DrawBuffer::writeString(const char *str, int x, int y)
{
	while (*str != 0) {
		this->at(x, y).ch = *str;
		str++;
		x++;
	}

}
void DrawBuffer::paintFrom(DrawBuffer& source){
	for (int x = 0; x < source.width; x++) {
		for (int y = 0; y < source.height; y++) {
			this->at(source.drawArea.left + x, source.drawArea.top + y).ch = source.at(x, y).ch;
			this->at(source.drawArea.left + x, source.drawArea.top + y).txtColor = source.at(x, y).txtColor;
			this->at(source.drawArea.left + x, source.drawArea.top + y).bgColor = source.at(x, y).bgColor;
		}
	}
}
void DrawBuffer::fillRect(rect rc, pixel pi)
{
	for (int x = rc.left; x <= rc.right; x++) {
		for (int y = rc.top; y <= rc.bottom; y++) {
			this->at(x, y) = pi;
		}
	}
}
void::DrawBuffer::flip() {
	pixel tmp;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < ((width +1) / 2); x++) {
			tmp = at(x, y);
			at(x, y) = at(width - x-1, y);
			at(width - x-1, y) = tmp;
		}
	}
}
DrawBuffer::DrawBuffer()
{	
	data = NULL; 
	width = 0, height = 0;
	number_in_queue = NOT_IN_QUEUE;
}

DrawBuffer::~DrawBuffer()
{
	DrawBuffer::setInactive();
	free(data);
}
