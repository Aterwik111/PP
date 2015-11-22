#include "includes.h"
#include "Labirynth.h"


void Labirynth::setSize(int x, int y)
{
	free(data);
	data =(int*) malloc(x*y*sizeof(int));
	sizeX = x;
	sizeY = y;
}
int& Labirynth::at(int x, int y) {
	return data[y*sizeX + x];
}
Labirynth::Labirynth()
{
}


Labirynth::~Labirynth()
{
}
