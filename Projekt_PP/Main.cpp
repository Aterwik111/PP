#include "includes.h"
#include "DrawBuffer.h"
#include "Renderer.h"
#include "Module.h"
#include "System.h"
using namespace std;

CRenderer *Renderer;


void Initialise();
void GameLogic(char a);

int main()
{
	Initialise();
	////////////////////////////////////////////////////////////////////////
	System *system = new System();
	system->setActive();
	////////////////////////////////////////////////////////////////////////
	system->helpMenu.ShowHelp();
	////////////////////////////////////////////////////////////////////////
	char a;
	do {
		a = 0;
		if (kbhit()) {
			a = _getch();//TODO kilka getchów jednoczesnie, pêtla
		}
		GameLogic(a);
		Renderer->RenderFrame();
		Sleep(20);
	} while (a != 'q');

	return 0;
}

void GameLogic(char a) {
	for (int i = 0; i < MAX_MODULES; i++) {
		if (Module::queue[i] != NULL) {
			Module::queue[i]->onFrame(a);
		}
	}
}
void Initialise() {
	Renderer = new CRenderer();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hwndC = GetConsoleWindow();
	COORD coord;
	coord.X = SCREEN_WIDTH;
	coord.Y = SCREEN_HEIGHT + 1;

	SMALL_RECT windowSize = { 0, 0, SCREEN_WIDTH-1, SCREEN_HEIGHT};
	if (!RESIZABLE_CONSOLE) {
		SetWindowLong(hwndC, GWL_STYLE, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
	}
	SetConsoleScreenBufferSize(handle, coord);
	SetConsoleWindowInfo(handle, TRUE, &windowSize);
	ShowWindow(GetConsoleWindow(), SW_NORMAL);
	SetConsoleTitle(L"LABIRYNT");
	_setcursortype(_NOCURSOR);
}
