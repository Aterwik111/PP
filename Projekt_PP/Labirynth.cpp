#include "includes.h"
#include "Labirynth.h"


void Labirynth::setSize(int x, int y)
{
	free(data);
	data =(int*) malloc(x*y*sizeof(int));
	sizeX = x;
	sizeY = y;
}
bool Labirynth::LoadFromFile(const char * filename)
{
	FILE *plik=NULL;
	bool bSucces = false;
	fopen_s(&plik,filename,"r");
	if (plik) {
		if (fscanf_s(plik, "%d %d %d %d %d %d", &sizeX, &sizeY,&spawnX,&spawnY,&finishX,&finishY)==6) {
			bSucces = true;
			this->setSize(sizeX, sizeY);
			for (int i = 0; i < sizeX*sizeY; i++) {//wczytywanie kolejnych pól labiryntu
				if (fscanf_s(plik, "%d", &data[i])!=1) {
					bSucces = false;
					break;
				}
			}
		}
	}
	for (int x = 0; x < this->sizeX - 1;x++) {//sprawdzanie czy nie ma pustych pól 2x2
		for (int y = 0; y < this->sizeY - 1; y++) {
			if (this->at(x,y)==BLOCK_EMPTY) {
				if (this->at(x + 1, y) == BLOCK_EMPTY) {
					if (this->at(x, y+1) == BLOCK_EMPTY) {
						if (this->at(x+1, y + 1) == BLOCK_EMPTY) {
							bSucces = false;
						}
					}
				}
			}
		}
	}
	if (plik) {
		fclose(plik);
	}
	return bSucces;
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
