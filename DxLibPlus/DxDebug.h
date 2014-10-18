#pragma once
class DxDebug
{
private:
	DxDebug();
	~DxDebug();
public:
	static bool IsDebugStreamAutoFlush;
	static bool SuppressDebugStream;
	static bool AutoClear;
	static void Clear();
	static void Update();
	static void OnFrameUpdated();
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
extern DxDebugStream dxout;