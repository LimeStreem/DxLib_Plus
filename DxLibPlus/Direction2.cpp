#include "stdafx.h"
#include "Direction2.h"
#include <boost\format.hpp>

Direction2::Direction2(float x, float y) :Vector2(x,y)
{
	
}


Direction2::~Direction2()
{
}

AffineVector2 Direction2::ToAffine()
{
	return AffineVector2(this->x, this->y, 0);
}

std::string Direction2::ToString()
{
	return (boost::format("Direction2(%1%,%2%)[length:%3%]") % x %y %Length()).str();
}
