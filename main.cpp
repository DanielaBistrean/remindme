#include <string>
#include <iostream>
#include <stdexcept>

#include "reminder.h"
#include "timer.h"

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
		// create a reminder
		reminder rmd{atoi(argv[1]), std::string{argv[2]}};
		std::cout << "Reminder-ul pentru: \"" << rmd.getTitle() << "\" a fost setat peste " << rmd.getTime() << " secunde\n";

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
