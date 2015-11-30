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
	DrawBuffer db3D, db3DP;
	Labirynth currentLab;
	int posX, posY, direction;
	int move_counter;
	DWORD start_time;
public:
	static pixel block_types[BLOCK_TYPES_AMOUNT];
	void onEnter(int param);
	void Draw2dLab();
	void fillWall(int number, bool empty, pixel px, DrawBuffer * db);
	void drawTopEdge(int number, bool empty, DrawBuffer* db);
	void drawBottomEdge(int number, bool empty, DrawBuffer* db);
	void drawEdge(int number,DrawBuffer* db);
	void drawFrontWall(int number, int type);
	void getProjection(int &middleWallType, int &wall_number, int* leftWalls, int* rightWalls);
	void Draw3dLab();
	void onFrame(key_buffer kb);
	bool loadFromFile(const char *filename);
	void startGame();
	void endGame();
	void onExit();
	bool tryToMove(int kierunek);
	Game();
	~Game();
};

