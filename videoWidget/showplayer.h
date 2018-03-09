#ifndef SHOWPLAYER_H
#define SHOWPLAYER_H

#include "videowidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMediaPlayer>
#include <QModelIndex>
#include <QObject>

class VIDEOWIDGETSHARED_EXPORT ShowPlayer
{
    Q_OBJECT
public:
    ShowPlayer();
    ~ShowPlayer();
    void showLyric();
    void showMV(QMediaPlayer &p);
    void addsonglistToListWidget(QStringList &s);
    QHBoxLayout *getHBoxLayout();

signals:
    void signalClickedListWidget(QModelIndex index);

private:
    VideoWidget *videoWidget;
    QHBoxLayout *hBoxLayout;
    QLabel *label;
    QListWidget *listWidget;
};

#endif // SHOWPLAYER_H
