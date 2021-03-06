#ifndef MIRACASTITEM_H
#define MIRACASTITEM_H

#include "settingsitem.h"
#include "../widgets/loadingindicator.h"
#include <types/sinkinfolist.h>
#include <QWidget>
#include <QLabel>

using namespace dcc::widgets;

namespace dcc {
namespace display {
class MiracastItem : public SettingsItem
{
    Q_OBJECT
public:
    explicit MiracastItem(const SinkInfo &info, QWidget *parent = 0);
    const SinkInfo info() const;
    void onConnectState(bool state);

signals:
    void requestSinkConnect(const QDBusObjectPath &path, const QRect &rect);
    void requestSinkDisConnect(const QDBusObjectPath &path);

protected:
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

private:
    SinkInfo m_info;
    QLabel *m_title;
    QLabel *m_connect;
    LoadingIndicator *m_loading;
};
}
}

#endif // MIRACASTITEM_H
