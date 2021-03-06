#include "stdafx.h"
#include "MathDX.h"
#include <math.h>

MathDX::MathDX()
{
}


MathDX::~MathDX()
{
}

float MathDX::Lerp(float start, float end, float t)
{
	return start + (end - start)*t;
}

float MathDX::ToDegree(float radian)
{
	//1度=2π/360度であるので、以下のように求まる
	return radian / (2.0* PI/360.0);
}

float MathDX::ToRadian(float degree)
{
	return degree*(2.0 * PI / 360.0);
}

float MathDX::Sin(float v)
{
	return sin(v);
}

float MathDX::Cos(float v)
{
	return cos(v);
}

float MathDX::Tan(float v)
{
	return tan(v);
}

float MathDX::ArcSin(float v)
{
	return asin(v);
}

float MathDX::ArcCos(float v)
{
	return acos(v);
}

float MathDX::ArcTan(float v)
{
	return atan(v);
}

float MathDX::Max(float v1, float v2)
{
	return max(v1, v2);
}

float MathDX::Min(float v1, float v2)
{
	return min(v1, v2);
}

float MathDX::PI = 3.141592f;