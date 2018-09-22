#ifndef REMINDME_REMINDER_H
#define REMINDME_REMINDER_H 1

#include <ctime>
#include <string>

#include "timer.h"

namespace remindme
{
	class reminder
	{
	public:
		reminder(const std::time_t &time, const std::string &sTitle);
		
		std::time_t getTime() const;
		std::string getTitle() const;
	private:
		std::time_t m_time;
		std::string m_sTitle;
		timer m_timer;

		static void callback(union sigval value);
	};
}


#endif
