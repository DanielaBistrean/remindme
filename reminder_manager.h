#ifndef REMINDME_REMINDERMANAGER_H
#define REMINDME_REMINDERMANAGER_H 1

#include "reminder.h"
#include <list>

namespace remindme
{
	class reminder_manager
	{
	public:
		reminder_manager();
		~reminder_manager();
		void add(const reminder &r);
		void show();
	private:
		std::list<reminder> m_lRem;
	};
}

#endif
