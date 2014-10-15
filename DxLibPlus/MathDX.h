#pragma once
class MathDX
{
private:
	MathDX();
	~MathDX();
public:
	/*
	*��̒l����`�⊮���܂��B
	*/
	static float Lerp(float start, float end, float t);
	static float ToDegree(float radian);
	static float ToRadian(float degree);
	static float Sin(float v);
	static float Cos(float v);
	static float Tan(float v);
	static float ArcSin(float v);
	static float ArcCos(float v);
	static float ArcTan(float v);
	static float PI;
};

