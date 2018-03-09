#include "showPlayer.h"


#include <QDebug>

#define LHTEST 1

ShowPlayer::ShowPlayer()
{
    listWidget = new QListWidget;
    videoWidget = new VideoWidget;
    label = new QLabel;
    hBoxLayout = new QHBoxLayout;
    label->setStyleSheet("background:white");
    hBoxLayout->addWidget(listWidget, 1);
    hBoxLayout->addWidget(label, 2);
}

ShowPlayer::~ShowPlayer()
{

}

void ShowPlayer::showLyric()
{
    if(!hBoxLayout && !listWidget) {
        qDebug() << hBoxLayout << listWidget;
        qDebug() << "void ShowPlayer::showLyric()" << "hBoxLayout is NULL! ";
        return ;
    }
    if(!label) {
        qDebug() << "void ShowPlayer::showLyric()" << "label is NULL! ";
        return ;
    }
#if LHTEST
    qDebug() << "================1" << hBoxLayout->count();
#endif
    hBoxLayout->replaceWidget(videoWidget, label, Qt::FindChildrenRecursively);
#if LHTEST
    qDebug() << "================2" << hBoxLayout->count();
#endif
}

void ShowPlayer::showMV(QMediaPlayer &p)
{
    if(!hBoxLayout && !listWidget) {
        qDebug() << "void ShowPlayer::showMV(QMediaPlayer &p)" << "hBoxLayout is NULL! ";
        return ;
    }
    if(!videoWidget) {
        qDebug() << "void ShowPlayer::showMV(QMediaPlayer &p)" << "videoWidget is NULL! ";
        return ;
    }
//    p.setVideoOutput(videoWidget);
#if LHTEST
    qDebug() << "================1" << hBoxLayout->count();
#endif
//    hBoxLayout->removeWidget(hBoxLayout->itemAt(1)->widget());
#if LHTEST
    qDebug() << "================2" << hBoxLayout->count();
#endif
    hBoxLayout->replaceWidget(label, videoWidget, Qt::FindChildrenRecursively);
//    hBoxLayout->addWidget(videoWidget, 2);
#if LHTEST
    qDebug() << "================3" << hBoxLayout->count();
#endif
}

void ShowPlayer::addsonglistToListWidget(QStringList &s)
{
    listWidget->addItems(s);
}

QHBoxLayout *ShowPlayer::getHBoxLayout()
{
    return this->hBoxLayout;
}

