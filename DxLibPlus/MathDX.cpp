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
	//1ìx=2ÉŒ/360ìxÇ≈Ç†ÇÈÇÃÇ≈ÅAà»â∫ÇÃÇÊÇ§Ç…ãÅÇ‹ÇÈ
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

float MathDX::PI = 3.141592f;