#pragma once
#include "Wall.h"
#include"Food.h"
#include"Obstacle.h"
#include"Snake.h"
#include"GotoXY.h"
#include <stdlib.h>
class Game
{
public:
	Game(void);
	~Game(void);
	void Start();
	void End();
public:
	void OutTip();//输出提示性语句
private:	
	enum {foodnum=10,obstaclenum=10};//食物数目.障碍物数目
	Wall wall;
	Snake snake;
	Food food[foodnum];
	MyPoint foodPos[foodnum];
	Obstacle obstacle[obstaclenum];
	MyPoint obstaclePos[obstaclenum];
	MyPoint currentScorePos;//显示当前分数的位置
	MyPoint maxScorePos;   //显示最高分的位置
	int currentScore;
	int maxScore;
	char currentDirection;//大蛇的当前行走方向
	MyPoint wallPoint;//墙的左上角的位置
	COORD bufferSize; //设置窗口大小
private:
	void OperationAfterMove();//大蛇每走一步应该做的操作
	bool IsHitWall();//判断大蛇是否撞墙
	int IsHitObstacle();//判断大蛇是否撞障碍物,-1表示没撞到，否则表示撞到了第几个障碍物
	int IsHitFood();//判断大蛇是否吃到食物,返回-1表示没吃到，否则表示吃到了第几个食物
	void Init();
	bool IsContrary(char direction);//检测direction与大蛇的当前行进方向是否相反
};
