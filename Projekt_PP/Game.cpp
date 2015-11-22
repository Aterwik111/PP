#include "includes.h"
#include "Game.h"

void Game::onActivate() {
	db2D.z_order = Z_INDEX_LAB_2D;
	db2D.setArea({SCREEN_WIDTH-40,5,SCREEN_WIDTH -5,30});
	db2D.setActive();
	db2D.setBgColor(LIGHTBLUE);
}
void Game::onDeactivate()
{
	db2D.setInactive();
}
void Game::onFrame(char a) {
}
Game::Game()
{
}


Game::~Game()
{
}
