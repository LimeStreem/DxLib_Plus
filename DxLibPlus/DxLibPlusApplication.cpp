#include "stdafx.h"
#include "DxLibPlusApplication.h"
#include "WindowUtility.h"

DxLibPlusApplication::DxLibPlusApplication()
{
}


DxLibPlusApplication::~DxLibPlusApplication()
{
}

void DxLibPlusApplication::Initialize()
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	OnInitialize();
}