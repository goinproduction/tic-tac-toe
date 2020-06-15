#include "stdafx.h"
#include "Menu.h"
#include "System.h"
#include <conio.h>
#include "GamePlay.h"
#include "Funtion.h"
extern int player, amount;
int turnfirst = 1;
int counttime = 30000;
bool Check[3] = { false, true, true };
void MainMenuChoose(char **&T)
{
	T = new char*[7];
	for (int i = 0; i < 7; i++)
	{
		T[i] = new char[8];
	}
	strcpy(T[0], "  HELP ");
	strcpy(T[1], "  OPTIONS  ");
	strcpy(T[2], "  NEW GAME ");
	strcpy(T[3], "  SAVE GAME ");
	strcpy(T[4], "  LOAD GAME ");
	strcpy(T[5], "  ABOUT ");
	strcpy(T[6], "  EXIT ");
}
void Exit(char **&T)
{
	T = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		T[i] = new char[22];
	}
	strcpy(T[0], "  DONG Y LUU  ");
	strcpy(T[1], "  THOAT MA KHONG LUU  ");
	strcpy(T[2], "  TRO LAI  ");
}
int ChooseFeature(int max, char **T)
{
	char choose = NULL;
	int i = 1;
	char KeyMove[3];
	KeyMove[0] = 72; // UP
	KeyMove[1] = 80; // DOWN
	KeyMove[2] = 13; // DOWN
	int feature = 0, temp;
	if (max == 6) temp = 0;
	else temp = -10;
	textcolor(62);
	gotoxy(12 + temp, i);
	printf("%s", T[feature]);
	textcolor(15);
	while (choose != KeyMove[0] || choose != KeyMove[1])
	{
		choose = _getch();
		if (choose == KeyMove[0])// Up
		{
			if (feature > 0)
			{
				if (i > 1) {
					gotoxy(11 + temp, i);
					printf("%s ", T[i - 1]);
					i--;
					gotoxy(12 + temp, i);
					textcolor(62);
					printf("%s", T[i - 1]);
					textcolor(15);
				}
				feature--;
			}

		}
		if (choose == KeyMove[1])//Down
		{
			if (feature < max)
			{
				gotoxy(11 + temp, i);
				printf("%s ", T[i - 1]);
				i++;
				gotoxy(12 + temp, i);
				textcolor(62);
				printf("%s", T[i - 1]);
				textcolor(15);
				feature++;
			}
		}
		if (choose == KeyMove[2]) break;
	}
	return feature;
}
void MainMenu()
{
	system("cls");
	resizeConsole(300, 200);
	char choose = NULL;
	textcolor(15);
	printf("|---------- MAIN MENU----------|\n");
	printf("|           HELP               |\n");
	printf("|           OPTIONS            |\n");
	printf("|           NEW GAME           |\n");
	printf("|           SAVE GAME          |\n");
	printf("|           LOAD GAME          |\n");
	printf("|           ABOUT              |\n");
	printf("|           EXIT               |\n");
	printf("|----- Hay chon chuc nang -----|\n");
	char **T;
	MainMenuChoose(T);
	int feature = ChooseFeature(6, T);
	switch (feature)
	{
	case 0:
	{
			  Help();
			  system("cls");
			  MainMenu();
			  break;
	}
	case 1:
	{
			  Option();
			  break;
	}
	case 2:
	{
			  Reset();
			  Start();
			  Play();
			  break;
	}
	case 3:
	{
			  system("cls");
			  printf("Save Game Successfully");
			  SaveGame();
			  _getch();
			  MainMenu();
			  break;
	}
	case 4:
	{
			  Loadgame();
			  break;
	}
	case 5:
	{
			  About();
			  MainMenu();
			  break;
	}
	case 6:
	{
			  system("cls");
			  char **ExitMenu;
			  printf("|--------- "); textcolor(14); printf("THOAT"); textcolor(15); printf(" ---------|\n");
			  printf("|  DONG Y LUU             |\n");
			  printf("|  THOAT MA KHONG LUU     |\n");
			  printf("|  TRO LAI                |\n");
			  printf("|-------------------------|\n");
			  Exit(ExitMenu);
			  int e = ChooseFeature(2, ExitMenu) + 1;
			  switch (e)
			  {
			  case 1:
			  {
						remove("RecentlyCaroGame.CR");
						SaveGame();
						exit(0);
			  }
			  case 2:
			  {
						remove("RecentlyCaroGame.CR");
						exit(0);
			  }
			  default:
				  MainMenu();
			  }
	}
	}
}
void Help()
{
	system("cls");
	textcolor(15);
	resizeConsole(460, 350);
	printf("|---------------------- "); textcolor(14); printf("HELP"); textcolor(15); printf(" ----------------------|\n");
	printf("|------------------- "); textcolor(14); printf("CACH CHOI"); textcolor(15); printf(" --------------------|\n");
	printf("|  Nguoi choi 1 dung 4 phim mui ten de di chuyen   |\n");
	printf("|            nhan Enter de dat quan co             |\n");
	printf("|  Nguoi choi 2 dung 4 phim A, D, W, S de di chuyen|\n");
	printf("|            nhan Space de dat quan co             |\n");
	printf("|-------------------- "); textcolor(14); printf("PHIM TAT"); textcolor(15); printf(" --------------------|\n");
	printf("|            F1 : Hien thi GIUP DO                 |\n");
	printf("|            F2 : Choi van moi                     |\n");
	printf("|            F3 : Luu game                         |\n");
	printf("|            F4 : Tai game                         |\n");
	printf("|            F5 : Hien thi thong tin               |\n");
	printf("|           ESC : Menu chinh                       |\n");
	printf("|------------------- "); textcolor(14); printf("LUAT CHOI"); textcolor(15); printf(" ------------------- |\n");
	printf("| Hai ben thay phien danh cac dau X,O tren ban co  |\n");
	printf("| Ben nao co duong 5 quan lien tuc ma khong bi chan|\n");
	printf("| 2 dau tren mot hang, cot,duong cheo la thang     |\n");
	printf("|---------- NHAN PHIM BAT KI DE QUAY LAI ----------|\n");
	_getch();
}
void About()
{
	system("cls");
	resizeConsole(400, 200);
	textcolor(15);
	printf("|------------------ "); textcolor(14); printf("ABOUT"); textcolor(15); printf(" ------------------|\n");
	printf("|    Game : "); textcolor(14); printf("Caro Game (Console)      "); textcolor(15);
	printf("\t|\n|    Nhom phat trien :  "); ; textcolor(15);
	printf("\t\t|\n|    1 : "); textcolor(14); printf("Nguyen Thanh Suu            "); textcolor(15);
	printf("\t|\n|    MSSV : "); textcolor(14); printf("1712736                       "); textcolor(15);
	printf("\t|\n|    2 : "); textcolor(14); printf("Vu Thanh Dat             "); textcolor(15);
	printf("\t|\n|    MSSV : "); textcolor(14); printf("1612087                      "); textcolor(15);
	printf("\t|\n|    3 : "); textcolor(14); printf("SILIPHOKHAM KHATTHALOM     "); textcolor(15);
	printf("\t|\n|    MSSV : "); textcolor(14); printf("1512691                      "); textcolor(15);
	printf("\t|\n|------- NHAN PHIM BAT KI DE TRO LAI -------|\n");
	_getch();
	system("cls");
}
void Option()
{
	resizeConsole(340, 190);
	system("cls");
	printf("|---------- "); textcolor(14); printf("CHON CHUC NANG"); textcolor(15); printf(" ---------|\n");
	printf("|  CHE DO CHOI :                    |\n");
	printf("|     - NGUOI VOI NGUOI :           |\n");
	printf("|     - NGUOI VOI MAY   :           |\n");
	printf("|  NGUOI MOT DANH TRUOC :           |\n");
	printf("|  THOI GIAN DANH       :           |\n");
	printf("|       TRO LAI                     |\n");
	printf("|-----------------------------------|\n");
	gotoxy(27, 5);
	printf("%d", counttime / 1000);
	char **T = new char*[5];
	T[0] = new char[18];
	strcpy(T[0], "NGUOI VOI NGUOI : ");
	T[1] = new char[18];
	strcpy(T[1], "NGUOI VOI MAY   : ");
	T[2] = new char[23];
	strcpy(T[2], "NGUOI MOT DANH TRUOC : ");
	T[3] = new char[25];
	strcpy(T[3], "THOI GIAN DANH       : ");
	T[4] = new char[10];
	strcpy(T[4], "TRO LAI ");
	char choose = NULL;
	int i = 2, temp = 0;
	Choosen(Check);
	char KeyMove[3];
	KeyMove[0] = 72; // UP
	KeyMove[1] = 80; // DOWN
	KeyMove[2] = 13; // ENTER
	textcolor(62);
	gotoxy(8, i);
	printf("%s", T[i - 2]);
	while (choose != KeyMove[0] || choose != KeyMove[1])
	{
		choose = _getch();
		if (choose == KeyMove[0])// Up
		{
			if (i> 2)
			{
				gotoxy(8 - temp, i);
				printf("%s ", T[i - 2]);
				i--;
				if (i == 4 || i == 5) temp = 5;
				else temp = 0;
				gotoxy(8 - temp, i);
				textcolor(62);
				printf("%s", T[i - 2]);
				textcolor(15);
			}
		}
		if (choose == KeyMove[1])//Down
		{
			if (i<7)
				gotoxy(8 - temp, i);
			textcolor(15);
			printf("%s ", T[i - 2]);
			i++;
			if (i > 6) i = 6;
			if (i == 4 || i == 5) temp = 5;
			else temp = 0;
			gotoxy(8 - temp, i);
			textcolor(62);
			printf("%s", T[i - 2]);
			textcolor(15);
		}
		if (choose == KeyMove[2])
		{
			if (i == 6) { MainMenu(); break; }
			if (i == 5)
			{
				int temp;
				gotoxy(26, i);
				printf("   ");
				gotoxy(27, i);
				scanf("%d", &temp);
				counttime = temp * 1000;
				gotoxy(27, i);
				printf("%d", counttime / 1000);
			}
			Check[i - 2] = !Check[i - 2];
			if (i - 2 == 0) Check[1] = !Check[0];
			if (i - 2 == 1) Check[0] = !Check[1];
			Choosen(Check);
		}
	}
}
void Choosen(bool Check[])
{
	textcolor(15);
	for (int j = 0; j < 3; j++)
	{
		gotoxy(30, j + 2);
		if (Check[j] == true)
			printf("YES");
		else printf("NO ");
	}
	if (Check[0] == true) player = 1;
	else player = 2;
	if (Check[1] == true) player = 2;
	else player = 1;
	if (Check[2] == true) turnfirst = 1;
	else
		turnfirst = 2;
}