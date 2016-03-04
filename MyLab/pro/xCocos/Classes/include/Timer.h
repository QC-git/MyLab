/*!
 * \file Timer.h
 *
 * \author MILO
 * \date 11/4/2015
 *
 *
 */
#pragma once

class IntervalTimer
{
public:
	IntervalTimer() : _interval(0), _current(0) {}

	void Update(time_t diff) { _current += diff; if (_current < 0) _current = 0; }
	bool Passed() { return _current >= _interval; }
	void Reset() { if (_current >= _interval) _current -= _interval; }

	void SetCurrent(time_t current) { _current = current; }
	void SetInterval(time_t interval) { _interval = interval; }
	time_t GetInterval() const { return _interval; }
	time_t GetCurrent() const { return _current; }

private:
	time_t _interval;
	time_t _current;
};

struct TimeTracker
{
	TimeTracker(time_t expiry) : i_expiryTime(expiry) {}
	void Update(time_t diff) { i_expiryTime -= diff; }
	bool Passed(void) const { return (i_expiryTime <= 0); }
	void Reset(time_t interval) { i_expiryTime = interval; }
	time_t GetExpiry(void) const { return i_expiryTime; }
	time_t i_expiryTime;
};

struct TimeTrackerSmall
{
	TimeTrackerSmall(int32_t expiry) : i_expiryTime(expiry) {}
	void Update(int32_t diff) { i_expiryTime -= diff; }
	bool Passed(void) const { return (i_expiryTime <= 0); }
	void Reset(int32_t interval) { i_expiryTime = interval; }
	int32_t GetExpiry(void) const { return i_expiryTime; }
	int32_t i_expiryTime;
};
