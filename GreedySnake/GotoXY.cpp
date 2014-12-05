#include "GotoXY.h"
GotoXY::GotoXY(void)
{
}
GotoXY::~GotoXY(void)
{
}
void GotoXY::operator()(MyPoint point)
{
	COORD pos;
	pos.X=point.x;  
	pos.Y=point.y;  
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);  
}