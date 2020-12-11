#pragma once
#define LE 75
#define RI 77
#define U 72
#define D 80
#define SP 32
#define WINDOW_WIDTH 410
#define WINDOW_HEIGHT 410
#include<stdio.h>
#include <graphics.h>		//图形库
#include <iostream>
#include<mmsystem.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include<random>
#include<string>
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
	int foodx, foody;
	int temx, temy;
	int score = 0;
	int start = 0;
public:
	map(int number);
	void Init();
	void drawsnake();
	void movesnake();
	bool gameover();
	void changedirection();
	void drawfood();
	void eatfood();
	void drawmap();
	void running();
	bool isaccsibleplace(int x,int y);
	void textprint(int type);
	~map();
};
void map::textprint(int type)
{
	int x[3];
	int y[3];
	 x[0] = WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2+10;
	 x[2]=x[1] = (WINDOW_WIDTH + 200) / 2 + 90;
	 y[0] = 140;
	 y[2]=y[1] = WINDOW_HEIGHT / 2;
	switch (type)
	{
	case 0: rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		settextstyle(30, 0, TEXT("微软雅黑"));
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 30, 50, TEXT("贪吃蛇"));
		settextstyle(20, 0, TEXT("微软雅黑"));
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 50, 250, TEXT("按“↑”键:向上移动"));
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 50, 275, TEXT("按“↓”键:向下移动"));
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 50, 300, TEXT("按“→”键:向右移动"));
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 50, 325, TEXT("按“←”键:向左移东"));
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 50, 350, TEXT("按“Space”键:暂停"));
		
		settextstyle(25, 0, TEXT("微软雅黑"));
		settextcolor(YELLOW);
		outtextxy(WINDOW_WIDTH + ((WINDOW_WIDTH + 200) - WINDOW_WIDTH) / 2 - 20, 100, TEXT("分数:"));
		break;
		case 1:settextstyle(65, 0, TEXT("仿宋"));
			outtextxy((WINDOW_WIDTH + 200) / 2 - 120, WINDOW_HEIGHT / 2 - 100, TEXT("游戏失败"));
			settextstyle(33, 0, TEXT("仿宋"));
			settextcolor(YELLOW);
			outtextxy((WINDOW_WIDTH + 200) / 2 - 90, WINDOW_HEIGHT / 2  , TEXT("最终得分："));
			setfillcolor(BLACK);
			fillrectangle((WINDOW_WIDTH + 200) / 2 - 68, WINDOW_HEIGHT / 2 + 45, (WINDOW_WIDTH + 200) / 2 + 80, WINDOW_HEIGHT / 2 + 85);
			settextstyle(33, 0, TEXT("仿宋"));
			settextcolor(RED);

			outtextxy((WINDOW_WIDTH + 200) / 2 - 60, WINDOW_HEIGHT / 2 + 50, TEXT("重新开始"));
			break;
		case 2:
			settextstyle(65, 0, TEXT("仿宋"));
			outtextxy((WINDOW_WIDTH + 200) / 2 - 120, WINDOW_HEIGHT / 2 - 100, TEXT("恭喜过关"));
			settextstyle(33, 0, TEXT("仿宋"));
			settextcolor(YELLOW);
			outtextxy((WINDOW_WIDTH + 200) / 2 - 100, WINDOW_HEIGHT / 2, TEXT("最终得分："));
			setfillcolor(BLACK);
			fillrectangle((WINDOW_WIDTH + 200) / 2 - 58, WINDOW_HEIGHT / 2 + 45, (WINDOW_WIDTH + 200) / 2 + 60, WINDOW_HEIGHT / 2 + 85);
			settextstyle(33, 0, TEXT("仿宋"));
			settextcolor(RED);
			outtextxy((WINDOW_WIDTH + 200) / 2 - 50, WINDOW_HEIGHT / 2 + 50, TEXT("下一关"));

	}
	settextstyle(30, 0, TEXT("微软雅黑"));
	settextcolor(WHITE);
	if(score/10==0)
		outtextxy(x[type]-20, y[type], TEXT("0"));
	else
		outtextxy(x[type] - 20,y[type], TEXT("1"));
	int t = score % 10;
	switch (t)
	{
	case 0:outtextxy(x[type], y[type], TEXT("0")); break;
	case 1:outtextxy(x[type], y[type], TEXT("1")); break;
	case 2:outtextxy(x[type], y[type], TEXT("2")); break;
	case 3:outtextxy(x[type], y[type], TEXT("3")); break;
	case 4:outtextxy(x[type], y[type], TEXT("4")); break;
	case 5:outtextxy(x[type], y[type], TEXT("5")); break;
	case 6:outtextxy(x[type], y[type], TEXT("6")); break;
	case 7:outtextxy(x[type], y[type], TEXT("7")); break;
	case 8:outtextxy(x[type], y[type], TEXT("8")); break;
	case 9:outtextxy(x[type], y[type], TEXT("9")); break;
	default:
		break;
	}
}
map::map(int number)
{
	for (int i = 0; i < 410; i = i + 10)
		for (int j = 0; j < 410; j = j + 10) mappro[i][j] = 0;
	this->number = number;
	
	snakelength = 3;
	snakebody[0].x = 30;
	snakebody[0].y = 10;
	snakebody[1].x = 20;
	snakebody[1].y = 10;
	snakebody[2].x = 10;
	snakebody[2].y = 10;
	direction = RI;
	flag = 0;
	foodx = 0;
	foody = 0;
}
void map::Init()
{
	for (int i = 0; i < 410; i = i + 10)
		for (int j = 0; j < 410; j = j + 10) mappro[i][j] = 0;
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
		  break;
	case 2: 
		for (int i = 0; i < 410; i = i + 10)
			for (int j = 0; j < 410; j = j + 10)
				if (i == 0 || j == 0 || i == 400 || j == 400) mappro[i][j] = 1; break;
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
	foodx = 0;
	foody = 0;
	score = 0;
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
	case U:snakebody[0].y = snakebody[0].y - 10; break;
	case D:snakebody[0].y = snakebody[0].y + 10; break;
	default:
		break;
	}
}
bool map::gameover()
{
	if (mappro[snakebody[0].x][snakebody[0].y] == 1) return true;
	for (int i = 1; i < snakelength; i++)
		if (snakebody[0].x == snakebody[i].x && snakebody[0].y == snakebody[i].y) return true;
	return false;
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
	case SP:start = (start + 1) % 2;
	default:
		break;
	}
}
void map::drawmap()
{
	for (int i = 0; i < 410; i = i + 10)
		for (int j = 0; j < 410; j = j + 10)
			if (mappro[i][j] == 1)
			{

				setfillcolor(RED);
				fillrectangle(i, j, i + 10, j + 10);
			}
}
void map::drawfood()
{
	int x, y;
	if (flag==0)
	{
		while (1)
		{
			x = (rand() % 41) * 10;
			y = (rand() % 41) * 10;
			if (isaccsibleplace(x, y)) break;
		}
		foodx = x;
		foody = y;
		
		flag = 1;
	}
	setfillcolor(GREEN);
	fillroundrect(foodx, foody, foodx + 10, foody + 10, 10, 10);
}
void map::eatfood()
{
	if (snakebody[0].x==foodx&&snakebody[0].y==foody)
	{
		foodx= 0;
		foody = 0;
		flag = 0;
		snakelength++;
		snakebody[snakelength - 1].x = temx;
		snakebody[snakelength - 1].y = temy;
		score++;
	}
}
void map::running()
{
	MOUSEMSG m;
	begin:
	srand((unsigned int)time(NULL));
	Init();
	drawsnake();
	drawfood();
	textprint(0);
	
	while (1)
	{
		while (!_kbhit())
		{
			if (start)
			{
				cleardevice();
				drawmap();
				
				movesnake();

				drawfood();
				if (gameover()) goto end;
				if (score == 5) goto next;
				textprint(0);
				eatfood();
				drawsnake();
				Sleep(100);
			}
		}
		changedirection();
		
	}
end:
	textprint(1);
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= (WINDOW_WIDTH + 200) / 2 - 68 && m.x <= (WINDOW_WIDTH + 200) / 2 + 80 && m.y >= WINDOW_HEIGHT / 2 + 45 && m.y <= WINDOW_HEIGHT / 2 + 85 && m.uMsg == WM_LBUTTONUP)
		{
			cleardevice();
			goto begin;
		}
	}
next:
	textprint(2);
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= (WINDOW_WIDTH + 200) / 2 - 58 && m.x <= (WINDOW_WIDTH + 200) / 2 + 60 && m.y >= WINDOW_HEIGHT / 2 + 45 && m.y <= WINDOW_HEIGHT / 2 + 85 && m.uMsg == WM_LBUTTONUP)
		{
			number = number + 1;
			cleardevice();
			goto begin;
		}
	}
	while (1);
}
map::~map()
{
	delete[]mappro;
	delete[]snakebody;
}
bool map::isaccsibleplace(int x,int y)
{
	if (mappro[x][y] == 1) return false;
	for (int i = 0; i < snakelength; i++)
		if (snakebody[i].x == x && snakebody[i].y == y) return false;
	return true;
}
int main()
{
	map A(1);
	A.running();
	return 0;
}