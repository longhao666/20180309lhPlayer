#include "player.h"
#include "ui_player.h"

#include <QPushButton>
#include <videowidget.h>
#include <playercontrols.h>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QDebug>
#include <string>
#include <QLabel>
#include <QListWidget>

#define LHTEST 1


Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , uiPlayer(new Ui::Player)
{
    uiPlayer->setupUi(this);

    player = new QMediaPlayer(this);

    this->musicShow();

    this->controlShow();


}

Player::~Player()
{

}

void Player::musicShow()
{
    playerlist = new Playerlist;

    showPlayer = new ShowPlayer;

    connect(showPlayer, &ShowPlayer::signalClickedListWidget, this, &Player::slotDoubleClicked);

    uiPlayer->layout->addLayout(showPlayer->getHBoxLayout());
//    showPlayer->showMV(*player);
//    showPlayer->showLyric();
}

void Player::controlShow()
{
    QPushButton *openButton = new QPushButton(tr("Open"), this);

    connect(openButton, SIGNAL(clicked()), this, SLOT(open()));
    // 创建 自定义的类,有暂停,播放,等功能
    PlayerControls *controls = new PlayerControls(this);
    controls->setState(player->state());
    controls->setVolume(player->volume());
    controls->setMuted(controls->isMuted());

    //! 一系列信号与槽
    // A:
    connect(controls, SIGNAL(play()), this, SLOT(playClicked()));
    connect(controls, SIGNAL(pause()), this, SLOT(pauseClicked()));
    connect(controls, SIGNAL(stop()), this, SLOT(stopClicked()));
    connect(controls, SIGNAL(next()), this, SLOT(nextClicked()));
    connect(controls, SIGNAL(previous()), this, SLOT(previousClicked()));
    connect(controls, SIGNAL(changeVolume(int)), this, SLOT(setVolumeClicked(int)));
    connect(controls, SIGNAL(changeMuting(bool)), this, SLOT(setMutedClicked(bool)));
    connect(controls, SIGNAL(changeRate(qreal)), this, SLOT(setPlaybackRate(qreal)));

//    connect(controls, SIGNAL(stop()), videoWidget, SLOT(update()));
    // B:
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),
            controls, SLOT(setState(QMediaPlayer::State)));
    connect(player, SIGNAL(volumeChanged(int)), controls, SLOT(setVolume(int)));
    connect(player, SIGNAL(mutedChanged(bool)), controls, SLOT(setMuted(bool)));

    //! 布局吧
    // 满屏按钮申请空间
    fullScreenButton = new QPushButton(tr("FullScreen"), this);
    fullScreenButton->setCheckable(true);
    // 颜色按钮申请空间
    colorButton = new QPushButton(tr("Color Options..."), this);
    colorButton->setEnabled(false);
    connect(colorButton, SIGNAL(clicked()), this, SLOT(showColorDialog()));

    QHBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->addWidget(controls, 1);
    controlLayout->addWidget(fullScreenButton, 0);
    controlLayout->addWidget(colorButton, 0);
    controlLayout->insertWidget(0, openButton, 0);

    uiPlayer->layout->addLayout(controlLayout);
}

void Player::playClicked()
{
    player->play();
}

void Player::pauseClicked()
{

}

void Player::stopClicked()
{

}

void Player::nextClicked()
{
//    showPlayer->showMV(*player);
}

void Player::previousClicked()
{
//    showPlayer->showLyric();
}

void Player::setVolumeClicked(int velue)
{

}

void Player::setMutedClicked(bool b)
{

}

void Player::setPlaybackRate(qreal q)
{

}

void Player::open()
{

    *(playerlist->m_playerSongPath) = QFileDialog::getOpenFileNames(this,
                                                             tr("open Music"),
                                                             tr("./"),
                                                             tr("all(*);; Music(*.mp3 *.avi);; MV(*.mp4)"));
    playerlist->songpathToSong();
    showPlayer->addsonglistToListWidget(*(playerlist->m_playerSong));
}

void Player::slotDoubleClicked(QModelIndex index)
{
#if LHTEST
    qDebug() << "void Player::slotDoubleClicked(QModelIndex index)" << index.row();
#endif
    player->stop();
    player->setMedia(QUrl(playerlist->m_playerSongPath->at(index.row())));
    player->play();
}
