#pragma once
class DxDebug
{
private:
	DxDebug();
	~DxDebug();
public:
};

class DxDebugStreamBuffer :public std::streambuf
{
	char buf[1024];
public:
	DxDebugStreamBuffer();
	int sync();
	int overflow();
};

class DxDebugStream :public std::ostream
{
	DxDebugStreamBuffer buf;
public:
	DxDebugStream();
};

extern DxDebugStream dout;