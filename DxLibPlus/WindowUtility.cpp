#include "stdafx.h"
#include "WindowUtility.h"


WindowUtility::WindowUtility()
{
}


WindowUtility::~WindowUtility()
{
}

void WindowUtility::SetWindowTitle(std::string str)
{
	SetWindowText(str.c_str());
}

std::string WindowUtility::GetWindowTitle()
{
	int n = GetWindowTextLength(GetMainWindowHandle());
	TCHAR* titleCache = new TCHAR[n];
	GetWindowText(GetMainWindowHandle(), titleCache, n);
	std::string buffer = std::string(titleCache);
	delete [] titleCache;
	return buffer;
}

void WindowUtility::SetWindowMode(bool isWindowed)
{
	ChangeWindowMode(isWindowed);
}

bool WindowUtility::GetWindowMode()
{
	return GetWindowModeFlag();
}