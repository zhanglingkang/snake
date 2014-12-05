#include "Wall.h"
#include"GotoXY.h"
#include <iostream>
using namespace std;
Wall::Wall()
{
	this->xlength=0;
	this->ylength=0;
}
Wall::Wall(int xlength,int ylength)
{
	this->xlength=xlength;
	this->ylength=ylength;
}
Wall::~Wall(void)
{
}
void Wall::Paint(MyPoint point)
{
	GotoXY gotoXY;
	gotoXY(point);
	//第一行
	for(int i=0;i<xlength;++i)
	{
		if(0==i%2)
			cout<<"#";
		else
			cout<<" ";
	}
	//第二行至倒数第二行
	for(int j=1;j<ylength-1;++j)
	{
		gotoXY(MyPoint(point.x,point.y+j));
		cout<<"#";
		gotoXY(MyPoint(point.x+xlength-1,point.y+j));
		cout<<"#";
	}
	//最后一行
	gotoXY(MyPoint(point.x,point.y+ylength-1));
	for(i=0;i<xlength;++i)
	{
		if(0==i%2)
			cout<<"#";
		else
			cout<<" ";
	}
}
void Wall::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void Wall::SetXlength(int xlength)
{
	this->xlength=xlength;

}
void Wall::SetYlength(int ylength)
{
	this->ylength=ylength;
}
int Wall::GetXlength()
{
	return this->xlength;
}
int Wall::GetYlength()
{
	return this->ylength;
}