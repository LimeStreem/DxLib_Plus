#pragma once
#include "DxLibPlusObject.h"
#include "Vector2.h"
#include "Entity.h"
#include <vector>  
#include<windef.h>

class Scene :
	public DxLibPlusObject
{
public:
	Scene(RECT* size);
	~Scene();
	 void Update();
	 void Draw();
	 void AddEntity(Entity entity);
	 RECT* Size;//`ζΜζ
protected:
	 virtual void OnUpdate();
	 virtual void OnDraw();
private:
	int _id;
	std::vector<int> _entityList;//±ΜV[ΜEntityΜ`ζ\[gΟέXgB
};

