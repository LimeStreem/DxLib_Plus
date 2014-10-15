#include "stdafx.h"
#include "AffineVector2.h"
#include <boost\format.hpp>

AffineVector2::AffineVector2(float x,float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


AffineVector2::~AffineVector2()
{
}

std::string AffineVector2::ToString()
{
	return (boost::format("AffineVector2(%1%,%2%,%3%)") % x%y%z).str();
}