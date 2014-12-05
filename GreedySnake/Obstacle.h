#pragma once
#include"Wall.h"
class Obstacle
{
public:
	Obstacle(void);
	~Obstacle(void);
	void Paint(MyPoint point);//将障碍物绘制在point处
	void SetColor(unsigned short color);       
};

