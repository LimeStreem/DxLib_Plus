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
	//TODO:�e�G���e�B�e�B�̍X�V����������
	throw "notImplement!";
	//�����܂�

	for (size_t i = 0; i < _child.size(); i++)
	{
		_child.at(i).UpDate(this);
	}
}
