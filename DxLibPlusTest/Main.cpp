#include <Windows.h>
#include "..\DxLibPlus\DxLibPlusApplication.h"
#include "TestApplication.h"
int WINAPI WinMain(HINSTANCE h1, HINSTANCE h2,  LPSTR lp,int p)
{
	DxLibPlusApplication *app =new TestApplication();
	app->Initialize();
	app->RunMessageLoop();
	app->Finalize();
		delete app;
	return 0;
}