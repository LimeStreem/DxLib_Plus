#pragma once
#include "DxLibPlusObject.h"
class AffineVector2 :
	public DxLibPlusObject
{
public:
	AffineVector2(float x, float y, float z);
	~AffineVector2();
	float x;
	float y;
	float z;
	std::string ToString();
};

