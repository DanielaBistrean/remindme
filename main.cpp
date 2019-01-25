#include <string>
#include <iostream>
#include <stdexcept>
#include <list>
#include <unistd.h>

#include "reminder.h"
#include "timer.h"
#include "reminder_manager.h"

using namespace remindme;

int
main(int argc, char const *argv[])
{

	if (argc <= 2)
	{
		std::cerr << "Usage: " << argv[0] << " TIME TITLE\n";
		return 1;
	}

	try
	{
		// std::list<reminder> remList;
		// create a reminder manager using constructor
		reminder_manager rm{};

		// create a reminder
		// reminder rmd2{1, "Reminder2"};
		reminder rmd{atoi(argv[1]), std::string{argv[2]}};
		// remList.push_back(rmd);
		std::cout << "Reminder-ul pentru: \"" << rmd.getTitle() << "\" a fost setat peste " << rmd.getTime() << " secunde\n";

		rm.add(rmd);
		// rm.add(rmd2);
		rm.show();
		// show(remList);
		// auto it = remList.begin();

		// for ( ; it != remList.end(); it++)
		// 	std::cout << it->getTitle() << "\n";

		// wait a bit
		// sleep(rmd.getTime() + 1);
		while (1);
		// get a notification

	}
	catch(const std::exception &e)
	{
		std::cerr << "error: " << e.what() << "\n";
		return 1;
	}
	catch (...)
	{
		std::cerr << "error: unexpected\n";
		return 1;
	}

	return 0;
}
