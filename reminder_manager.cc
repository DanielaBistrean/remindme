#include "reminder_manager.h"

#include <iostream>

namespace remindme
{
	reminder_manager::reminder_manager()
	{
		
	}

	reminder_manager::~reminder_manager()
	{

	}

	void
	reminder_manager::add (const reminder &r)
	{
		m_lRem.push_back(r);
	}

	void
	reminder_manager::show ()
	{
		// std::list<reminder>::iterator it; 
		auto it = m_lRem.begin();

		std::cout << "The list of reminder:\n";
		for ( ; it != m_lRem.end(); it++)
			std::cout << it->getTitle() << "\n";
	}
}
