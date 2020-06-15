// DoAn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <dos.h>
#include <string>
#include "Funtion.h"
#include "Menu.h"
#include "System.h"
#include <conio.h>
#include "GamePlay.h"
TOADO toado;
int Index[19][19] = { 0 };
int d = 19, c = 19, x = toado.x = 1, y = toado.y = 1;
//int _tmain(int argc, _TCHAR* argv[])
//{
//	MainMenu();
//	return 0;
//}
int main(){
	MainMenu();
	return 0;
}
