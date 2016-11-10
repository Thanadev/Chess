#include "notificationbus.h"

NotificationBus* NotificationBus::instance = NULL;

NotificationBus::NotificationBus(QObject *parent) : QObject(parent)
{

}

NotificationBus::~NotificationBus()
{

}

NotificationBus* NotificationBus::getInstance()
{
    if (instance == NULL) {
        instance = new NotificationBus();
    }

    return instance;
}

