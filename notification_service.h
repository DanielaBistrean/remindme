#ifndef REMINDME_NOTIFICATIONSERVICE_H
#define REMINDME_NOTIFICATIONSERVICE_H 1

#include "notification.h"

#include <string>
#include <memory>

namespace remindme
{
	class notification_service
	{
	public:
		~notification_service();
		static std::shared_ptr<notification_service> getInstance(const std::string &sAppName);

		notification createNotification(const std::string &sTitle, const std::string &sBody);
		notification createNotification(const std::string &sTitle);
	private:
		notification_service(const std::string &sAppName);
		static std::shared_ptr<notification_service> s_pInstance; // declared here for clarity
	};
}

#endif
