#pragma once
#include "stdafx.h"
class DxLibPlusObject
{
public:
	DxLibPlusObject();
	~DxLibPlusObject();
	virtual std::string ToString()const;
};

std::ostream& operator<<(std::ostream &stream, const DxLibPlusObject& val);
std::ostream& operator<<(std::ostream &stream, const DxLibPlusObject* val);