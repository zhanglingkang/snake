#include "Game.h"
#include<iostream>
#include<cmath>
#include<ctime>
#include <conio.h>
using namespace std;
Game::Game(void)
{
	this->OutTip();
	this->Init();
}
Game::~Game(void)
{
}
void Game::Start()
{
	GotoXY()(this->currentScorePos);
	cout<<this->currentScore;
	GotoXY()(this->maxScorePos);
	cout<<this->maxScore;
	while(true)
	{	
		if(kbhit())
		{
			char ch=getch();
			if(('w'==ch||'s'==ch||'a'==ch||'d'==ch)&&!this->IsContrary(ch))
			{
				snake.Move(ch,false);
				this->OperationAfterMove();
				currentDirection=ch;
			}
		}
		else
		{
			if(this->currentScore<1)
				Sleep(1000);
			else	
				Sleep(1000/sqrt((float)this->currentScore));//得分越多速度越快
			snake.Move(currentDirection,false);
			this->OperationAfterMove();
		}
	}
}
void Game::OutTip()
{
		//设置窗口大小
	HANDLE hOut ;
	CONSOLE_SCREEN_BUFFER_INFO csbi ;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE) ;
	GetConsoleScreenBufferInfo(hOut, &csbi) ;
	this->bufferSize.X=80;
	this->bufferSize.Y=25;																
	::SetConsoleScreenBufferSize(hOut, this->bufferSize);
	wall.SetColor(9);
	GotoXY()(MyPoint(0,10));
	cout<<"---------------------------------欢迎玩贪吃蛇游戏-------------------------------"<<endl<<endl;
	cout<<"-----------------------------------游戏说明如下---------------------------------"<<endl<<endl;
	cout<<"-------------w:上-------------s:下--------------a:左-------------d:右-----------"<<endl<<endl;
	cout<<"---------每获得10分,大蛇成长一节----------------分数越多,大蛇跑的越快-----------"<<endl<<endl;
	cout<<"---------abcde为食物,对应12345分-------------方块为障碍物，碰到一次减2分--------"<<endl<<endl;
	cout<<"-----------------开始:s-------------------------------退出:q--------------------"<<endl<<endl;
	while(true)
	{
		if(kbhit())
		{
			char ch=getch();
			if('s'==ch)
			{
				return;
			}
			else if('q'==ch)
			{
				exit(0);
			}
		}
	}
}
bool Game::IsContrary(char direction)
{
	if(abs(this->currentDirection-direction)=='w'-'s'||abs(this->currentDirection-direction)=='d'-'a')
		return true;
	return false;

}
void Game::Init()
{
	//屏幕最上方显示当前得分与最高得分
	system("cls");
	GotoXY()(MyPoint(0,0));
	cout<<"当前得分:";
	this->currentScorePos.x=9;
	this->currentScorePos.y=0;
	GotoXY()(MyPoint(69,0));
	cout<<"最高得分:";
	this->maxScorePos.x=77;
	this->maxScorePos.y=0;
	this->wallPoint.x=0;
	this->wallPoint.y=1;
	//设置墙
	wall.SetXlength(79);
	wall.SetYlength(20);
	wall.SetColor(10);
	wall.Paint(this->wallPoint);
	//大蛇
	snake=Snake();
	snake.SetColor(rand()%15+1);
	snake.Paint(MyPoint(bufferSize.X/2+this->wallPoint.x,bufferSize.Y/2+this->wallPoint.y));
	//食物
	srand((unsigned)time(NULL));
	for(int i=0;i<this->foodnum;++i)
	{
		this->food[i].SetFoodKind(Food::FoodKind(rand()%Food::foodKindNum+Food::a));
		foodPos[i].x=this->wallPoint.x+rand()%(wall.GetXlength()-2)+1;
		foodPos[i].y=this->wallPoint.y+rand()%(wall.GetYlength()-2)+1;
		food[i].SetColor(rand()%15+1);
		food[i].Paint(foodPos[i]);
	}
	//障碍物
	for(i=0;i<this->obstaclenum;++i)
	{
		obstaclePos[i].x=this->wallPoint.x+rand()%(wall.GetXlength()-2)+1;
		obstaclePos[i].y=this->wallPoint.y+rand()%(wall.GetYlength()-2)+1;
		obstacle[i].SetColor(10);
		obstacle[i].Paint(obstaclePos[i]);
	}
	//默认的大蛇的当前行进方向
	this->currentDirection='w';
	this->currentScore=0;
	this->maxScore=0;
}
bool Game::IsHitWall()
{
	MyPoint tempPoint=this->wallPoint;
	//检测是否撞到上边和下边
	for(int i=0;i<wall.GetXlength();++i)
	{	
		if(snake.isHitPoint(tempPoint))
			return true;
		tempPoint.y+=wall.GetYlength()-1;
		if(snake.isHitPoint(tempPoint))
			return true;
		++tempPoint.x;
		tempPoint.y-=wall.GetYlength()-1;	
	}
	//检测是否撞到左边和右边
	tempPoint=this->wallPoint;
	for(i=0;i<wall.GetYlength()-1;++i)
	{
		++tempPoint.y;
		if(snake.isHitPoint(tempPoint))
			return true;
		tempPoint.x+=wall.GetXlength()-1;
		if(snake.isHitPoint(tempPoint))
			return true;
		tempPoint.x-=wall.GetXlength()-1;
	}
	return false;
}
int Game::IsHitObstacle()
{
	for(int i=0;i<this->obstaclenum;++i)
	{
		if(snake.isHitPoint(this->obstaclePos[i]))
			return i;
	}
	return -1;
}
int Game::IsHitFood()
{
	for(int i=0;i<this->foodnum;++i)
	{
		if(snake.isHitPoint(this->foodPos[i]))
		{
			return i;
		}
	}
	return -1;
}
void Game::OperationAfterMove()
{
	int index=this->IsHitFood();
	if(-1!=index)
	{
		this->currentScore+=this->food[index].ScoreNum();
		GotoXY()(this->currentScorePos);
		cout<<this->currentScore;
		cout<<"   ";
		//每增长到10的倍数分以后，大蛇就成长一次
		if(this->currentScore/10>(this->currentScore-food[index].ScoreNum())/10)
		{
			snake.Move(this->currentDirection,true);
		}
		this->food[index].SetFoodKind(Food::FoodKind(rand()%Food::foodKindNum+Food::a));
		this->foodPos[index].x=this->wallPoint.x+rand()%(wall.GetXlength()-2)+1;
		this->foodPos[index].y=this->wallPoint.y+rand()%(wall.GetYlength()-2)+1;
		this->food[index].SetColor(rand()%15+1);
		this->food[index].Paint(foodPos[index]);
		return;
	}
	index=this->IsHitObstacle();
	if(-1!=index)
	{
		this->currentScore-=2;
		GotoXY()(this->currentScorePos);
		cout<<this->currentScore;
		this->obstaclePos[index].x=this->wallPoint.x+rand()%(wall.GetXlength()-2)+1;
		this->obstaclePos[index].y=this->wallPoint.y+rand()%(wall.GetYlength()-2)+1;
		this->obstacle[index].SetColor(rand()%15+1);
		this->obstacle[index].Paint(obstaclePos[index]);
		return;
	}
	if(snake.isHitBody()||this->IsHitWall())
	{
		this->End();
	}
}
void Game::End()
{
	system("cls");
	wall.SetColor(rand()%15+1);
	GotoXY()(MyPoint(0,this->bufferSize.Y/2));
	cout<<"------------------------------------游戏结束------------------------------------"<<endl<<endl;
	cout<<"-------------------------------你的得分记录是"<<this->currentScore<<"----------------------------------"<<endl<<endl;
	if(this->currentScore>this->maxScore)
	{	
		this->maxScore=this->currentScore;
		cout<<"-----------------------------恭喜你,破了得分记录--------------------------------"<<endl<<endl;
	}
	cout<<"----------y:继续-------------------------------------------其他任意键结束-------"<<endl<<endl;
	while(true)
	{
		if(kbhit())
		{
			if('y'==getch())
			{
				system("cls");
				int temp=this->maxScore;
				this->Init();
				this->maxScore=temp;
				this->Start();
			}
			else
			{
				exit(0);
			}
		}
	}
}