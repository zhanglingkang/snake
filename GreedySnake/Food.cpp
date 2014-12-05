#include "Food.h"
#include "GotoXY.h"
#include<iostream>
int Food::foodKindNum=5;
Food::Food(void)
{
	this->foodKind=a;
}
Food::Food(FoodKind foodKind)
{
	this->foodKind=foodKind;
}
int Food::ScoreNum()
{
	return this->foodKind+1-'a';//abcde分别对应12345分
}
Food::~Food(void)
{
}
void Food::Paint(MyPoint point)
{
	GotoXY()(point);
	std::cout<<(char)this->foodKind;

}
void Food::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void Food::SetFoodKind(FoodKind foodKind)
{
	this->foodKind=foodKind;
}