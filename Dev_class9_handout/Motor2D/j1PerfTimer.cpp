// ----------------------------------------------------
// j1PerfTimer.cpp
// Slow timer with microsecond precision
// ----------------------------------------------------

#include "j1PerfTimer.h"
#include "SDL\include\SDL_timer.h"

uint64 j1PerfTimer::frequency = 0;

// ---------------------------------------------
j1PerfTimer::j1PerfTimer()
{
	// TODO 2: Fill Constructor, Start(),ReadMs() and ReadTicks() methods
	// they are simple, one line each!
	started_at = SDL_GetPerformanceCounter();
	frequency = SDL_GetPerformanceFrequency();
	Start();
}

// ---------------------------------------------
void j1PerfTimer::Start()
{
}

// ---------------------------------------------
double j1PerfTimer::ReadMs() const
{
	return (started_at - SDL_GetPerformanceCounter())*1000 / frequency;
}

// ---------------------------------------------
uint64 j1PerfTimer::ReadTicks() const
{
	return started_at - SDL_GetPerformanceCounter();
}


