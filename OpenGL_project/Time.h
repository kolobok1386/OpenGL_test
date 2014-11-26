#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time();
	Time(double elapsedTime, double timeFromStart);

	double getElapsedTime() const;
	void setElapsedTime(double value);

	double getTimeFromStart() const;
	void setTimeFromStart(double value);

protected:
	double m_elapsedTime;
	double m_timeFromStart;

};

#endif