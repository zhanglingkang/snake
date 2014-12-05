#pragma once
#include"Wall.h"
#include"LinkList.cpp"
class Snake
{
public:
	Snake(void);
	~Snake(void);
	void Move(char direction,bool isGrop);//wsad分别代表上下左右,isGrop表示大蛇是否成长了
	void Paint(MyPoint point);//point为蛇头位置,默认大蛇是直的且准备向上走，供用户使用
	void SetColor(unsigned short color);
	bool isHitBody() ;			//判断蛇头是否撞到身体
	bool isHitPoint(MyPoint point);//判断蛇头是否与该点碰撞;
private:
	void Paint();                  //将移动后的大蛇绘制，供内部使用  
	LinkList<MyPoint> snakePos;     //大蛇现在所在屏幕上的位置
};

