#pragma once
#include "DxLibPlusObject.h"
class Vector2 :
	public DxLibPlusObject
{
public:
	Vector2(float e);
	Vector2(float x, float y);
	~Vector2();
	float x;
	float y;
	float Length();
	float LengthSquared();
	std::string ToString();

	static Vector2 Add(Vector2 v1, Vector2 v2);
	static Vector2 Subtract(Vector2 v1, Vector2 v2);
};

