#include "includes.h"
#include "HelpModule.h"

void HelpModule::ShowHelp() {
	db.z_order =  Z_INDEX_HELP;
	bShown = true;
	db.setBgColor(CYAN);
	db.setTxtColor(YELLOW);
	db.setActive();
	db.writeString("POMOC",db.width/2 -2,1);
	db.writeString("Celem gry jest opuszczenie labiryntu...",1,3);
	db.writeString("Obsluga programu:", 1, 5);
	db.writeString("Strzalki w lewo/prawo - zmiana kierunku patrzenia o 90 stopni", 2, 6);
	db.writeString("Strzalki w gore/dol - ruch do przodu/do tylu", 2, 7);
	db.writeString("D - otwieranie i zamykanie drzwi", 2, 8);
	db.writeString("I - wczytanie domyslnego labiryntu", 2, 9);
	db.writeString("H - wyswietlenie/ukrycie pomocy", 2, 10);
	db.writeString("Q - wyjscie z programu", 2, 11);
}
void HelpModule::HideHelp() {
	bShown = false;
	db.setInactive();
}
void HelpModule::ToggleHelp() {
	if (bShown) {
		HideHelp();
	}
	else {
		ShowHelp();
	}
}
void HelpModule::onFrame(char a) {
	
}
HelpModule::HelpModule()
{
	db.setArea({ 1,SCREEN_HEIGHT / 2 - 7,SCREEN_WIDTH,SCREEN_HEIGHT / 2 + 7 });
}


HelpModule::~HelpModule()
{
}
