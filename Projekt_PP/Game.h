#pragma once
#include "Level.h"
#include "Labirynth.h"
#include "DrawBuffer.h"
class Game :
	public Level
{
	int gameState = 0;
	DrawBuffer db2D;
	DrawBuffer db3D;
	Labirynth currentLab;
	int posX, posY, direction;
public:
	void onEnter(int param);
	void Draw2dLab();
	void onFrame(key_buffer kb);
	bool loadFromFile(char *filename);
	void startGame();
	bool tryToMove(int kierunek);
	Game();
	~Game();
};

