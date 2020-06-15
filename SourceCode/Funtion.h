#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <dos.h>
#include <string.h>
#include <conio.h>
#include <ctime>
struct TOADO
{
	int x, y;
};
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
void SaveTemp();
void Checkpoint();
void Loadgame();
void SaveGame();
void Start();
void LoadData(char Game[]);
void CurrentGame(char Time[]);
void Convert(char Time[], int n, char buf[]);
void DrawChessBoard();
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();
void Move();
void Play();
void Reset();