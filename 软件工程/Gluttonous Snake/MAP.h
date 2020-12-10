#pragma once
#define LE 75
#define RI 77
#define U 72
#define D 80
#define WINDOW_WIDTH 410
#define WINDOW_HEIGHT 410
#include<stdio.h>
#include <graphics.h>		//Í¼ÐÎ¿â
#include <iostream>
#include<mmsystem.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include<random>
#pragma comment(lib,"winmm.lib")
#pragma once
struct body
{
	int x;
	int y;
};
class map
{
	int number;
	int mappro[410][410];
	body snakebody[200];
	int snakelength;
	int direction;
	int flag;
	int temx, temy;
	int score = 0;
public:
	map(int number);
	void Init();
	void drawsnake();
	void movesnake();
	bool iscrash();
	bool iseatitself();
	void changedirection();
	void drawfood();
	void eatfood();
	void running();
	~map();
};

map::map(int number)
{
	this->number = number;
	switch (number)
	{
	case 1: for (int i = 0; i < 410; i = i + 10)
		for (int j = 0; j < 410; j = j + 10)
		{
			if (i == 0 || j == 0 || i == 400 || j == 400) mappro[i][j] = 1;
			if (i == 60 && j >= 60 && j <= 160) {
				mappro[i][j] = 1; mappro[i + 280][j] = 1; mappro[i][j + 180] = 1; mappro[i + 280][j + 180] = 1;
				mappro[j][i] = 1; mappro[j][i + 280] = 1; mappro[j + 180][i] = 1; mappro[j + 180][i + 280] = 1;
			}

		}
	default:
		break;
	}
	snakelength = 3;
	snakebody[0].x = 30;
	snakebody[0].y = 10;
	snakebody[1].x = 20;
	snakebody[1].y = 10;
	snakebody[2].x = 10;
	snakebody[2].y = 10;
	direction = RI;
	flag = 0;
}
void map::Init()
{
	initgraph(640, 410);
	setbkcolor(BLACK);
	for (int i = 0; i < 410; i = i + 10)
		for (int j = 0; j < 410; j = j + 10)
			if (mappro[i][j] == 1)
			{

				setfillcolor(RED);
				fillrectangle(i, j, i + 10, j + 10);
			}
}
void map::drawsnake()
{
	for (int i = 0; i < snakelength; i++)
	{
		if (i == 0)
		{
			setfillcolor(YELLOW);
			fillrectangle(snakebody[i].x, snakebody[i].y, snakebody[i].x + 10, snakebody[i].y + 10);
		}
		else
		{
			setfillcolor(WHITE);
			fillrectangle(snakebody[i].x, snakebody[i].y, snakebody[i].x + 10, snakebody[i].y + 10);
		}
	}
}
void map::movesnake()
{
	temx = snakebody[snakelength - 1].x;
	temy = snakebody[snakelength - 1].y;
	for (int i = snakelength - 1; i > 0; i--)
	{
		snakebody[i].x = snakebody[i - 1].x;
		snakebody[i].y = snakebody[i - 1].y;
	}
	switch (direction)
	{
	case RI: snakebody[0].x = snakebody[0].x + 10; break;
	case LE:snakebody[0].x = snakebody[0].x - 10; break;
	case U:snakebody[0].y = snakebody[0].y + 10; break;
	case D:snakebody[0].y = snakebody[0].y - 10; break;
	default:
		break;
	}
}
bool map::iscrash()
{
	if (mappro[snakebody[0].x][snakebody[0].y] == 1) return false;
	else return true;
}
bool map::iseatitself()
{
	for (int i = 0; i < snakelength; i++)
		if (snakebody[0].x == snakebody[i].x && snakebody[0].y == snakebody[i].y) return false;
	return true;
}
void map::changedirection()
{
	int move = _getch();
	switch (move)
	{
	case RI:if (direction != LE) direction = move; break;
	case LE:if (direction != RI) direction = move; break;
	case U:if (direction != D) direction = move; break;
	case D:if (direction != U) direction = move; break;
	default:
		break;
	}
}
void map::drawfood()
{
	int x, y;
	int f;
	if (flag == 0)
	{
		do
		{
			f = 0;
			x = (rand() % 40) * 10;
			y = (rand() % 40) * 10;
			if (mappro[x][y] == 1) f = 1;
			for (int i = 0; i < snakelength; i++)
				if (snakebody[i].x == x && snakebody[i].y == y) f = 1;
		} while (f);
		mappro[x][y] = 2;
	}
	setfillcolor(GREEN);
	fillroundrect(x, y, x + 10, y + 10, 10, 10);
}
void map::eatfood()
{
	if (mappro[snakebody[0].x][snakebody[0].y] == 2)
	{
		mappro[snakebody[0].x][snakebody[0].y] = 0;
		flag = 0;
		snakelength++;
		snakebody[snakelength - 1].x = temx;
		snakebody[snakelength - 1].y = temy;
		score++;
	}
}
void map::running()
{
	srand((unsigned int)time(NULL));
	Init();
	drawsnake();
	char buf[100];
	while (1)
	{
		while (!_kbhit())
		{
			drawfood();
			movesnake();
			if (iscrash() || iseatitself()) goto end;
			rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
			settextstyle(30, 0, TEXT("Î¢ÈíÑÅºÚ"));
			outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 30, 50, TEXT("Ì°³ÔÉß"));
			settextstyle(25, 0, TEXT("Î¢ÈíÑÅºÚ"));
			settextcolor(YELLOW);
			outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 30, 100, TEXT("·ÖÊý:"));
			settextstyle(30, 0, TEXT("Î¢ÈíÑÅºÚ"));
			settextcolor(WHITE);
			_itoa_s(score, buf, _countof(buf), 10);
			outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 30, 150, LPCTSTR(buf));
			eatfood();
			drawsnake();
		}
		changedirection();
	}
end:
	settextstyle(65, 0, TEXT("·ÂËÎ"));
	outtextxy((WINDOW_WIDTH + 200) / 2 - 120, WINDOW_HEIGHT / 2 - 50, TEXT("ÓÎÏ·½áÊø"));
	settextstyle(33, 0, TEXT("·ÂËÎ"));
	settextcolor(YELLOW);
	outtextxy((WINDOW_WIDTH + 200) / 2 - 120, WINDOW_HEIGHT / 2 + 20, TEXT("×îÖÕµÃ·Ö"));
	outtextxy((WINDOW_WIDTH + 200) / 2, WINDOW_HEIGHT / 2 + 20, LPCTSTR(buf));
}
map::~map()
{
	delete[]mappro;
	delete[]snakebody;
}

