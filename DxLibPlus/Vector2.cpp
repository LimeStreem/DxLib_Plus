#include "stdafx.h"
#include "Vector2.h"
#include <math.h>
#include <boost\format.hpp>

Vector2::Vector2(float e)
{
	x = e;
	y = e;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


Vector2::~Vector2()
{
}


float Vector2::Length()const
{
	return sqrtf(LengthSquared());
}


float Vector2::LengthSquared()const
{
	return x*x + y*y;
}

std::string Vector2::ToString()const
{
	return (boost::format("Vector2(%1%,%2%)[length:%3%]") % x %y %Length()).str();
}

Vector2 Vector2::Add(Vector2 v1, Vector2 v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

Vector2 Vector2::Subtract(Vector2 v1, Vector2 v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

float Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}

Vector2 Vector2::ElementMul(Vector2 v1, Vector2 v2)
{
	return Vector2(v1.x*v2.x, v1.y*v2.y);
}

float Vector2::DotWith(Vector2 vec)
{
	return Dot(*this, vec);
}

Vector2 Vector2::AddWith(Vector2 vec)
{
	return Add(*this, vec);
}

Vector2 Vector2::SubtractWith(Vector2 vec)
{
	return Subtract(*this, vec);
}

Vector2 Vector2::ElementMulWith(Vector2 vec)
{
	return ElementMul(*this, vec);
}

Vector2 Vector2::operator+(Vector2 vec)
{
	return Add(*this, vec);
}
