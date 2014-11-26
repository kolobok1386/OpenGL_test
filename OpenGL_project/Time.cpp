#include "Time.h"

Time::Time()
: m_elapsedTime(0.0),
m_timeFromStart(0.0)
{	
}

Time::Time(double elapsedTime, double timeFromStart)
: m_elapsedTime(elapsedTime),
m_timeFromStart(timeFromStart)
{
}

double Time::getElapsedTime() const
{
	return m_elapsedTime;
}

void Time::setElapsedTime(double value)
{
	m_elapsedTime = value;
}

double Time::getTimeFromStart() const
{
	return m_timeFromStart;
}

void Time::setTimeFromStart(double value)
{
	m_timeFromStart = value;
}
