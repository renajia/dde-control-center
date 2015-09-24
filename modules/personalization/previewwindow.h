#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QLabel>
#include <QPointer>
#include <QPixmap>
#include <QVariantAnimation>

#include <libdui/dwindowclosebutton.h>
#include <libdui/libdui_global.h>

#include "mousearea.h"

DUI_USE_NAMESPACE

class QHBoxLayout;
class PreviewWindow : public MouseArea
{
    Q_OBJECT
public:
    explicit PreviewWindow(QWidget *parent = 0);
    ~PreviewWindow();
    void setImages(const QStringList &list);

public slots:
    void show(const QString &key);
    void close();

signals:
    void apply(const QString &key);

private slots:
    void updateCursor();

protected:
    void paintEvent(QPaintEvent *e);

private:
    int m_image_index_left = 0;
    int m_image_index_right = 0;
    QList<QPixmap> m_imageList;
    QPointer<QWidget> m_controlCenterWindow;
    int m_pixmap_x = 0;
    int m_pressed_x = 0;
    qreal m_top_rect_opacity = 0;
    QRect m_show_arrow_rect;
    QVariantAnimation m_animation_image_switch;
    QVariantAnimation m_animation_rect_opacity;
    DWindowCloseButton *m_closeButton;
    QString m_key;
    QHBoxLayout *m_indicatorLayout;

    void initUI();
    void imageToRight();
    void imageToLeft();
    void showTopRect();
    void hideTopRect();
    void updateActiveIndicator(int currentIndex, int newIndex);
};

#endif // PREVIEWWINDOW_H
