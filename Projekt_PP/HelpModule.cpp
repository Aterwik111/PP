#include "includes.h"
#include "HelpModule.h"
#include "System.h"
void HelpModule::ShowHelp() {
	bShown = true;
	db.setBgColor(CYAN);
	db.setTxtColor(YELLOW);
	db.setActive(Z_INDEX_HELP);
	db.writeString("POMOC", db.width / 2 - 2, 1);
	db.writeString("Celem gry jest opuszczenie labiryntu...", 1, 3);
	db.writeString("Sterowanie:", 1, 5);
	db.writeString("Strzalki w lewo/prawo - obrot o 90 stopni", 2, 6);
	db.writeString("Strzalki w gore/dol - ruch do przodu/do tylu", 2, 7);
	db.writeString("Obsluga programu:", 1, 9);
	db.writeString("R - restart gry", 2, 10);
	db.writeString("H - wyswietlenie/ukrycie pomocy", 2, 11);
	db.writeString("ESC - powrot do menu glownego", 2, 12);
	db.writeString("Q - wyjscie z programu", 2, 13);
}
void HelpModule::HideHelp() {
	db.clear();
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
void HelpModule::onFrame(key_buffer kb) {
	
}
HelpModule::HelpModule()
{
	db.setArea({ 1,SCREEN_HEIGHT / 2 - 7,SCREEN_WIDTH,SCREEN_HEIGHT / 2 + 7 });
}


HelpModule::~HelpModule()
{
}
