#include <Windows.h>
#include "..\DxLibPlus\DxLibPlusApplication.h"
int WINAPI WinMain(HINSTANCE h1, HINSTANCE h2,  LPSTR lp,int p)
{
	DxLibPlusApplication app = DxLibPlusApplication();
	app.Initialize();
	return 0;
}