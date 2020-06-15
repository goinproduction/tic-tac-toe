#include "stdafx.h"
#include "System.h"
extern  int x;
extern  int y;
void textcolor(int x)
{
	HANDLE Mau;
	Mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Mau, x);
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);

}
bool IsEmptyPosition()
{
	char buf[2];
	COORD coord = { x, y };
	DWORD num_read;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ReadConsoleOutputCharacter(hConsole, (LPTSTR)buf, (DWORD)1, coord, (LPDWORD)&num_read) == 0)
	{
		return false;
	}
	if (buf[0] == ' ' || buf[0] == NULL)
		return true;
	return false;
}
int SetFontSize(HANDLE windowHandle, COORD size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	font.dwFontSize = size;

	if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}
	return 1;
}
int GetFontSize(HANDLE windowHandle, COORD *size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}
	*size = font.dwFontSize;
	return 1;
}
void Textsize(float x)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;

	if (GetFontSize(hConsole, &size))
	{
		size.X = (SHORT)(size.X * x);
		size.Y = (SHORT)(size.Y * x);
		SetFontSize(hConsole, size);
	}
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}