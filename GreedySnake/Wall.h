#pragma once
struct MyPoint
{
	int x,
		y;
	MyPoint(){}
	MyPoint(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	bool operator==(MyPoint point)
	{
		return (this->x==point.x)&&(this->y==point.y);
	}
	MyPoint&operator=(const MyPoint&point)
	{
		this->x=point.x;
		this->y=point.y;
		return *this;
	}
};
class Wall
{
public:
	Wall(void);
	Wall(int xlength,int ylength);
	~Wall(void);
	void Paint(MyPoint point);//墙的绘制,point为墙的左上角顶点在dos窗口下的位置
	void SetColor(unsigned short color);// 设置窗体颜色
	void SetXlength(int xlength);
	void SetYlength(int ylength);
	int GetXlength();
	int GetYlength();
private:
	int xlength,//墙体水平和垂直方向的长度
		ylength;
};

