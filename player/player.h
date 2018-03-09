#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QModelIndex>

#include "playerlist.h"
#include "showplayer.h"


class QPushButton;
class QListWidget;
class QLabel;

namespace Ui {
class Player;
}

class Player : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    ~Player();

public slots:


private:
    void musicShow();
    void controlShow();

private slots:
    void playClicked();
    void pauseClicked();
    void stopClicked();
    void nextClicked();
    void previousClicked();
    void setVolumeClicked(int velue);
    void setMutedClicked(bool b);
    void setPlaybackRate(qreal q);
    void open();
    void slotDoubleClicked(QModelIndex index);

private:
    Ui::Player *uiPlayer;

    QMediaPlayer *player;

    Playerlist *playerlist;
    ShowPlayer *showPlayer;


    QPushButton *fullScreenButton; // 全屏按钮
    QPushButton *colorButton; // 颜色按钮

};

#endif // PLAYER_H
