#include "includes.h"
#include "System.h"
#include "Renderer.h"

void System::dialog(const char *tresc)
{
	DrawBuffer dialogBuffer;
	dialogBuffer.setArea({1,1,SCREEN_WIDTH,SCREEN_HEIGHT});
	dialogBuffer.z_order = Z_INDEX_DIALOG;
	dialogBuffer.setActive();
	dialogBuffer.setBgColor(BLACK);
	dialogBuffer.setTxtColor(LIGHTRED);
	int len = 0;
	while (tresc[len]) {
		len++;
	}
	dialogBuffer.writeString(tresc,(SCREEN_WIDTH / 2) - ( len/2), 20);
	Renderer->RenderFrame();
	_getch();
}

bool System::textInputDialog(const char * komunikat,char* buffer)
{
	DrawBuffer dialogBuffer;
	char path[TXT_FIELD_WIDTH]="";
	dialogBuffer.setArea({ 1,1,SCREEN_WIDTH,SCREEN_HEIGHT });
	dialogBuffer.z_order = Z_INDEX_DIALOG;
	dialogBuffer.setActive();
	dialogBuffer.setBgColor(GREEN);
	dialogBuffer.setTxtColor(LIGHTRED);
	int len = 0;
	while (komunikat[len]) {
		len++;
	}
	for (int i = (SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2; i < (SCREEN_WIDTH + TXT_FIELD_WIDTH) / 2; i++) {
		dialogBuffer.at(i, SCREEN_HEIGHT / 2 - 1).bgColor = BLACK;
	}
	dialogBuffer.writeString(komunikat, (SCREEN_WIDTH / 2) - (len / 2), SCREEN_HEIGHT / 2 - 3);
	Renderer->RenderFrame();
	_setcursortype(_NORMALCURSOR);

	int cur_pos = 0;
	int current_length=0;
	gotoxy((SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2 + 1, SCREEN_HEIGHT / 2);
	char a = 0;
	while(true){
		a = _getch();
		textbackground(BLACK);
		if ((a == 32) || (a >= 95 && a <= 122) || (a >= 44 && a <= 90)) {//litery lub cyfry lub znaki lub spacja
			if (current_length < TXT_FIELD_WIDTH - 1) {
				for (int i = current_length-1; i >=cur_pos; i--) {
					path[i+1] = path[i];
				}
				path[cur_pos] = a;
				cur_pos++;
				current_length++;
			}
		}
		else if (a == '\b') {//backspace
			if (cur_pos > 0) {
				cur_pos--;
				for (int i = cur_pos; i < current_length;i++){
					path[i] = path[i + 1];
				}
				current_length--;
			}
		}
		else if (a == 0) {
			a = _getch();
			switch (a) {
				case 'K'://strzalka w lewo
					if (cur_pos > 0) {
						cur_pos--;
					}
					break;
				case 'M'://strzalka w prawo
					if (cur_pos < current_length) {
						cur_pos++;
					}
					break;
			}
		}
		else if (a == 27) {//ESC
			_setcursortype(_NOCURSOR);
			gotoxy((SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2 + 1, SCREEN_HEIGHT / 2);
			for (int i = 0; i < TXT_FIELD_WIDTH; i++) {
				putchar(' ');
			}
			return false;
		}
		else if (a == '\r' || a == '\n') {//ENTER
			_setcursortype(_NOCURSOR);
			int i = 0;
			while (path[i]) {
				buffer[i] = path[i];
				i++;
			}
			buffer[i] = '\0';
			gotoxy((SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2 + 1, SCREEN_HEIGHT / 2);
			for (int i = 0; i < TXT_FIELD_WIDTH; i++) {
				putchar(' ');
			}
			return true;
		}
		gotoxy((SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2 + 1, SCREEN_HEIGHT / 2);
		std::cout << path;
		for (int i = current_length; i < TXT_FIELD_WIDTH; i++) {
			putchar(' ');
		}
		gotoxy((SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2 + 1 + cur_pos, SCREEN_HEIGHT / 2);
	}
	_setcursortype(_NOCURSOR);
	gotoxy((SCREEN_WIDTH - TXT_FIELD_WIDTH) / 2 + 1, SCREEN_HEIGHT / 2);
	for (int i = 0; i < TXT_FIELD_WIDTH; i++) {
		putchar(' ');
	}
	return false;
}

void System::gotoLevel(Level * lvl,int param)
{
	lvlChanged = true;
	if (currentLvl != NULL) {
		currentLvl->onExit();
	}
	currentLvl = lvl;
	this->param = param;
}

void System::onFrame(key_buffer kb)
{
	switch(kb.keys[0])
	{
	case 'h':
		helpMenu.ToggleHelp();		
		break;
	case 'f':
		if (fpsc.isActive()) {
			fpsc.setInactive();
		}
		else {
			fpsc.setActive();
		}
		break;
	}
	if (lvlChanged) {
		lvlChanged = false;
		helpMenu.HideHelp();
		currentLvl->onEnter(param);
	}
	currentLvl->onFrame(kb);
}

System::System()
{
	gotoLevel(&menuLvl,0);
}


System::~System()
{
}
