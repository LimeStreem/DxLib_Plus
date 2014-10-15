#include "stdafx.h"
#include "Coordinate2.h"
#include <boost\format.hpp>

Coordinate2::Coordinate2(float x, float y) :Vector2(x,y)
{
}


Coordinate2::~Coordinate2()
{
}

AffineVector2 Coordinate2::ToAffine()
{
	return AffineVector2(this->x, this->y, 1);
}

std::string Coordinate2::ToString()const
{
	return (boost::format("Coordinate2(%1%,%2%)[length:%3%]") % x %y %Length()).str();
}