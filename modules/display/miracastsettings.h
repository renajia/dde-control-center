#ifndef MIRACASTSETTINGS_H
#define MIRACASTSETTINGS_H

#include "contentwidget.h"
#include "switchwidget.h"
#include "settingsgroup.h"
#include "miracastnodevicepage.h"
#include "miracastdevicemodel.h"
#include "miracastitem.h"
#include "miracastmodel.h"
#include "../widgets/labels/normallabel.h"
#include "QVBoxLayout"

using namespace dcc::widgets;

namespace dcc {

namespace display {

class MiracastPage : public ContentWidget
{
    Q_OBJECT
public:
    explicit MiracastPage(const QString &title, QWidget *parent = 0);
    void setModel(MiracastDeviceModel *model);

signals:
    void requestDeviceEnable(const QDBusObjectPath &path, const bool enable);
    void requestDeviceConnect(const QDBusObjectPath &path, const QRect &rect);
    void requestDeviceDisConnect(const QDBusObjectPath &path);

private slots:
    void onItemAdded(MiracastItem *item);
    void onItemRemoved(MiracastItem *item);
    void onDeviceEnableChanged(const bool enable);

private:
    QVBoxLayout *m_mainLayout;
    MiracastNoDevicePage *m_nodevice;
    SettingsGroup *m_deviceGrp;
    MiracastDeviceModel *m_model;
    SwitchWidget *m_deviceSwBtn;
    NormalLabel *m_tip;
};

}
}

#endif // MIRACASTSETTINGS_H
