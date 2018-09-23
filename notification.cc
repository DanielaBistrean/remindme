#include "notification.h"

#include <stdexcept>

namespace remindme
{
	notification::notification(const std::string &sTitle)
	: m_sTitle{sTitle}
	, m_pNotification{nullptr}
	{
		m_pNotification = notify_notification_new (m_sTitle.c_str(), m_sBody.c_str(), 0);
		if (m_pNotification == nullptr)
			throw std::runtime_error("cannot create notification");
	}

	notification::notification(const std::string &sTitle, const std::string &sBody)
	: m_sTitle{sTitle}
	, m_sBody{sBody}
	, m_pNotification{nullptr}
	{
		m_pNotification = notify_notification_new (m_sTitle.c_str(), m_sBody.c_str(), 0);
		if (m_pNotification == nullptr)
			throw std::runtime_error("cannot create notification");
	}

	notification::~notification()
	{
		notify_notification_close(m_pNotification, 0);
	}

	bool
	notification::show(const unsigned &uTimeout)
	{
		notify_notification_set_timeout(m_pNotification, uTimeout);
		return notify_notification_show(m_pNotification, 0);
	}

}
