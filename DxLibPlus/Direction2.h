#pragma once
#include "Vector2.h"
#include "IAffineTransformable2D.h"
class Direction2 :
	public Vector2,public IAffineTransformable2D
{
public:
	Direction2(float x,float y);
	~Direction2();
	AffineVector2 ToAffine();
	virtual std::string ToString()const;
};

