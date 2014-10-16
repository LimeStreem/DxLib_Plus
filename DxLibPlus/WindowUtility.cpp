#include "stdafx.h"
#include "WindowUtility.h"
#include "boost\format.hpp"


WindowUtility::WindowUtility()
{
}


WindowUtility::~WindowUtility()
{
}

HRESULT WindowUtility::SetWindowTitle(std::string str)
{
	return SetWindowText(str.c_str()) == 0 ? S_OK :E_FAIL;
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

HRESULT WindowUtility::SetWindowMode(bool isWindowed)
{
	return ChangeWindowMode(isWindowed) == 0 ? S_OK : E_FAIL;
}

bool WindowUtility::GetWindowMode()
{
	return GetWindowModeFlag();
}

ScreenMode WindowUtility::GetSafeScreenMode(ScreenModeResolution resolutionType, ScreenModeColorBit colorBit)
{
	ScreenMode state = ScreenMode();
	switch (resolutionType)
	{
		case SCREEN_RESOLUTION_640x480:
			state.sizeX = 640;
			state.sizeY = 480;
			break;
		case SCREEN_RESOLUTION_800x600:
			state.sizeX = 800;
			state.sizeY = 600;
			break;
		case SCREEN_RESOLUTION_1024x768:
			state.sizeX = 1024;
			state.sizeY = 768;
			break;
		case SCREEN_RESOLUTION_1280x720:
			state.sizeX = 1280;
			state.sizeY = 720;
			break;
		case SCREEN_RESOLUTION_1280x1024:
			state.sizeX = 1280;
			state.sizeY = 1024;
			break;
		case SCREEN_RESOLUTION_1920x1080:
			state.sizeX = 1920;
			state.sizeY = 1080;
			break;
		default:
			return GetSafeScreenMode(ScreenModeResolution::SCREEN_RESOLUTION_640x480, colorBit);
	}
	switch (colorBit)
	{
		case COLOR_BIT_16:
			state.colorBit = 16;
			break;
		case COLOR_BIT_32:
			state.colorBit = 32;
			break;
		default:
			return GetSafeScreenMode(resolutionType, ScreenModeColorBit::COLOR_BIT_32);
	}
	return state;
}

ScreenMode WindowUtility::GetScreenMode()
{
	ScreenMode state = ScreenMode();
	GetScreenState(&state.sizeX, &state.sizeY, &state.colorBit);
	return state;
}

HRESULT WindowUtility::SetScreenMode(ScreenMode& state)
{
	return SetGraphMode(state.sizeX, state.sizeY, state.colorBit) == DX_CHANGESCREEN_OK ? S_OK : E_FAIL;
}

HRESULT WindowUtility::SetWindowIconID(int id)
{
	return DxLib::SetWindowIconID(id) == 0 ? S_OK : E_FAIL;
}

std::string ScreenMode::ToString()const
{
	return (boost::format("ScreenMode[解像度(Resolution)=(%1% * %2%)][カラービット数=%3%]")%this->sizeX%this->sizeY%this->colorBit).str();
}