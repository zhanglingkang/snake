#pragma once
#include <windows.h>
#include"Wall.h"
class GotoXY
{
public:
	GotoXY(void);
	~GotoXY(void);
	void operator()(MyPoint point);
};

