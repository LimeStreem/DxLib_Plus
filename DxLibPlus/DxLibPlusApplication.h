#pragma once
#include "DxLibPlusObject.h"
class DxLibPlusApplication :
	public DxLibPlusObject
{
public:
	DxLibPlusApplication();
	~DxLibPlusApplication();
	void Initialize();
	virtual void OnInitialize(); 
	virtual void OnFinalize();
};

