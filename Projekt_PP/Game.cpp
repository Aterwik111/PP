#include "includes.h"
#include "Game.h"
#include "System.h"

void Game::onEnter(int param) {
	gameState = 0;
	char path[TXT_FIELD_WIDTH];
	if (param == 0) {
		if (loadFromFile(DEFAULT_LABIRYNTH_NAME)) {
			startGame();
		}
		else {
			systemModule->dialog("Nie udalo sie wczytac domyslnego labiryntu!");
			systemModule->gotoLevel(&systemModule->menuLvl,0);
		}
	}
	else {
		
		if (systemModule->textInputDialog("Prosze podac sciezke do pliku z labiryntem do wczytwania", path)){
			if (loadFromFile(path)) { //sprobuj wczytac plik
				startGame();
			}
			else {
				systemModule->dialog("Nie udalo sie wczytac podanego labiryntu!");
				systemModule->gotoLevel(&systemModule->menuLvl, 0);
			}
		}
		else {
			systemModule->gotoLevel(&systemModule->menuLvl, 0);
		}
	}
}
void Game::Draw2dLab() {
	db2D.setBgColor(WHITE);
	for (int i = 0; i < db2D.width*db2D.height; i++) {
		db2D.data[i].ch = ' ';
		switch(currentLab.data[i]){
		case BLOCK_RED:
			db2D.data[i].bgColor = LIGHTGRAY;
			db2D.data[i].txtColor = LIGHTRED;
			db2D.data[i].ch = '#';
		break;
		case BLOCK_GREEN:
			db2D.data[i].bgColor = LIGHTGREEN;
			db2D.data[i].txtColor = DARKGRAY;
			db2D.data[i].ch = '$';
			break;
		case BLOCK_DARK:
			db2D.data[i].bgColor = DARKGRAY;
			db2D.data[i].txtColor = BLACK;
			db2D.data[i].ch = '@';
			break;
		case BLOCK_EMPTY:
			db2D.data[i].bgColor = WHITE;
			db2D.data[i].ch = ' ';
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
	db2D.setActive();
	dbCounters.setArea({ 1,2,SCREEN_WIDTH - this->currentLab.sizeX-2,2});
	dbCounters.z_order = Z_INDEX_LAB_COUNTERS;
	dbCounters.setActive();
	dbCounters.setBgColor(RED);
	dbCounters.setTxtColor(YELLOW);
	start_time = GetTickCount();
	move_counter = 0;
}
void Game::endGame() {
	gameState = 0;
	move_counter = 0;
	start_time = GetTickCount();
	db2D.setInactive();
	dbCounters.setInactive();
}
void Game::onExit() {
	endGame();
}
bool Game::loadFromFile(const char * filename)
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
				break;
			case 'r':
				endGame();
				startGame();
				break;
			case 27://ESC
				systemModule->gotoLevel(&systemModule->menuLvl, 0);
				return;
			}
		}
		for (int i = 0; i < db2D.width*db2D.height; i++) {
			if (currentLab.data[i] == 1) {
				db2D.data[i].bgColor = BLACK;
			}
		}
		Draw2dLab();
		char tmp[10];
		dbCounters.clear();
		dbCounters.writeString("Ilosc wykonanych ruchow: ",1,0);
		_itoa_s(this->move_counter, tmp, 10);
		dbCounters.writeString(tmp, 26, 0);
		dbCounters.writeString("Czas: ", 31, 0);
		_itoa_s((GetTickCount()-this->start_time)/1000, tmp, 10);
		dbCounters.writeString(tmp, 37, 0);
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
	bool result = false;
	switch (kierunek) {
	case DIRECTION_UP:
		if (posY > 0) {
			if (currentLab.at(posX, posY - 1) == BLOCK_EMPTY) {
				result = true;
				posY--;
			}
		}
		break;
	case DIRECTION_DOWN:
		if (posY+1 < currentLab.sizeY) {
			if (currentLab.at(posX, posY + 1) == BLOCK_EMPTY) {
				result = true;
				posY++;
			}
		}
		break;
	case DIRECTION_LEFT:
		if (posX > 0) {
			if (currentLab.at(posX-1, posY) == BLOCK_EMPTY) {
				result = true;
				posX--;
			}
		}
		break;
	case DIRECTION_RIGHT:
		if (posX+1 < currentLab.sizeX) {
			if (currentLab.at(posX+1, posY) == BLOCK_EMPTY) {
				result = true;
				posX++;
			}
		}
		break;
	}
	if (result) {
		move_counter++;
		return true;
	}
	return false;
}
Game::Game()
{
}


Game::~Game()
{
}
