#include "GameClock.h"
#include "Time.h"


GameClock::GameClock()
: mStartTime(), mCurrentTime(), mLastTime(), mFrequency()
{
	mFrequency = GetFrequency();
	Reset();
}

const LARGE_INTEGER& GameClock::StartTime() const
{
	return mStartTime;
}

const LARGE_INTEGER& GameClock::CurrentTime() const
{
	return mCurrentTime;
}

const LARGE_INTEGER& GameClock::LastTime() const
{
	return mLastTime;
}

void GameClock::Reset()
{
	GetTime(mStartTime);
	mCurrentTime = mStartTime;
	mLastTime = mCurrentTime;
}

double GameClock::GetFrequency() const
{
	LARGE_INTEGER frequency;

	if(QueryPerformanceFrequency(&frequency) == false)
	{
		throw std::exception("QueryPerformanceFrequency() failed.");
	}

	return (double)frequency.QuadPart;
}

void GameClock::GetTime(LARGE_INTEGER& time) const
{
	QueryPerformanceCounter(&time);
}

void GameClock::UpdateGameTime(Time& gameTime)
{
	GetTime(mCurrentTime);
	gameTime.setTimeFromStart((mCurrentTime.QuadPart - mStartTime.QuadPart) / mFrequency);
	gameTime.setElapsedTime((mCurrentTime.QuadPart - mLastTime.QuadPart) / mFrequency);

	mLastTime = mCurrentTime;
}
