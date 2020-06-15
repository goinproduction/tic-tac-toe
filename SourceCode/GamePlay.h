#pragma once
struct Point
{
	int x;
	int y;
};
long attackHorizontal(int indexrow, int indexcol);
long attackVertical(int indexrow, int indexcol);
long attackDiag1(int indexrow, int indexcol);
long attackDiag2(int indexrow, int indexcol);
long defenseHorizontal(int indexrow, int indexcol);
long defenseVertical(int indexrow, int indexcol);
long defenseDiag1(int indexrow, int indexcol);
long defenseDiag2(int indexrow, int indexcol);
void findRoad();
