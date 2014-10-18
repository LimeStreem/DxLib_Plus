#pragma once
#include <DxLibPlusApplication.h>
class TestApplication :
	public DxLibPlusApplication
{
public:
	TestApplication();
	~TestApplication();
	void OnInitialize();
	void OnPrepareMessageLoop();
};

