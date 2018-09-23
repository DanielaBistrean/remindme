#ifndef REMINDME_NOTIFICATION_H
#define REMINDME_NOTIFICATION_H 1

#include <string>
#include <libnotify/notify.h>

namespace remindme
{
	class notification
	{
	public:
		~notification();

		bool show(const unsigned &uTimeout);
	private:
		notification(const std::string &sTitle);
		notification(const std::string &sTitle, const std::string &sBody);
		
		std::string 		m_sTitle;
		std::string 		m_sBody;
		NotifyNotification* m_pNotification;

		friend class notification_service;
	};
}

#endif
