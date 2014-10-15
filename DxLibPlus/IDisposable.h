#pragma once
class IDisposable
{
protected:
	IDisposable();
public:
	virtual void Dispose() = 0;
};

