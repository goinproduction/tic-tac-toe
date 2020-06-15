#include "stdafx.h"
#include "GamePlay.h"
#include "Funtion.h"
#include "System.h"
extern  int x, y, d, c, turn, amount;
extern int Index[19][19];
unsigned int Attack[] = { 0, 15, 225, 225 * 19, 225 * 19 * 19, 225 * 19 * 19 * 19 };
unsigned int Defense[] = { 0, 14, 220, 3300, 50000, 740000 };
long attackHorizontal(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexcol + 1; i < d; i++)
	{
		if (Index[indexrow][i] == turn)  count1++;
		else
		{
			if (Index[indexrow][i] == 3 - turn)
			{
				count2++;
				break;
			}
			else break;
		}
	}
	for (int i = indexcol - 1; i >= 0; i--)
	{
		if (Index[indexrow][i] == turn) count1++;
		else
		{
			if (Index[indexrow][i] == 3 - turn)
			{
				count2++; break;
			}
			else break;
		}
	}
	if (count2 == 2)
	{
		return 0;
	}
	if (count1 == 1) return (Attack[count1] - Defense[count2] + 10);
	return(Attack[count1] - Defense[count2]);
}
long attackVertical(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexrow + 1; i < d; i++)
	{
		if (Index[i][indexcol] == turn)
		{
			count1++;
		}
		else
		{
			if (Index[i][indexcol] == 3 - turn) {
				count2++; break;
			}
			else break;
		}
	}
	for (int i = indexrow - 1; i >= 0; i--)
	{
		if (Index[i][indexcol] == turn)
		{
			count1++;
		}
		else
		{
			if (Index[i][indexcol] == 3 - turn)
			{
				count2++; break;
			}
			else break;
		}
	}
	if (count2 == 2) return 0;
	if (count1 == 1) return (Attack[count1] - Defense[count2] + 10);
	return(Attack[count1] - Defense[count2]);
}
long attackDiag1(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexrow - 1, j = indexcol + 1; i >= 0, j < d; i--, j++)
	{
		if (Index[i][j] == turn) count1++;
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	for (int i = indexrow + 1, j = indexcol - 1; i < d, j >= 0; i++, j--)
	{
		if (Index[i][j] == turn) count1++;
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	if (count2 >= 2) return 0;
	if (count1 == 1) return (Attack[count1] - Defense[count2] + 10);
	return(Attack[count1] - Defense[count2]);
}
long attackDiag2(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexrow + 1, j = indexcol + 1; i < d, j < d; i++, j++)
	{
		if (Index[i][j] == turn) count1++;
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	for (int i = indexrow - 1, j = indexcol - 1; i >= 0, j >= 0; i--, j--)
	{
		if (Index[i][j] == turn) count1++;
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	if (count2 >= 2) return 0;
	if (count1 == 1) return (Attack[count1] - Defense[count2] + 10);
	return(Attack[count1] - Defense[count2]);
}
long defenseHorizontal(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexcol + 1; i < d; i++)
	{
		if (Index[indexrow][i] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[indexrow][i] == 3 - turn) { count2++; }
			else break;
		}
	}
	for (int i = indexcol - 1; i >= 0; i--)
	{
		if (Index[indexrow][i] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[indexrow][i] == 3 - turn)  count2++;
			else break;
		}
	}
	if (count1 == 2)
	{
		return 0;
	}
	if (count1 == 1) return (Defense[count2] - Attack[count1 + 1]);
	return(Defense[count2 + 1] - Attack[count1]);
}
long defenseVertical(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexrow + 1; i < d; i++)
	{
		if (Index[i][indexcol] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[i][indexcol] == 3 - turn) count2++;
			else break;
		}
	}
	for (int i = indexrow - 1; i >= 0; i--)
	{
		if (Index[i][indexcol] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[i][indexcol] == 3 - turn) count2++;
			else break;
		}
	}
	if (count1 == 2) return 0;
	if (count1 == 1) return (Defense[count2] - Attack[count1 + 1]);
	return(Defense[count2 + 1] - Attack[count1]);
}
long defenseDiag1(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexrow - 1, j = indexcol + 1; i >= 0, j < d; i--, j++)
	{
		if (Index[i][j] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	for (int i = indexrow + 1, j = indexcol - 1; i < d, j >= 0; i++, j--)
	{
		if (Index[i][j] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	if (count1 == 2) return 0;
	if (count1 == 1) return (Defense[count2] - Attack[count1 + 1]);
	return(Defense[count2 + 1] - Attack[count1]);
}
long defenseDiag2(int indexrow, int indexcol)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = indexrow + 1, j = indexcol + 1; i < d, j < d; i++, j++)
	{
		if (Index[i][j] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[i][j] == 3 - turn)
				count2++;
			else
				break;
		}
	}
	for (int i = indexrow - 1, j = indexcol - 1; i >= 0, j >= 0; i--, j--)
	{
		if (Index[i][j] == turn)
		{
			count1++;
			break;
		}
		else
		{
			if (Index[i][j] == 3 - turn) count2++;
			else break;
		}
	}
	if (count1 == 2) return 0;
	if (count1 == 1) return (Defense[count2] - Attack[count1 + 1]);
	return(Defense[count2 + 1] - Attack[count1]);
}
void findRoad()
{
	int max = 0;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{
			if (Index[i][j] == 0)
			{
				long attack = attackVertical(i, j) + attackHorizontal(i, j) + attackDiag1(i, j) + attackDiag2(i, j);
				long defense = defenseVertical(i, j) + defenseHorizontal(i, j) + defenseDiag1(i, j) + defenseDiag2(i, j);
				long atOrde = attack > defense ? attack : defense;
				if (amount == 0)
				{
					x = 2 * d;
					y = c;
					return;
				}
				if (atOrde >= max)
				{
					max = atOrde;
					x = 4 * j + 2;
					y = 2 * i + 3;
				}
			}
		}
	}
}
