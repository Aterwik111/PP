#include "includes.h"
#include "Game.h"


void Game::onEnter(int param) {
	gameState = 0;
	if (param == 0) {
		if (loadFromFile(DEFAULT_LABIRYNTH_NAME)) {
			startGame();
		}
		else {
			//komunikat o bledzie i powrot do menu
		}
	}
	else {
		//pytanie o nazwe poziomu
	}
}
void Game::Draw2dLab() {
	db2D.setBgColor(WHITE);
	for (int i = 0; i < db2D.width*db2D.height; i++) {
		db2D.data[i].ch = ' ';
		switch(currentLab.data[i]){
		case BLOCK_WALL:
			db2D.data[i].bgColor = BLACK;
		break;
		case BLOCK_EMPTY:
			db2D.data[i].bgColor = WHITE;
			break;
		}
	}
}
void Game::startGame() {
	gameState = 1;
	posX = currentLab.spawnX;
	posY = currentLab.spawnY;
	direction = DIRECTION_DOWN;
	db2D.setArea({SCREEN_WIDTH - this->currentLab.sizeX ,2,SCREEN_WIDTH-1,1 + this->currentLab.sizeX });
	Draw2dLab();
	db2D.setActive();
}
bool Game::loadFromFile(char * filename)
{
	if (currentLab.LoadFromFile(filename)) {
		gameState = 1;
		return true;
	}
	gameState = 0;
	return false;
}
void Game::onFrame(key_buffer kb) {
	if (gameState == 1) {	
		if (kb.number_of_keys) {
			switch (kb.keys[0]){
			case 0: //pewnie strza³ka
				if (kb.number_of_keys > 1) {
					switch(kb.keys[1]){
					case 'H'://strzalka w gore
						tryToMove(direction);
						break;
					case 'P':
						tryToMove((4 + direction + 2) % 4);
						break;
					case 'K'://strzalka w lewo
						direction = (4 + direction -1) % 4;
						break;
					case 'M'://strzalka w prawo
						direction = (4 + direction + 1) % 4;
						break;
					}
				}
			}
		}
		for (int i = 0; i < db2D.width*db2D.height; i++) {
			if (currentLab.data[i] == 1) {
				db2D.data[i].bgColor = BLACK;
			}
		}
		Draw2dLab();
		switch(direction){
		case DIRECTION_LEFT:
			db2D.at(posX, posY).ch = '<';
			break;
		case DIRECTION_UP:
			db2D.at(posX, posY).ch = '^';
			break;
		case DIRECTION_RIGHT:
			db2D.at(posX, posY).ch = '>';
			break;
		case DIRECTION_DOWN:
			db2D.at(posX, posY).ch = 'v';
			break;
		}
		
	}
}
bool Game::tryToMove(int kierunek) {
	switch (kierunek) {
	case DIRECTION_UP:
		if (posY > 0) {
			if (currentLab.at(posX, posY - 1) == BLOCK_EMPTY) {
				posY--;
			}
		}
		break;
	case DIRECTION_DOWN:
		if (posY+1 < currentLab.sizeY) {
			if (currentLab.at(posX, posY + 1) == BLOCK_EMPTY) {
				posY++;
			}
		}
		break;
	case DIRECTION_LEFT:
		if (posX > 0) {
			if (currentLab.at(posX-1, posY) == BLOCK_EMPTY) {
				posX--;
			}
		}
		break;
	case DIRECTION_RIGHT:
		if (posX+1 < currentLab.sizeX) {
			if (currentLab.at(posX+1, posY) == BLOCK_EMPTY) {
				posX++;
			}
		}
		break;
	}
	return false;
}
Game::Game()
{
}


Game::~Game()
{
}
