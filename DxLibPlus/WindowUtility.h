#pragma once
#include "DxLibPlusObject.h"
enum  ScreenModeResolution
{
	SCREEN_RESOLUTION_640x480,
	SCREEN_RESOLUTION_800x600,
	SCREEN_RESOLUTION_1024x768,
	SCREEN_RESOLUTION_1280x1024,
	SCREEN_RESOLUTION_1280x720,
	SCREEN_RESOLUTION_1920x1080
};
enum ScreenModeColorBit
{
	COLOR_BIT_16=16,
	COLOR_BIT_32=32
};
class ScreenMode:public DxLibPlusObject
{
public:
	int sizeX;
	int sizeY;
	int colorBit;
	virtual std::string ToString()const;
};
class WindowUtility
{
private:
	WindowUtility();
	~WindowUtility();
public:
	static HRESULT SetWindowTitle(std::string title);
	static HRESULT SetWindowMode(bool isWindowed);
	static std::string GetWindowTitle();
	static bool GetWindowMode();
	static HRESULT SetScreenMode(ScreenMode& state);
	static ScreenMode GetScreenMode();
	static ScreenMode GetSafeScreenMode(ScreenModeResolution resolutionType,ScreenModeColorBit colorBit);
	static HRESULT SetWindowIconID(int id);
};

