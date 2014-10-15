#include "stdafx.h"
#include "Matrix.h"
#include <boost\format.hpp>
#include "MathDX.h"
Matrix::Matrix(float m_00, float m_01, float m_02, float m_10, float m_11, float m_12, float m_20, float m_21, float m_22)
{
	this->SetAt(0, 0, m_00);
	this->SetAt(0, 1, m_01);
	this->SetAt(0, 2, m_02);
	this->SetAt(1, 0, m_10);
	this->SetAt(1, 1, m_11);
	this->SetAt(1, 2, m_12);
	this->SetAt(2, 0, m_20);
	this->SetAt(2, 1, m_21);
	this->SetAt(2, 2, m_22);
}

Matrix::~Matrix()
{
}

void Matrix::SetAt(int row,int colmn, float val)
{
	this->elements[row * 3 + colmn] = val;
}

float Matrix::GetAt(int row, int colmn)const
{
	return this->elements[row * 3 + colmn];
}

Matrix Matrix::Identity()
{
	return Matrix(1,0,0,0,1,0,0,0,1);
}

Matrix Matrix::Zero()
{
	return Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

Coordinate2 Matrix::TransformCoordinate(Coordinate2 vec){
	AffineVector2 avec = Transform(vec.ToAffine());
	return Coordinate2(avec.x / avec.z, avec.y / avec.z);
}

Direction2 Matrix::TransformDirection(Direction2 vec)
{
	AffineVector2 avec = Transform(vec.ToAffine());
	return Direction2(avec.x, avec.y);
}

AffineVector2 Matrix::Transform(AffineVector2 avec){
	return AffineVector2(MulColmun(0, avec), MulColmun(1, avec), MulColmun(2, avec));
}

float Matrix::MulColmun(int colmun, AffineVector2 vec){
	return GetAt(0, colmun)*vec.x + GetAt(1, colmun)*vec.y + GetAt(2, colmun)*vec.z;
}

float Matrix::Det()
{//サラスの公式
	return GetAt(0, 0)*GetAt(1, 1)*GetAt(2, 2) + GetAt(0, 1)*GetAt(1, 2)*GetAt(2, 0) + GetAt(0, 2)*GetAt(2, 1)*GetAt(1, 0)
		- GetAt(0, 2)*GetAt(1, 1)*GetAt(2, 0) - GetAt(0, 1)*GetAt(1, 0)*GetAt(2, 2) - GetAt(0, 0)*GetAt(2, 1)*GetAt(1, 2);
}

float Matrix::Tr()
{
	return GetAt(0, 0) + GetAt(1, 1) + GetAt(2, 2);
}

bool Matrix::IsSingularMatrix()
{
	return Det() == 0;
}

Matrix Matrix::Invert()
{
	if (IsSingularMatrix())
	{//非正則の場合は逆行列は求まらない
		return Matrix(NAN, NAN, NAN, NAN, NAN, NAN, NAN, NAN, NAN);
	}
	else{
		return Matrix(GetAt(1,1)*GetAt(2,2)-GetAt(1,2)*GetAt(2,1),GetAt(0,2)*GetAt(2,1)-GetAt(0,1)*GetAt(2,2),GetAt(0,1)*GetAt(1,2)-GetAt(0,2)*GetAt(1,1),
					GetAt(1,2)*GetAt(2,0)-GetAt(1,0)*GetAt(2,2),GetAt(0,0)*GetAt(2,2)-GetAt(0,2)*GetAt(2,0),GetAt(0,2)*GetAt(1,0)-GetAt(0,0)*GetAt(1,2),
					GetAt(1,0)*GetAt(2,1)-GetAt(1,1)*GetAt(2,0),GetAt(0,1)*GetAt(2,0)-GetAt(0,0)*GetAt(2,1),GetAt(0,0)*GetAt(1,1)-GetAt(0,1)*GetAt(1,0)).MulScalar(Det());
	}
}

Matrix Matrix::MulScalar(float s)
{
	return Matrix(GetAt(0, 0)*s, GetAt(0, 1)*s, GetAt(0, 2)*s, GetAt(1, 0)*s, GetAt(1, 1)*s, GetAt(1, 2)*s, GetAt(2, 0)*s, GetAt(2, 1)*s, GetAt(2, 2)*s);
}

std::string Matrix::ToString()
{
	return (boost::format("「%1% %2% %3%丁\n|%4% %5% %6%|\nL%7% %8% %9%」") % GetAt(0, 0) % GetAt(0, 1) % GetAt(0, 2) % GetAt(1, 0) % GetAt(1, 1) % GetAt(1, 2) % GetAt(2, 0) % GetAt(2, 1) % GetAt(2, 2)).str();
}

Matrix Matrix::Rotated(float deg)
{
	float radian = MathDX::ToRadian(deg);
	return Matrix(MathDX::Cos(radian), -MathDX::Sin(radian), 0, MathDX::Cos(radian), MathDX::Sin(radian),0,0,0,1);
}

Matrix Matrix::Multiply(const Matrix& m1,const Matrix& m2)
{
	return Matrix(CalcMultipliedElement(m1, m2, 0, 0), CalcMultipliedElement(m1, m2, 0, 1), CalcMultipliedElement(m1, m2, 0, 2),
				  CalcMultipliedElement(m1, m2, 1, 0), CalcMultipliedElement(m1, m2, 1, 1), CalcMultipliedElement(m1, m2, 1, 2),
				  CalcMultipliedElement(m1, m2, 2, 0), CalcMultipliedElement(m1, m2, 2, 1), CalcMultipliedElement(m1, m2, 2, 2));
}

float Matrix::CalcMultipliedElement(const Matrix& m1,const Matrix&m2,int row,int colmun)
{
	float result = 0;
	for (int i = 0; i < 3; i++)
	{
		result += m1.GetAt(row, i)*m2.GetAt(i, colmun);
	}
	return result;
}