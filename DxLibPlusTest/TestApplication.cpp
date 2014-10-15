#include "TestApplication.h"
#include "../DxLibPlus/WindowUtility.h"
#include "../DxLibPlus/DxDebug.h"
#include "../DxLibPlus/Vector2.h"
TestApplication::TestApplication()
{
}

TestApplication::~TestApplication()
{
}

void TestApplication::OnInitialize()
{
	ScreenMode state=WindowUtility::GetScreenMode();
}

void TestApplication::OnPrepareMessageLoop()
{
	Vector2 vec = Vector2(2, 3);
	dout << vec <<"\n"<< std::endl;
}