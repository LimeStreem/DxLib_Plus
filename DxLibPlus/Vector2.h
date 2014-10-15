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
	float Length()const;
	float LengthSquared()const;
	//TODO 実装よろしく
	float DotWith(Vector2 vec);
	Vector2 AddWith(Vector2 v);
	Vector2 SubtractWith(Vector2 v);
	Vector2 ElementMulWith(Vector2 v);
	//ここまで
	virtual  std::string ToString()const;

	static Vector2 Add(Vector2 v1, Vector2 v2);
	static Vector2 Subtract(Vector2 v1, Vector2 v2);
	//TODO 実装よろしく
	static float Dot(Vector2 v1, Vector2 v2);
	static Vector2 ElementMul(Vector2 v1, Vector2 v2);
	static Vector2 Top();
	static Vector2 Bottom();
	static Vector2 Left();
	static Vector2 Right();
	//+オペレーターの実装よろ
};

