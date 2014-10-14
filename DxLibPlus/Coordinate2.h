#pragma once
#include "Vector2.h"
#include "IAffineTransformable2D.h"
class Coordinate2 :
	public Vector2,public IAffineTransformable2D
{
public:
	Coordinate2(float x,float y);
	~Coordinate2();
	AffineVector2 ToAffine();
	std::string ToString();
};

