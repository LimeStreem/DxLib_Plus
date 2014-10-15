#include "stdafx.h"
#include "DxLibPlusObject.h"
#include <typeinfo>


DxLibPlusObject::DxLibPlusObject()
{
}


DxLibPlusObject::~DxLibPlusObject()
{
}


std::string DxLibPlusObject::ToString()const
{
	return typeid(this).name();
}

std::ostream & operator<<(std::ostream& stream, const DxLibPlusObject& val)
{
	stream << val.ToString();
	return stream;
}

std::ostream & operator<<(std::ostream& stream, const DxLibPlusObject* val)
{
	stream << val->ToString();
	return stream;
}