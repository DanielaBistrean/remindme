#include "notification_service.h"

#include <stdexcept>
#include <libnotify/notify.h>

namespace remindme
{
	notification_service::notification_service(const std::string &sAppName)
	{
		bool bRes = notify_init(sAppName.c_str());
		if (!bRes)
			throw std::runtime_error("cannot initialize notification service");
	}

	notification_service::~notification_service()
	{
		notify_uninit();
	}

	notification_service&
	notification_service::getInstance(const std::string &sAppName)
	{
		static notification_service ns{sAppName};
		return ns;
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
