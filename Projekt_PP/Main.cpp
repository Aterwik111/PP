#include "includes.h"
#include "DrawBuffer.h"
#include "Renderer.h"
#include "Module.h"
#include "System.h"
using namespace std;

CRenderer *Renderer;
System *systemModule;

void Initialise();
void GameLogic(key_buffer kb);

int main()
{
	Initialise();
	////////////////////////////////////////////////////////////////////////
	systemModule = new System();
	systemModule->setActive();
	////////////////////////////////////////////////////////////////////////
	char a =0;
	key_buffer kb = kb = { 0,"" };
	do {
		kb = { 0,"" };
		while(kbhit()) {
			if (kb.number_of_keys >= KEY_BUFFER_SIZE) {
				break;
			}
			a = _getch();
			kb.keys[kb.number_of_keys] = a;
			kb.number_of_keys++;
		}
		GameLogic(kb);
		Renderer->RenderFrame();
	} while (a != 'q');

	return 0;
}

void GameLogic(key_buffer kb) {
	for (int i = 0; i < MAX_MODULES; i++) {
		if (Module::queue[i] != NULL) {
			Module::queue[i]->onFrame(kb);
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
