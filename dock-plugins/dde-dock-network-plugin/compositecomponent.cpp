#include <QIcon>
#include <QLabel>

#include <dock/dockconstants.h>

#include "compositecomponent.h"

CompositeComponent::CompositeComponent(QObject *parent) :
    QObject(parent)
{
    QIcon::setThemeName("Deepin");

    m_item = new QLabel;
    m_item->setFixedSize(Dock::APPLET_FASHION_ICON_SIZE, Dock::APPLET_FASHION_ICON_SIZE);
    m_item->setPixmap(QIcon::fromTheme("network-online").pixmap(m_item->size()));
}

QString CompositeComponent::getUUID()
{
    return "uuid_composite";
}

QString CompositeComponent::getTitle()
{
    return "Network";
}

QWidget * CompositeComponent::getItem()
{
    return m_item;
}

void CompositeComponent::retainItem()
{
    m_item->setParent(NULL);
}

QWidget * CompositeComponent::getApplet()
{
    return NULL;
}

QString CompositeComponent::getMenuContent()
{
    return "";
}

void CompositeComponent::invokeMenuItem(QString, bool)
{

}