#include "stdafx.h"
#include "DxLibPlusObject.h"
#include <typeinfo>

DxLibPlusObject::DxLibPlusObject()
{
}


DxLibPlusObject::~DxLibPlusObject()
{
}


std::string DxLibPlusObject::ToString()
{
	return typeid(this).name();
}
