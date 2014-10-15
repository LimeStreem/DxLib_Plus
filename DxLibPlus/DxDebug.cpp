#include "stdafx.h"
#include "DxDebug.h"
#include <iostream>
DxDebugStream dout = DxDebugStream();
DxDebug::DxDebug()
{
}


DxDebug::~DxDebug()
{
	
}


DxDebugStreamBuffer::DxDebugStreamBuffer()
{
	std::memset(buf, 0, sizeof(buf));
	setp(buf, buf + (sizeof(buf) - 1));
}

int DxDebugStreamBuffer::sync()
{
	*(pptr() - 1) = '\0';
	printfDx("%s", buf);
	int offset = pptr() - pbase();
	pbump(-offset);
	return 0;
}

int DxDebugStreamBuffer::overflow()
{
	printfDx("%s", buf);
	int offset = pptr() - pbase();
	pbump(offset);
	return 0;
}

DxDebugStream::DxDebugStream() :std::ostream(&buf)
{

}