#include "stdafx.h"
#include "Scene.h"
#include "Entity.h"


Scene::Scene(RECT* size)
{
	Size = size;
}


Scene::~Scene()
{
}

void Scene::OnDraw()
{

}

void Scene::OnUpdate()
{

}



void Scene::AddEntity(Entity entity)
{
	//zindexでソートして登録
	int count = 0;
	int length = _entityList.size();

	while (true)
	{
		if (count == length - 1)
		{
			//TODO:リスト末尾にentityを追加
			throw "NotImplement!";
		}
		if (_entityList.at(count).ZIndex > entity.ZIndex)
		{
			//TODO:リストのcount位置にentityを挿入
			throw "NotImplement!";
		}
		count++;
	}
}

void Scene::Draw()
{
	for (size_t i = 0; i < _entityList.size(); i++)
	{
		_entityList.at(i).Draw();
	}
}

void Scene::Update()
{
	RootEntity.UpDate();
}