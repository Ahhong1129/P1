#pragma once
#include"GameWindows.h"
class GTimer
{
private:

	LARGE_INTEGER timerFreq;
	LARGE_INTEGER timeNow;
	LARGE_INTEGER timePrevious;
	int Requested_FPS;
	float intervalsPerFrame;
public:
	GTimer();
	~GTimer(); 
	void init(int fps);
	int frameToUpdate();
};

