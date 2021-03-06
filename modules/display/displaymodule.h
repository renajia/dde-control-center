#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include "moduleinterface.h"
#include "miracastmodel.h"

namespace dcc {
class ModuleWidget;

namespace display {
class Monitor;
class DisplayWorker;
class DisplayModel;
class DisplayWidget;
class MiracastWorker;
class DisplayModule : public QObject, public ModuleInterface
{
    Q_OBJECT

public:
    explicit DisplayModule(FrameProxyInterface *frame, QObject *parent = 0);
    ~DisplayModule();

private slots:
    void showBrightnessPage();
    void showResolutionDetailPage();
    void showCustomSettings(const QString &config);
    void showConfigPage(const QString &config);
    void showRecognize();
#ifndef DCC_DISABLE_ROTATE
    void showRotate(Monitor *mon = nullptr);
#endif

#ifndef DCC_DISABLE_MIRACAST
    void showMiracastPage(const QDBusObjectPath &path);
#endif

private:
    void initialize();
    void reset();
    void moduleActive();
    void moduleDeactive();
    void contentPopped(ContentWidget * const w);
    const QString name() const;
    ModuleWidget *moduleWidget();

private:
    DisplayModel *m_displayModel;
    DisplayWorker *m_displayWorker;
    DisplayWidget *m_displayWidget;
    MiracastModel *m_miracastModel;
    MiracastWorker *m_miracastWorker;
};

} // namespace display

} // namespace dcc

#endif // DISPLAYMODULE_H
