#pragma once
#include "DxLibPlusObject.h"
class Scene :
	public DxLibPlusObject
{
public:
	Scene();
	~Scene();
	 void Update();
	 void Draw(); 
protected:
	 virtual void OnUpdate();
	 virtual void OnDraw();
};

