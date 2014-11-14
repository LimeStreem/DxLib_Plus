#pragma once
#include "DxLibPlusObject.h"
#include <vector>  

class Entity :
	public DxLibPlusObject
{
public:
	Entity();
	~Entity();
	void Draw();
	void UpDate();
	void UpDate(Entity* parent);
	void SetParent(Entity parent);//eEntity‚Ìİ’è
	int ZIndex;
protected:
	std::vector<Entity> _child;
};

