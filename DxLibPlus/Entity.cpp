#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}


void Entity::UpDate()
{
	//TODO:親エンティティの更新処理をする
	throw "notImplement!";
	//ここまで

	for (size_t i = 0; i < _child.size(); i++)
	{
		_child.at(i).UpDate(this);
	}
}
