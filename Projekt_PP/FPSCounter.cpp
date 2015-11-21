#include "defines.h"
#include "FPSCounter.h"

void FPSCounter::onFrame(char a) {
	static char liczba[10];
	db.clear();
	tick2 = GetTickCount();
	if ( tick2- tick1 >= 1000) {
		_itoa_s(counter, liczba, 10);
		counter = 0;
		tick1 = tick2;
	}
	db.setBgColor(BLACK);
	db.setTxtColor(YELLOW);
	db.writeString("FPS:", 0, 0);
	db.writeString(liczba, 5, 0);
	counter++;
}
void FPSCounter::onActivate() {
	db.z_order = 15;
	db.setActive();
}
void FPSCounter::onDesactivate() {
	db.setInactive();
}
FPSCounter::FPSCounter()
{
	db.setArea({SCREEN_WIDTH-12,1,SCREEN_WIDTH,1});
}


FPSCounter::~FPSCounter()
{
}
