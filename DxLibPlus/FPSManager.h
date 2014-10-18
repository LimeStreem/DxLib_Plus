#pragma once
#include "DxLibPlusObject.h"
#include "DxIterableQueue.h"
#include <queue>


class FPSCountQueue :public std::queue < long >
{
public:
	std::deque<long>::iterator begin();

	std::deque<long>::iterator end();

	long Sum();

	int Count();

	float Average();
};

class FPSManager :
	public DxLibPlusObject
{
protected:
	FPSCountQueue* frameTimes;
	unsigned long lastFrameSecound;
public:
	FPSManager();
	~FPSManager();
	unsigned int maxRecordFrame;
	virtual std::string ToString();
	void FrameUpdated();
	float GetFPS();
	float IdealFPS;
};
