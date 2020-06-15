#pragma once
#include "Funtion.h"
#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <dos.h>
#include <conio.h>
#include "System.h"
#include <ctime>
#include "Menu.h"
#include "GamePlay.h"
#include <time.h>
extern  int d, c, x, y, turnfirst, counttime;
int row, col, temp = 0, cec = 1, player = 2, amount = 0, turn = turnfirst;
char key = NULL;
extern int Index[19][19];
bool Iswin = NULL;
int countdown;
void Mark()
{
	gotoxy(x, y);

	if (turn == 1)
	{
		textcolor(14);
		printf("X");
	}
	else
	{
		textcolor(11);
		printf("O");
	}
	textcolor(15);
	amount++;
	gotoxy(2 * d + 8, 2 * (c + 2) - 1);
	printf("%d", amount);

}
void Play();

void Reset()
{
	Iswin = NULL;
	turn = turnfirst;
	temp = 0;
	amount = 0;
	key = NULL;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			Index[i][j] = 0;
		}
	}
}
void LoadData(char Game[])
{
	FILE *filein = fopen(Game, "r");
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			Index[i][j] = 0;
		}
	}
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fscanf(filein, "%d", &Index[i][j]);
		}
	}
	fscanf(filein, "%d %d %d", &turn, &player, &amount);
}
struct CurrentTime
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int date = ltm->tm_mday;
	int hour = ltm->tm_hour;
	int minute = ltm->tm_min;
};
bool checkHorizontal()
{
	int countLeft = 0;
	int countRight = 0;
	for (int i = col; i < d; i++)
	{
		if (Index[row][i] == turn) countRight++;
		else break;
	}
	for (int i = col - 1; i >= 0; i--)
	{
		if (Index[row][i] == turn) countLeft++;
		else break;
	}
	if (countLeft + countRight == 5)
	{
		if ((col - countLeft - 1 >= 0 && Index[row][col - countLeft - 1] == 3 - turn) && (col + countRight <= 14 && Index[row][col + countRight] == 3 - turn))
		{
			return false;
		}
	}
	return (countLeft + countRight >= 5);
}
bool checkVertical()
{
	int countTop = 0;
	int countDown = 0;
	for (int i = row; i < c; i++)
	{
		if (Index[i][col] == turn)	countDown++;
		else break;
	}
	for (int i = row - 1; i >= 0; i--)
	{
		if (Index[i][col] == turn) countTop++;
		else break;
	}
	if (countTop + countDown == 5)
	{
		if ((row - countTop - 1 >= 0 && Index[row - countTop - 1][col] == 3 - turn) && (row + countDown <= 14 && Index[row + countDown][col] == 3 - turn))
		{
			return false;
		}
	}
	return (countTop + countDown >= 5);
}
bool checkDiag1()
{
	int count1 = 0;
	int count2 = 0;
	for (int i = row, j = col; i >= 0, j < d; i--, j++)
	{
		if (Index[i][j] == turn) count1++;
		else break;
	}
	for (int i = row + 1, j = col - 1; i < c, j >= 0; i++, j--)
	{
		if (Index[i][j] == turn) count2++;
		else break;
	}

	if (count1 + count2 == 5)
	{
		if ((row - count1 >= 0 && col + count1 <= 14 && Index[row - count1][col + count1] == 3 - turn) && (row + count2 + 1 <= 14 && col - count2 - 1 >= 0 && Index[row + count2 + 1][col - count2 - 1] == 3 - turn))
		{
			return false;
		}
	}
	return (count1 + count2 >= 5);
}
bool checkDiag2()
{
	int count1 = 0;
	int count2 = 0;
	for (int i = row, j = col; i < d, j < c; i++, j++)
	{
		if (Index[i][j] == turn)
		{
			count2++;
		}
		else
		{
			break;
		}
	}
	for (int i = row - 1, j = col - 1; i >= 0, j >= 0; i--, j--)
	{
		if (Index[i][j] == turn)
		{
			count1++;
		}
		else
		{
			break;
		}
	}
	if (count1 + count2 == 5)
	{
		if ((row - count1 - 1 >= 0 && col - count1 - 1 && Index[row - count1 - 1][col - count1 - 1] == 3 - turn) && (row + count2 <= 14 && col + count2 >= 0 && Index[row + count2][col + count2] == 3 - turn))
		{
			return false;
		}
	}
	return (count1 + count2 >= 5);
}
bool Check()
{
	if (checkHorizontal() || checkVertical() || checkDiag1() || checkDiag2())
	{
		return true;
	}
	return false;
}
void Convert(char Time[], int n, char buf[])
{
	char temp[3] = "0";
	if (n / 10 == 0)
	{
		strcat(temp, buf);
		strcpy(buf, temp);
	}
	strcat(Time, buf);
	strcat(Time, "_");
}
void CurrentGame(char Time[])
{
	CurrentTime TimeNow;
	char buf[50];
	sprintf(buf, "%d", TimeNow.hour);
	Convert(Time, TimeNow.hour, buf);
	sprintf(buf, "%d", TimeNow.minute);
	Convert(Time, TimeNow.minute, buf);
	sprintf(buf, "%d", TimeNow.date);
	Convert(Time, TimeNow.date, buf);
	sprintf(buf, "%d", TimeNow.month);
	Convert(Time, TimeNow.month, buf);
	sprintf(buf, "%d", TimeNow.year);
	Convert(Time, TimeNow.year, buf);
	Time[16] = '.';
	strcpy(buf, "CR");
	strcat(Time, buf);
}
void SaveGame()
{
	char Save[20] = "";
	CurrentGame(Save);
	FILE *filein = fopen(Save, "wt");
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fprintf(filein, "%d ", Index[i][j]);
		}
		fputc('\n', filein);
	}
	fprintf(filein, "%d %d %d", turn, player, amount);
	fclose(filein);
	remove("RecentlyCaroGame.CR");
}
void Checkpoint()
{
	row = (y - 3) / 2;
	col = (x - 2) / 4;
	Index[row][col] = turn;
	if (Check())
	{
		Iswin = true;
	}
	key = NULL;
}
void Reload()
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (Index[i][j] == 1)
			{
				gotoxy(4 * j + 2, 2 * i + 3);
				textcolor(14);
				printf("X ");
			}
			if (Index[i][j] == 2)
			{
				gotoxy(4 * j + 2, 2 * i + 3);
				textcolor(11);
				printf("O ");
			}
		}
	}
}
void DrawChessBoard()
{
	textcolor(8);
	printf("\n\n");

	printf("%c", 218);
	for (int i = 0; i < c - 1; i++)
	{
		printf("%c%c%c%c", 196, 196, 196, 194);
	}
	printf("%c%c%c%c\n", 196, 196, 196, 191);
	for (int i = 0; i < d - 1; i++)
	{
		for (int j = 0; j < c + 1; j++)
		{
			printf("%c   ", 179);
		}
		printf("\n%c", 195);
		for (int i = 0; i < c - 1; i++)
		{
			printf("%c%c%c%c", 196, 196, 196, 197);
		}
		printf("%c%c%c%c\n", 196, 196, 196, 180);
	}
	for (int j = 0; j < c + 1; j++)
	{
		printf("%c   ", 179);
	}
	printf("\n%c", 192);
	for (int i = 0; i < c - 1; i++)
	{
		printf("%c%c%c%c", 196, 196, 196, 193);
	}
	printf("%c%c%c%c\n", 196, 196, 196, 217);
	textcolor(15);
	gotoxy(80, 2);
	printf("|------ PHIM CHUC NANG ------|");
	gotoxy(80, 3);
	printf("|- F1  : GIUP DO             |");
	gotoxy(80, 4);
	printf("|- F2  : TRO CHOI MOI        |");
	gotoxy(80, 5);
	printf("|- F3  : LUU TRO CHOI        |");
	gotoxy(80, 6);
	printf("|- F4  : TAI TRO CHOI        |");
	gotoxy(80, 7);
	printf("|- F5  : THONG TIN TRO CHOI  |");
	gotoxy(80, 8);
	printf("|- ESC : MENU CHINH          |");
	gotoxy(80, 9);
	printf("|----------------------------|");
	textcolor(14);
	gotoxy(2 * d, c);
	gotoxy(2 * d - 7, 2 * (c + 2) - 1);
	printf("So nuoc danh : %d", amount);
	gotoxy(2 * d, c);
	gotoxy(2 * d - 7, 1);
	printf(">> GAME CARO <<");
	textcolor(15);
	gotoxy(86, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(86, 22);
	printf("%c Time remain:    %c\n", 179, 179);
	gotoxy(86, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}
void MoveLeft()
{
	if (x == 2) return;
	x = x - 4;
	gotoxy(x, y);
}
void MoveRight()
{
	if (x == 4 * c - 2) return;
	x = x + 4;
	gotoxy(x, y);
}
void MoveUp()
{
	if (y == 3) return;
	y = y - 2;
	gotoxy(x, y);
}
void MoveDown()
{
	if (y == 2 * d + 1) return;
	y = y + 2;
	gotoxy(x, y);
}
void Start()
{
	system("cls");
	resizeConsole(1000, 750);
	DrawChessBoard();
	x = 2 * d; y = c;
	gotoxy(88, 10);
	if (player == 1)printf("NGUOI VS NGUOI");
	else { gotoxy(88, 10); printf("NGUOI VS MAY"); }
}
void SaveTemp()
{
	char Save[20] = "RecentlyCaroGame.CR";
	FILE *filein = fopen(Save, "wt");
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fprintf(filein, "%d ", Index[i][j]);
		}
		fputc('\n', filein);
	}
	fprintf(filein, "%d %d %d", turn, player, amount);
	fclose(filein);
}
void Loadtemp()
{
	char recent[20] = "RecentlyCaroGame.CR";
	LoadData(recent);
	remove("RecentlyCaroGame.CR");
	printf("Den luot nguoi choi %d\n", turn);
	temp = 0;
	system("cls");
	Start();
	Reload();
	Play();
}
void Loadgame()
{
	resizeConsole(600, 300);
	system("cls");
	printf("|------------ LOAD GAME ------------|\n");
	HANDLE hFind, h;
	WIN32_FIND_DATA FindData, Count;
	char **ListGameSaved;
	int i = 0;
	h = FindFirstFile(L"*.CR*", &Count);
	if (h == INVALID_HANDLE_VALUE)
	{
		printf("|    Khong co game nao,nhan phim    |\n");
		printf("|       bat ky de tro ve            |\n");
		printf("|-----------------------------------|\n");
		_getch();
		MainMenu();
	}
	while (FindNextFile(h, &Count)) i++;
	ListGameSaved = new char *[i + 1];
	hFind = FindFirstFile(L"*.CR*", &FindData);
	ListGameSaved[0] = new char[20];
	i = 0;
	wcstombs(ListGameSaved[i], FindData.cFileName, 20);
	printf("| %d : %s           |\n", i, ListGameSaved[i++]);
	while (FindNextFile(hFind, &FindData))
	{
		ListGameSaved[i] = new char[20];
		wcstombs(ListGameSaved[i], FindData.cFileName, 20);
		printf("| %d : %s           |\n", i, ListGameSaved[i++]);
	}
	if (strcmp(ListGameSaved[i - 1], "RecentlyCaroGame.CR") == 0)
	{
		gotoxy(25, i);
		printf("<-RESUME \n");
	}
	int choose;
	printf("|-----------------------------------|\n");
	printf("Nhap game can Load : ", i + 1);
	scanf("%d", &choose);
	printf("Game duoc load : %s\n", ListGameSaved[choose - 1]);
	LoadData(ListGameSaved[choose - 1]);
	printf("Den luot nguoi choi %d\n", turn);
	temp = 0;
	system("cls");
	Start();
	Reload();
	Play();
}
void Move()
{
	gotoxy(x, y);
	char KeyMove[5];
	if (turn == 1)
	{
		KeyMove[0] = 72; // UP
		KeyMove[1] = 80; // DOWN
		KeyMove[2] = 75; // LEFT
		KeyMove[3] = 77; // RIGHT
		KeyMove[4] = 13; // ENTER
	}
	if (turn == 2)
	{
		KeyMove[0] = 'w';
		KeyMove[1] = 's';
		KeyMove[2] = 'a';
		KeyMove[3] = 'd';
		KeyMove[4] = 32;
	}
	while (key != KeyMove[0] || key != KeyMove[1] || key != KeyMove[2] || key != KeyMove[3] || key != KeyMove[4] && !(key = _getch()))
	{
		key = _getch();
		if (key == KeyMove[4])
		{
			return;
		}
		if (key == KeyMove[0])
		{
			MoveUp();
			return;
		}
		if (key == KeyMove[1])
		{
			MoveDown();
			return;
		}
		if (key == KeyMove[2])
		{
			MoveLeft();
			return;
		}
		if (key == KeyMove[3])
		{
			MoveRight();
			return;
		}
		if (key == 59) // 59 : F1
		{
			SaveTemp();
			Help();
			Loadtemp();
			return;
		}
		if (key == 60) // 60 : F2
		{
			gotoxy(80, 10);
			Reset();
			Start();
			Play();
			return;
		}
		if (key == 61) // 61 : F3
		{
			gotoxy(84, 25);
			printf("SAVE GAME SUCCESSFULLY");
			Sleep(1000);
			SaveGame();
			gotoxy(84, 25);
			printf("                      ");
			return;
		}
		if (key == 62) // 62 : F4
		{
			resizeConsole(350, 200);
			SaveTemp();
			Loadgame();
			return;
		}
		if (key == 63) // 63 : F5
		{
			SaveTemp();
			About();
			Loadtemp();
			return;
		}
		if (key == 64 || key == 27) // 64 : F6 , 27 ESC
		{
			SaveTemp();
			MainMenu();
			return;
		}





	}
}
void EraseDrawTurn()
{
	for (int i = 81; i < 117; i++)
	{
		for (int j = 11; j < 20; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	}
}
void DrawTurn()
{
	textcolor(14);
	EraseDrawTurn();
	if (turn == 1) {
		gotoxy(3 + 90, 13);
		printf("X");
		gotoxy(3 + 89, 14);
		printf("X");
		gotoxy(3 + 91, 12);
		printf("x");
		gotoxy(3 + 91, 13);
		printf("X");
		gotoxy(3 + 91, 14);
		printf("X");
		gotoxy(3 + 91, 15);
		printf("X");
		gotoxy(3 + 91, 16);
		printf("X");
		gotoxy(3 + 91, 17);
		printf("X");
		gotoxy(3 + 89, 17);
		printf("X");
		gotoxy(3 + 92, 17);
		printf("X");
		gotoxy(3 + 90, 17);
		printf("X");
		gotoxy(3 + 93, 17);
		printf("X");
	}
	else
	{
		if (player == 1)
		{
			gotoxy(3 + 90, 12);
			printf("O");
			gotoxy(3 + 91, 12);
			printf("O");
			gotoxy(3 + 92, 12);
			printf("O");
			gotoxy(3 + 89, 13);
			printf("O");
			gotoxy(3 + 93, 13);
			printf("O");
			gotoxy(3 + 89, 14);
			printf("O");
			gotoxy(3 + 92, 14);
			printf("O");
			gotoxy(3 + 91, 15);
			printf("O");
			gotoxy(3 + 90, 16);
			printf("O");
			gotoxy(3 + 90, 17);
			printf("O");
			gotoxy(3 + 89, 17);
			printf("O");
			gotoxy(3 + 93, 17);
			printf("O");
			gotoxy(3 + 92, 17);
			printf("O");
			gotoxy(3 + 91, 17);
			printf("O");
		}
		else
		{
			gotoxy(3 + 91, 12);
			printf("C");
			gotoxy(3 + 92, 12);
			printf("C");
			gotoxy(3 + 93, 13);
			printf("C");
			gotoxy(3 + 90, 12);
			printf("C");
			gotoxy(3 + 89, 13);
			printf("C");
			gotoxy(3 + 89, 14);
			printf("C");
			gotoxy(3 + 89, 15);
			printf("C");
			gotoxy(3 + 89, 16);
			printf("C");
			gotoxy(3 + 93, 16);
			printf("C");
			gotoxy(3 + 90, 17);
			printf("C");
			gotoxy(3 + 91, 17);
			printf("C");
			gotoxy(3 + 92, 17);
			printf("C");
			gotoxy(3 + 93, 17);
		}

	}
	textcolor(15);
}
void TimeCount()
{
	gotoxy(x, y);
	textcolor(14);
	Sleep(50);
	countdown = countdown - 50;
	if (countdown % 1000 == 0) {
		gotoxy(101, 22);
		printf("%d ", countdown / 1000);
		gotoxy(x, y);
	}
	if (countdown <= 0)
	{
		turn = 3 - turn;
		DrawTurn();
		gotoxy(81, 11);
		if (player == 2) printf("--- MAY GIANH CHIEN THANG ---\n", turn);
		else printf("-- NGUOI CHOI THU %d THANG --\n", turn);
		key = 13;
		turn = 0;
		_getch();
		Reset();
		MainMenu();
		return;
	}
}
void Play()
{
	countdown = counttime;
	if (amount == 19 * 19)
	{
		DrawTurn();
		gotoxy(81, 11);
		printf("--HAI NGUOI CHOI HOA NHAU--\n");
		turn = 0;
		return;
	}
	if (turn == 1)
	{
		DrawTurn();
		gotoxy(81, 11);
		printf("--- Den luot nguoi choi 1 ---\n");
		gotoxy(81, 18);
		printf("- Dung v,<,>,^ de di chuyen -\n");
		gotoxy(81, 19);
		printf(" ---  Dung ENTER de danh ---\n");

		while (key != 13 || !IsEmptyPosition())
		{

			{
				while (!_kbhit())
				{
					TimeCount();
				}
				Move();
			}
		}

		Mark();
		Checkpoint();
		if (Iswin == true)
		{
			DrawTurn();
			gotoxy(81, 11);
			printf("--- NGUOI CHOI 1 DA THANG ---\n");
			turn = 0;
			return;
		}
		turn = 2;
		countdown = counttime;
		Play();
	}
	if (turn == 2 && player == 1)
	{
		DrawTurn();
		gotoxy(81, 11);
		printf("--- Den luot nguoi choi 2 ---\n");
		gotoxy(81, 18);
		printf("- Dung A,D,S,W de di chuyen -\n");
		gotoxy(81, 19);
		printf(" ---  Dung SPACE de danh ---\n");
		while (key != 32 || !IsEmptyPosition())
		{

			{
				while (!_kbhit())
				{
					TimeCount();
				}
				Move();
			}
		}
		Mark();
		Checkpoint();
		if (Iswin == true)
		{
			DrawTurn();
			gotoxy(81, 11);
			printf("--- NGUOI CHOI 2 DA THANG ---\n");
			turn = 0;
			return;
		}
		countdown = counttime;
		turn = 1;
		Play();
	}
	if (turn == 2 && player == 2)
	{
		DrawTurn();
		gotoxy(81, 11);
		printf("  --- Den luot may danh ---  \n");
		gotoxy(81, 19);
		printf(" --- Waiting for Computer ---\n");
		srand(time(NULL));
		Sleep(rand() % (1200 - 10 + 1) + 10);
		findRoad();
		Mark();
		Checkpoint();
		if (Iswin == true)
		{
			DrawTurn();
			gotoxy(81, 11);
			printf("---  MAY DA CHIEN THANG  ---\n");
			turn = 0;
			return;
		}
		turn = 1;
		Play();
	}
	textcolor(14);
	gotoxy(82, 25);
	printf("NHAN PHIM BAT KI DE QUAY LAI");
	_getch();
	Reset();
	MainMenu();
}
