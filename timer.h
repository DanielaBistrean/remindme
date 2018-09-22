#ifndef REMINDME_TIMER_H
#define REMINDME_TIMER_H 1

#include <functional>
#include <ctime>
#include <csignal>

namespace remindme
{
	typedef void (*callback_t) (union sigval);

	class timer
	{
	public:
		timer();
		timer(const callback_t &callback, const void *ptr);
		~timer();

		void reset(const callback_t &callback, const void *ptr);
		bool start(const std::time_t &sec);
	private:
		timer_t m_timer;
		bool m_bInitialized;
	};
}

#endif
