#include "reminder.h"

#include <stdexcept>
#include <iostream>

namespace remindme
{
	void
	reminder::callback(union sigval value)
	{
		try
		{
			const reminder *r = static_cast<const reminder*> (value.sival_ptr);
			std::cout << r->getTitle() << ": time is up!\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << "error: " << e.what() << "\n";
		}
		catch (...)
		{
			std::cerr << "error: unexpected\n";
		}
	}

	reminder::reminder(const std::time_t &time, const std::string &sTitle)
	: m_time(time)
	, m_sTitle(sTitle)
	, m_timer{reminder::callback, this}
	{
		if (time < 0)
			throw std::runtime_error("invalid time value");

		m_timer.start(m_time);
	}

	std::time_t
	reminder::getTime() const
	{
		return m_time;
	}

	std::string
	reminder::getTitle() const
	{
		return m_sTitle;
	}
}
