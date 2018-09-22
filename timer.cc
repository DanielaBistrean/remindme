#include "timer.h"

#include <stdexcept>

namespace remindme
{
	timer::timer()
	: m_bInitialized(false)
	{
	}

	timer::timer(const callback_t &callback, const void *ptr)
	: m_bInitialized(false)
	{
		reset(callback, ptr);
	}

	timer::~timer()
	{
		if (m_bInitialized)
			timer_delete(m_timer);
	}

	bool
	timer::start(const std::time_t &sec)
	{
		if (!m_bInitialized)
			return false;

		struct itimerspec tspec;
		//memset(&tspec.it_interval, 0, sizeof(tspec.it_interval));
		tspec.it_interval.tv_sec = 0;
		tspec.it_interval.tv_nsec = 0;

		tspec.it_value.tv_sec = sec;
		tspec.it_value.tv_nsec = 0;

		int res = timer_settime(m_timer, 0, &tspec, NULL);
		if (res != 0)
			throw std::runtime_error("cannot start timer");
		
		return true;
	}

	void
	timer::reset(const callback_t &callback, const void *ptr)
	{
		if (m_bInitialized)
			timer_delete(m_timer);

		struct sigevent sevp;
		sevp.sigev_notify = SIGEV_THREAD;
		sevp.sigev_value.sival_ptr = const_cast<void*> (ptr); 
		sevp.sigev_notify_function = callback;
		sevp.sigev_notify_attributes = NULL;

		int res = timer_create(CLOCK_MONOTONIC, &sevp, &m_timer);
		if (res != 0)
			throw std::runtime_error("cannot create timer");

		m_bInitialized = true;
	}
}
