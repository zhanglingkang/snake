#include "Obstacle.h"
#include"GotoXY.h"
#include<iostream>
using namespace std;

Obstacle::Obstacle(void)
{
}


Obstacle::~Obstacle(void)
{
}
void Obstacle::Paint(MyPoint point)
{
	GotoXY()(point);
	cout<<char(2);
}
void Obstacle::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}