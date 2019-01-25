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

		bool show(const unsigned &uTimeout = 0);
		void close();
	private:
		notification(const std::string &sTitle, bool bAutoClose = false);
		notification(const std::string &sTitle, const std::string &sBody, bool bAutoClose = false);
		
		std::string 		m_sTitle;
		std::string 		m_sBody;
		NotifyNotification* m_pNotification;
		bool 				m_bAutoClose;

		friend class notification_service;
	};
}

#endif
