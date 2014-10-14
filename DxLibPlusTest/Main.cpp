#include <Windows.h>
#include "..\DxLibPlus\Vector2.h"
#include "..\DxLibPlus\Direction2.h"
int WINAPI WinMain(HINSTANCE h1, HINSTANCE h2,  LPSTR lp,int p)
{
	Vector2 vec = Vector2(1, 10);
	Vector2 vec2 = Vector2(1, 2);
	std::string l = Direction2(1, 1).ToString();
	return 0;
}