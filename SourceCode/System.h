#pragma once
#include "System.h"
#include <Windows.h>
void textcolor(int x);
void gotoxy(int x, int y);
int SetFontSize(HANDLE windowHandle, COORD size);
int GetFontSize(HANDLE windowHandle, COORD *size);
void Textsize(float x);
void resizeConsole(int width, int height);
bool IsEmptyPosition();
