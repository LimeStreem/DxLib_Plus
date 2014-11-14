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
	 RECT* Size;//描画領域
	 Entity RootEntity;//Update開始点
protected:
	 virtual void OnUpdate();
	 virtual void OnDraw();
private:
	int _id;
	std::vector<Entity> _entityList;//このシーンのEntityの描画順ソート済みリスト。
};

