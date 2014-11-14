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
	void UpDate(Entity* parent);
	void SetParent(Entity parent);//eEntity‚Ìİ’è
protected:
	std::vector<int> _child;
private :
	int _zIndex;
};

