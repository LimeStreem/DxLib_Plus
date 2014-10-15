#include "stdafx.h"
#include "DxLibPlusApplication.h"
#include "WindowUtility.h"

DxLibPlusApplication::DxLibPlusApplication()
{
}


DxLibPlusApplication::~DxLibPlusApplication()
{
	this->Finalize();
}

void DxLibPlusApplication::Initialize()
{
	ChangeWindowMode(TRUE);
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
		ClearDrawScreen();
		OnPrepareMessageLoop();
		OnPostMessageLoop();
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