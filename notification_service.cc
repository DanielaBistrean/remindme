#include "notification_service.h"

#include <stdexcept>
#include <libnotify/notify.h>
#include <iostream>

namespace remindme
{
	std::shared_ptr<notification_service> notification_service::s_pInstance;

	notification_service::notification_service(const std::string &sAppName)
	{
		bool bRes = notify_init(sAppName.c_str());
		if (!bRes)
			throw std::runtime_error("cannot initialize notification service");
		// std::cout << "[debug] Init was called\n";
	}

	notification_service::~notification_service()
	{
		notify_uninit();
		// std::cout << "[debug] uninit was called\n";
	}

	std::shared_ptr<notification_service>
	notification_service::getInstance(const std::string &sAppName)
	{
		// std::cout << "[debug] getInstance was called\n";
		if (s_pInstance == nullptr)
			s_pInstance = std::shared_ptr<notification_service>(new notification_service(sAppName));
		
		return s_pInstance;
	}

	notification
	notification_service::createNotification(const std::string &sTitle, const std::string &sBody)
	{
		return notification(sTitle, sBody);
	}

	notification
	notification_service::createNotification(const std::string &sTitle)
	{
		return notification(sTitle);
	}
}
