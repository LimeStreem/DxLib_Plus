#pragma once
#include "DxLibPlusObject.h"
#include "FPSManager.h"
class DxLibPlusApplication :
	public DxLibPlusObject
{
public:
	DxLibPlusApplication();
	virtual ~DxLibPlusApplication();
	void Initialize();
	void Finalize();
	void RunMessageLoop();
	FPSManager* fpsManager;
protected:
	virtual void OnInitialize(); 
	virtual void OnFinalize();
	virtual void OnPrepareMessageLoop();
	virtual void OnPostMessageLoop();
	virtual bool ContinueMessageLoop();
};

