#include "stdafx.h"
#include "FPSManager.h"
#include <queue>
#include "MathDX.h"
#include "DxDebug.h"
FPSManager::FPSManager()
{
	this->frameTimes = new FPSCountQueue();
	this->maxRecordFrame = 10;
	this->lastFrameSecound = 0;
	this->IdealFPS = 30;
}


FPSManager::~FPSManager()
{
	delete frameTimes;
}

std::string FPSManager::ToString()
{
	return "";
}

void FPSManager::FrameUpdated()
{
	long current = GetNowCount();
	if (this->lastFrameSecound == 0)
	{//Å‰‚Ì‚Æ‚«‚ÍƒtƒŒ[ƒ€‚Ì·‚ð‚Æ‚ê‚È‚¢‚Ì‚Å‚±‚¤‚µ‚Ä‚¨‚­
		this->lastFrameSecound = current;
		return;
	}
	else{
		float frameDelta = current - this->lastFrameSecound;
		this->frameTimes->push(frameDelta);
		if (this->frameTimes->Count() > this->maxRecordFrame)
		{
			this->frameTimes->pop();
		}
		this->lastFrameSecound = current;
		float sleepTime = MathDX::Max(1000 / this->IdealFPS - frameDelta, 0);
		dxout<<'\n' << sleepTime;
		WaitTimer(sleepTime);
	}
}

float FPSManager::GetFPS()
{
	return 1000/this->frameTimes->Average();
}

std::deque<long>::iterator FPSCountQueue::begin()
{
	return c.begin();
}

std::deque<long>::iterator FPSCountQueue::end()
{
	return c.end();
}

long FPSCountQueue::Sum()
{
	long sum = 0;
	for (auto it = begin(); it!=end(); it++)
	{
		sum += (*it);
	}
	return sum;
}

int FPSCountQueue::Count()
{
	int count = 0;
	for (auto it = begin(); it!=end(); it++)
	{
		count++;
	}
	return count;
}

float FPSCountQueue::Average()
{
	return Sum() / ((float) Count());
}