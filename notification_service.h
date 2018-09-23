#ifndef REMINDME_NOTIFICATIONSERVICE_H
#define REMINDME_NOTIFICATIONSERVICE_H 1

#include "notification.h"

#include <string>

namespace remindme
{
	class notification_service
	{
	public:
		~notification_service();
		static notification_service& getInstance(const std::string &sAppName);

		notification createNotification(const std::string &sTitle, const std::string &sBody);
		notification createNotification(const std::string &sTitle);
	private:
		notification_service(const std::string &sAppName);
	};
}

#endif
