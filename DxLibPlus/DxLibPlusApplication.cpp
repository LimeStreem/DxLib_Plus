#include "stdafx.h"
#include "DxLibPlusApplication.h"
#include "WindowUtility.h"
#include "DxDebug.h"
DxLibPlusApplication::DxLibPlusApplication()
{
	fpsManager = new FPSManager();
}


DxLibPlusApplication::~DxLibPlusApplication()
{
	this->Finalize();
	delete fpsManager;
}

void DxLibPlusApplication::Initialize()
{
	ChangeWindowMode(TRUE);
	WindowUtility::SetScreenMode(WindowUtility::GetSafeScreenMode(ScreenModeResolution::SCREEN_RESOLUTION_1280x720, ScreenModeColorBit::COLOR_BIT_32));
	DxLib_Init();
	OnInitialize();
}

void DxLibPlusApplication::Finalize()
{
	OnFinalize();
	DxLib_End();
}

void DxLibPlusApplication::OnInitialize()
{

}

void DxLibPlusApplication::OnFinalize()
{

}

void DxLibPlusApplication::RunMessageLoop()
{
	while (ContinueMessageLoop()&&ProcessMessage()==0)
	{
		DxDebug::OnFrameUpdated();
		fpsManager->FrameUpdated();
		ClearDrawScreen();
		OnPrepareMessageLoop();
		OnPostMessageLoop();
		dxout <<"\n"<< fpsManager->GetFPS();
		DxDebug::Update();
		ScreenFlip();
	}
}

void DxLibPlusApplication::OnPrepareMessageLoop()
{

}

void DxLibPlusApplication::OnPostMessageLoop()
{

}

bool DxLibPlusApplication::ContinueMessageLoop()
{
	return CheckHitKey(KEY_INPUT_ESCAPE) == 0;
}