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
	 RECT* Size;//�`��̈�
	 Entity RootEntity;//Update�J�n�_
protected:
	 virtual void OnUpdate();
	 virtual void OnDraw();
private:
	int _id;
	std::vector<Entity> _entityList;//���̃V�[����Entity�̕`�揇�\�[�g�ς݃��X�g�B
};

