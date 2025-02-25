// tu_timer.h	-- by Thatcher Ulrich <tu@tulrich.com>

// This source code has been donated to the Public Domain.  Do
// whatever you want with it.

// Utility/profiling timer.


#ifndef TU_TIMER_H
#define TU_TIMER_H

#include <time.h>
#include "base/tu_types.h"

namespace tu_timer
{
	// General-purpose wall-clock timer.  May not be hi-res enough
	// for profiling.
	void init_timer();

	// milliseconds since we started playing.
	Uint32 get_ticks();

	// Sleep the current thread for the given number of
	// milliseconds.  Don't rely on the sleep period being very
	// accurate.
	void sleep(int milliseconds);
	
	// Hi-res timer for CPU profiling.

	// Return a hi-res timer value.  Time 0 is arbitrary, so
	// generally you want to call this at the start and end of an
	// operation, and pass the difference to
	// profile_ticks_to_seconds() to find out how long the
	// operation took.
	uint64	get_profile_ticks();

	// Convert a hi-res ticks value into seconds.
	double	profile_ticks_to_seconds(uint64 profile_ticks);

	double	profile_ticks_to_milliseconds(uint64 ticks);

	// Return the time as seconds elapsed since midnight, January 1, 1970.
	Uint64 get_systime();

};


struct tu_datetime
{
	enum part
	{
		YEAR,	// year - 1900
		FULLYEAR,	// a four-digit number, such as 2000
		MON,
		MDAY,	// day of a month
		WDAY,	// day of a week
		HOUR,
		MIN,
		SEC
	};

	tu_datetime();

	double get_time() const;
	void set_time(double t);

	int get(part part);
	void set(part part, int val);

private:

	time_t m_time;
};


#endif // TU_TIMER_H


// Local Variables:
// mode: C++
// c-basic-offset: 8 
// tab-width: 8
// indent-tabs-mode: t
// End:
