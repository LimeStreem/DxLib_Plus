#include "stdafx.h"
#include "DxDebug.h"
#include <iostream>
#include <stdarg.h>
DxDebugStream dxout = DxDebugStream();
DxDebug::DxDebug()
{
}


DxDebug::~DxDebug()
{
}

void DxDebug::Clear()
{
	clsDx();
}

void DxDebug::Update()
{
	if (IsDebugStreamAutoFlush)
	{
		dxout.flush();
	}
}

void DxDebug::OnFrameUpdated()
{
	if (AutoClear)Clear();
}

bool DxDebug::IsDebugStreamAutoFlush = true;
bool DxDebug::AutoClear = true;
#ifdef _DEBUG
bool DxDebug::SuppressDebugStream = false;
#else
bool DxDebug::SuppressDebugStream = true;
#endif

DxDebugStreamBuffer::DxDebugStreamBuffer()
{
	std::memset(buf, 0, sizeof(buf));
	setp(buf, buf + (sizeof(buf) - 1));
}

int DxDebugStreamBuffer::sync()
{
	if(!DxDebug::SuppressDebugStream)printfDx("%s", buf);
	int offset = pptr() - pbase();
	pbump(-offset);
	return 0;
}

int DxDebugStreamBuffer::overflow()
{
	if (!DxDebug::SuppressDebugStream)printfDx("%s", buf);
	int offset = pptr() - pbase();
	pbump(offset);
	return 0;
}

DxDebugStream::DxDebugStream() :std::ostream(&buf)
{

}