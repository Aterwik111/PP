#include "includes.h"
#include "Game.h"
#include "System.h"

pixel Game::block_types[BLOCK_TYPES_AMOUNT] = { {' ',BLACK,WHITE} ,{'@',BLACK,DARKGRAY}, {'#',LIGHTRED,LIGHTGRAY},{'X',BLACK,GREEN} };

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
		
		if (systemModule->textInputDialog("Prosze podac sciezke do pliku z labiryntem do wczytania", path)){
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
		db2D.data[i] = Game::block_types[currentLab.data[i]];
	}
}
void Game::fillWall(int number, bool empty,pixel px, DrawBuffer* db) {
	int startX = 0, widthX = 0, heightY = 0;
	double startY = 0;
	switch (number) {
	case 1://pierwsza sciana
		startX = 5;
		startY = 2.0;
		widthX = 5;
		heightY = 23;
		break;
	case 2://druga sciana
		startX = 10;
		startY = 4.5;
		widthX = 4;
		heightY = 18;
		break;
	case 3://trzecia sciana
		startX = 14;
		startY = 6.5;
		widthX = 3;
		heightY = 14;
		break;
	case 4://czwarta sciana
		startX = 18;
		startY = 8.5;
		widthX = 3;
		heightY =10;
		break;
	case 5://pi¹ta sciana
		startX = 21;
		startY = 10.0;
		widthX = 2;
		heightY = 7;
		break;
	case 6://szósta sciana
		startX = 23;
		startY = 11.0;
		widthX = 1;
		heightY = 5;
		break;
	case 7://siódma sciana
		startX = 25;
		startY = 12.0;
		widthX = 1;
		heightY = 3;
		break;
	}
	for (int i = 0; i < widthX; i++) {
		for (int j = 0; j < heightY; j++) {
			db->at(startX - i, (int)(startY)+j + 1) = px;
		}
		if (!empty) {
			startY -= 0.5;
			heightY += 1;
		}
	}
}
void Game::drawTopEdge(int number, bool empty, DrawBuffer* db) {
	int widthX;
	int startX;
	double startY;
	char c = 0;
	switch(number) {
	case 1://pierwsza sciana
		startX = 5;
		startY = 2.0;
		widthX = 5;
		break;
	case 2://druga sciana
		startX = 10;
		startY = 4.5;
		widthX = 4;
		break;
	case 3://trzecia sciana
		startX = 14;
		startY = 6.5;
		widthX = 3;
		break;
	case 4://czwarta sciana
		startX = 18;
		startY = 8.5;
		widthX = 3;
		break;
	case 5://pi¹ta sciana
		startX = 21;
		startY = 10.0;
		widthX = 2;
		break;
	case 6://szósta sciana
		startX = 23;
		startY = 11.0;
		widthX = 1;
		break;
	case 7://siódma sciana
		startX = 25;
		startY = 12.0;
		widthX = 1;
		break;
	default:
		widthX = 0;
		break;
	}
	for (int i = 0; i < widthX; i++) {
		if (startY - (int)startY > 0.0) {//0.5
			c = '_';
		}
		else {
			c = '-';
		}
		db->at(startX, (int)startY).ch = c;
		startX--;
		if (!empty) {
			startY -= 0.5;
		}
	}
}
void Game::drawBottomEdge(int number, bool empty, DrawBuffer* db) {
	int widthX;
	int startX;
	double startY;
	char c = 0;
	switch (number) {
	case 1://pierwsza sciana
		startX = 5;
		startY = 25.0;
		widthX = 5;
		break;
	case 2://druga sciana
		startX = 10;
		startY = 22.5;
		widthX = 4;
		break;
	case 3://trzecia sciana
		startX = 14;
		startY = 20.5;
		widthX = 3;
		break;
	case 4://czwarta sciana
		startX = 18;
		startY = 18.5;
		widthX = 3;
		break;
	case 5://pi¹ta sciana
		startX = 21;
		startY = 17.0;
		widthX = 2;
		break;
	case 6://szósta sciana
		startX = 23;
		startY = 16.0;
		widthX = 1;
		break;
	case 7://siódma sciana
		startX = 25;
		startY = 15.0;
		widthX = 1;
		break;
	default:
		widthX = 0;
		break;
	}
	for (int i = 0; i < widthX; i++) {
		if (startY - (int)startY > 0.0) {//0.5
			c = '_';
		}
		else {
			c = '-';
		}
		db->at(startX, (int)startY).ch = c;
		startX--;
		if (!empty) {
			startY += 0.5;
		}
	}
}
void Game::drawEdge(int number,DrawBuffer *db) {
	int startY=0, height=0, posX=0;
	switch (number) {
	case 0:
		posX = 0;
		startY = 0;
		height = 28;
	break;
	case 1:
		posX = 6;
		startY = 3;
		height = 22;
		break;
	case 2:
		posX = 11;
		startY = 5;
		height = 18;
		break;
	case 3:
		posX = 15;
		startY = 7;
		height = 14;
		break;
	case 4:
		posX = 19;
		startY = 9;
		height = 10;
		break;
	case 5:
		posX = 22;
		startY = 11;
		height = 6;
		break;
	case 6:
		posX = 24;
		startY = 12;
		height = 4;
		break;
	case 7:
		posX = 26;
		startY = 13;
		height = 2;
		break;
	}
	for (int i = 0; i < height; i++) {
		db->at(posX,startY+i).ch ='|';
		db->at(posX, posY).txtColor = BLACK;
		db->at(posX, startY + i).bgColor = RED;
	}
}
void Game::drawFrontWall(int number, int type) {
	rect r = { 0,0,-1,-1};
	char c = '-';
	switch (number) {
	case 0:
		r = {1, 0, 52, 27};
		break;
	case 1:
		r = { 7, 3, 46, 24 };
		break;	
	case 2:
		r = { 12, 5, 41, 21 };
		c = '_';
		break;
	case 3:
		r = { 16, 7, 37, 19 };
		c = '_';
		break;
	case 4:
		r = { 20, 9, 33, 17 };
		c = '_';
		break;
	case 5:
		r = { 23, 11, 30, 16 };
		break;
	case 6:
		r = { 25, 12, 28, 15 };
		break;
	}
	if (number != 0) {
		for (int i = r.left; i <= r.right; i++) {
			db3D.at(i, r.top - 1).ch = c;
			db3D.at(i, r.top - 1).bgColor = WHITE;
			db3D.at(i, r.top - 1).txtColor = BLACK;

			db3D.at(i, r.bottom + 1) = Game::block_types[type];
			db3D.at(i, r.bottom + 1).ch = c;
		}
	}
	db3D.fillRect(r, Game::block_types[type]);
}
void Game::getProjection(int &middleWallType, int &wall_number, int* leftWalls, int* rightWalls) {
	int directionX = 0, directionY = 0;
	int positionX, positionY;
	int leftX=0, leftY=0;
	positionX = this->posX;
	positionY = this->posY;
	int wall_num = 0;
	switch (this->direction) {
	case DIRECTION_LEFT:
		directionX = -1;
		leftY = 1;
		break;
	case DIRECTION_RIGHT:
		directionX = 1;
		leftY = -1;
		break;
	case DIRECTION_UP:
		directionY = -1;
		leftX = -1;
		break;
	case DIRECTION_DOWN:
		directionY = 1;
		leftX = 1;
		break;
	}
	while (true) {
		positionX += directionX;
		positionY += directionY;
		if (positionX >= 0 && positionX < currentLab.sizeX && positionY >= 0 && positionY < currentLab.sizeY) {
			if (currentLab.at(positionX, positionY) == BLOCK_EMPTY) {
				wall_num++;
			}
			else {
				middleWallType = currentLab.at(positionX, positionY);
				break;
			}
		}
		else {
			break;
		}
	}
	if (wall_num > 7) { wall_num = 7; }
	wall_number = wall_num;
	positionX = this->posX;
	positionY = this->posY;
	for (int i = 0; i <= wall_num; i++) {
		positionX += directionX;
		positionY += directionY;
		if (positionX >= 0 && positionX < currentLab.sizeX && positionY >= 0 && positionY < currentLab.sizeY) {
			leftWalls[i] = currentLab.at(positionX + leftX, positionY + leftY);
			rightWalls[i] = currentLab.at(positionX - leftX, positionY - leftY);
		}
		else {
			leftWalls[i] = 0;
			rightWalls[i] = 0;
		}
	}
}
void Game::Draw3dLab()
{
	db3D.clear();
	db3D.setBgColor(WHITE);
	db3D.setTxtColor(BLACK);
	db3DP.clear();
	db3DP.setBgColor(WHITE);
	db3DP.setTxtColor(BLACK);

	int wall_num = 0, middle_wall_type=0;
	int leftWalls[8], rightWalls[8];
	pixel tmpPx = {0,0,0};
	getProjection(middle_wall_type,wall_num, leftWalls, rightWalls);
	drawEdge(0, &db3D);
	drawEdge(0, &db3DP);
	for (int i = 0; i < wall_num; i++) {
		if (leftWalls[i] == BLOCK_EMPTY){
			if (leftWalls[i + 1]!=BLOCK_EMPTY){
			fillWall(i + 1, true, Game::block_types[leftWalls[i + 1]], &db3D);
			drawTopEdge(i + 1, true, &db3D);
			drawBottomEdge(i + 1, true, &db3D);
			}
		}
		else {
			fillWall(i + 1, false, Game::block_types[leftWalls[i]], &db3D);
			drawTopEdge(i+1, false, &db3D);
			drawBottomEdge(i+1, false, &db3D);
		}
		drawEdge(i+1, &db3D);

		if (rightWalls[i] == BLOCK_EMPTY) {
			if (rightWalls[i + 1]!=BLOCK_EMPTY){
			fillWall(i + 1, true, Game::block_types[rightWalls[i + 1]], &db3DP);
			drawTopEdge(i + 1, true, &db3DP);
			drawBottomEdge(i + 1, true, &db3DP);
			}
		}
		else {
			fillWall(i + 1, false, Game::block_types[rightWalls[i]], &db3DP);
			drawTopEdge(i + 1, false, &db3DP);
			drawBottomEdge(i + 1, false, &db3DP);
		}
		drawEdge(i + 1, &db3DP);
	}
    db3DP.flip();
	db3D.paintFrom(db3DP);
	drawFrontWall(wall_num, middle_wall_type);
}
void Game::startGame() {
	gameState = 1;
	posX = currentLab.spawnX;
	posY = currentLab.spawnY;
	direction = DIRECTION_DOWN;
	db2D.setArea({SCREEN_WIDTH - this->currentLab.sizeX ,2,SCREEN_WIDTH-1,1 + this->currentLab.sizeX });
	db2D.setActive(Z_INDEX_LAB_2D);
	db3D.setArea({ 10,4,63,31});
	db3D.setActive(Z_INDEX_LAB_3D);
	db3D.setBgColor(GREEN);
	db3DP.setArea({ 27,0,53,27});
	db3DP.setBgColor(LIGHTGREEN);
	dbCounters.setArea({ 1,2,SCREEN_WIDTH - this->currentLab.sizeX-2,2});
	dbCounters.setActive(Z_INDEX_LAB_COUNTERS);
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
	db3D.setInactive();
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
		Draw3dLab();
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
