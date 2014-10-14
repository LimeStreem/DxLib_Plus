#pragma once
#include "AffineVector2.h"
class IAffineTransformable2D
{
public:
	IAffineTransformable2D();
	~IAffineTransformable2D();
	virtual AffineVector2 ToAffine() = 0;
};

