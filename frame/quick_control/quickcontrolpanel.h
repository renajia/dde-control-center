#ifndef QUICKCONTROLPANEL_H
#define QUICKCONTROLPANEL_H

#include <QWidget>
#include <QStackedLayout>
#include <QPushButton>

namespace dcc {

namespace network {

class NetworkModel;
class NetworkWorker;

}

}

class QuickControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit QuickControlPanel(QWidget *parent = 0);

signals:
    void requestDetailConfig() const;

private slots:
    void pageSwitched(const int index);
    void switchToggled(const int index);

private:
    QStackedLayout *m_itemStack;

    dcc::network::NetworkModel *m_networkModel;
    dcc::network::NetworkWorker *m_networkWorker;
};

#endif // QUICKCONTROLPANEL_H