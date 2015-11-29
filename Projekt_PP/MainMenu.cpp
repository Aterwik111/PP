#include "includes.h"
#include "MainMenu.h"
#include "System.h"


void MainMenu::onEnter(int param)
{
	
	db.setArea({1,1,SCREEN_WIDTH,SCREEN_HEIGHT});
	db.setBgColor(BLACK);
	db.setTxtColor(YELLOW);
	for (int i = db.width * 9; i < db.width * 10; i++) {
		db.data[i].bgColor = LIGHTRED;
	}
	for (int i = db.width * 10; i < db.width * 17; i++) {
		db.data[i].bgColor = RED;
	}
	db.writeString("MENU GLOWNE", 2, 9);
	db.writeString("I - wczytanie domyslnego labiryntu", 2, 11);
	db.writeString("O - wczytanie labiryntu z wybranego pliku", 2, 12);
	db.writeString("E - edytor poziomow", 2, 13);
	db.writeString("H - wyswietlenie pomocy", 2, 14);
	db.writeString("Q - wyjscie z programu", 2, 15);
	db.setActive(Z_INDEX_MAIN_MENU);
	
}

void MainMenu::onExit()
{
	db.setInactive();
}

void MainMenu::onFrame(key_buffer kb)
{
	switch (kb.keys[0]) {
	case 'i':
		systemModule->gotoLevel(&systemModule->gameLvl, 0);
		break;
	case 'o':
		systemModule->gotoLevel(&systemModule->gameLvl, 1);
		break;
	}
}

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}
