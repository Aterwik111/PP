#pragma once
class Labirynth
{
public:
	int sizeX, sizeY;
	int *data=NULL;
	int& at(int x, int y);
	void setSize(int x, int y);
	Labirynth();
	~Labirynth();
};

