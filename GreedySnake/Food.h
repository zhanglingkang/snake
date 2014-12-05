#pragma once
#include "Wall.h"
class Food
{
public:
	enum FoodKind //食物种类
	{
		a='a',b,c,d,e
	};
	Food(void);
	explicit Food(FoodKind foodKind);
	~Food(void);
	int ScoreNum();   //此食物的分数
	void Paint(MyPoint point);//将食物绘制在point处
	void SetColor(unsigned short color);
	static  int foodKindNum;
	void SetFoodKind(FoodKind foodKind);
private:
	FoodKind foodKind;
};
