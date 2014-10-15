#pragma once
#include "DxLibPlusObject.h"
#include "IAffineTransformable2D.h"
#include "Direction2.h"
#include "Coordinate2.h"
class Matrix :
	public DxLibPlusObject
{
public:
	Matrix(float m_00, float m_01, float m_02, float m_10, float m_11, float m_12, float m_20, float m_21, float m_22);
	~Matrix();
	float elements[9];
	void SetAt(int row, int colmn, float val);
	float GetAt(int row, int colmn) const;
	Coordinate2 TransformCoordinate(Coordinate2 vec);
	Direction2 TransformDirection(Direction2 vec);
	AffineVector2 Transform(AffineVector2 avec);
	std::string ToString();
	float Det();
	float Tr();
	bool IsSingularMatrix();
	Matrix Invert();
	Matrix MulScalar(float s);
	static Matrix Identity();
	static Matrix Zero();
	static Matrix Rotated(float angle);
	static Matrix Multiply(const Matrix& m1,const Matrix& m2);
private:
	float MulColmun(int colmun, AffineVector2 vec);
	static float CalcMultipliedElement(const Matrix& m1,const Matrix& m2,int row,int colmun);
};

