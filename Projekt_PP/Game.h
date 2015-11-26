#pragma once
#include "Level.h"
#include "Labirynth.h"
#include "DrawBuffer.h"
class Game :
	public Level
{
	int gameState = 0;
	DrawBuffer db2D;
	DrawBuffer dbCounters;
	DrawBuffer db3D;
	Labirynth currentLab;
	int posX, posY, direction;
	int move_counter;
	DWORD start_time;
public:
	void onEnter(int param);
	void Draw2dLab();
	void onFrame(key_buffer kb);
	bool loadFromFile(const char *filename);
	void startGame();
	void endGame();
	void onExit();
	bool tryToMove(int kierunek);
	Game();
	~Game();
};

