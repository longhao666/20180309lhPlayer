#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include "videowidget_global.h"
#include <QVideoWidget>

class VIDEOWIDGETSHARED_EXPORT VideoWidget : public QVideoWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget *parent = 0);
    ~VideoWidget();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // VIDEOWIDGET_H
