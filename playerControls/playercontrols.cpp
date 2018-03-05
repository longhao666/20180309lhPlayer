/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "playercontrols.h"

#include <QBoxLayout>
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include <QComboBox>
#include <QAudio>
#include <QIcon>

PlayerControls::PlayerControls(QWidget *parent)
    : QWidget(parent)
    , playerState(QMediaPlayer::StoppedState)
    , playerMuted(false)
    , playButton(0)
    , stopButton(0)
    , nextButton(0)
    , previousButton(0)
    , muteButton(0)
    , volumeSlider(0)
    , rateBox(0)
{
    // 1
    playButton = new QToolButton(this);
#if 0
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
#elif 1
    playButton->setIcon(QIcon(QString(":/image/png1/7.png")));
#endif
    connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));
    // 2
    stopButton = new QToolButton(this);
#if 0
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
#elif 1
    stopButton->setIcon(QIcon(QString(":/image/png1/11.png")));
#endif
    stopButton->setEnabled(false);
    connect(stopButton, SIGNAL(clicked()), this, SIGNAL(stop()));
    // 3
    nextButton = new QToolButton(this);
#if 0
    nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
#elif 1
    nextButton->setIcon(QIcon(QString(":/image/png1/3.png")));
#endif
    connect(nextButton, SIGNAL(clicked()), this, SIGNAL(next()));
    // 4
    previousButton = new QToolButton(this);
#if 0
    previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
#elif 1
    previousButton->setIcon(QIcon(QString(":/image/png1/8.png")));
#endif
    connect(previousButton, SIGNAL(clicked()), this, SIGNAL(previous()));
    // 5
    muteButton = new QToolButton(this);
#if 0
    muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
#elif 1
    muteButton->setIcon(QIcon(QString(":/image/gnome/Image-audio-volume-high.png")));
#endif
    connect(muteButton, SIGNAL(clicked()), this, SLOT(muteClicked()));
    // 6
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    connect(volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(onVolumeSliderValueChanged()));
    // 7
    rateBox = new QComboBox(this);
    rateBox->addItem("0.5x", QVariant(0.5));
    rateBox->addItem("1.0x", QVariant(1.0));
    rateBox->addItem("2.0x", QVariant(2.0));
    rateBox->setCurrentIndex(1);

    connect(rateBox, SIGNAL(activated(int)), SLOT(updateRate()));

    QBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(stopButton);
    layout->addWidget(previousButton);
    layout->addWidget(playButton);
    layout->addWidget(nextButton);
    layout->addWidget(muteButton);
    layout->addWidget(volumeSlider);
    layout->addWidget(rateBox);
    setLayout(layout);
}

PlayerControls::~PlayerControls()
{

}

/*
 * 返回播放状态
 *
*/
QMediaPlayer::State PlayerControls::state() const
{
    return playerState;
}

int PlayerControls::volume() const
{
    qreal linearVolume =  QAudio::convertVolume(volumeSlider->value() / qreal(100),
                                                QAudio::LogarithmicVolumeScale,
                                                QAudio::LinearVolumeScale);

    return qRound(linearVolume * 100);
}

bool PlayerControls::isMuted() const
{
    return playerMuted;
}

qreal PlayerControls::playbackRate() const
{
    return rateBox->itemData(rateBox->currentIndex()).toDouble();
}

/*
 * 设置播放状态
 *
*/
void PlayerControls::setState(QMediaPlayer::State state)
{
    if (state != playerState) {
        playerState = state;

        switch (state) {
        case QMediaPlayer::StoppedState:
            stopButton->setEnabled(false);
#if 0
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
#elif 1
            playButton->setIcon(QIcon(QString(":/image/png1/5.png")));
#endif
            break;
        case QMediaPlayer::PlayingState:
            stopButton->setEnabled(true);
#if 0
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
#elif 1
            playButton->setIcon(QIcon(QString(":/image/png1/7.png")));
#endif
            break;
        case QMediaPlayer::PausedState:
            stopButton->setEnabled(true);
#if 0
            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
#elif 1
            playButton->setIcon(QIcon(QString(":/image/png1/5.png")));
#endif
            break;
        }
    }
}

void PlayerControls::setVolume(int volume)
{
    qreal logarithmicVolume = QAudio::convertVolume(volume / qreal(100),
                                                    QAudio::LinearVolumeScale,
                                                    QAudio::LogarithmicVolumeScale);

    volumeSlider->setValue(qRound(logarithmicVolume * 100));
}

void PlayerControls::setMuted(bool muted)
{
    if (muted != playerMuted) {
        playerMuted = muted;
#if 0
        muteButton->setIcon(style()->standardIcon(muted
                ? QStyle::SP_MediaVolumeMuted
                : QStyle::SP_MediaVolume));
#elif 1
        if(muted) {
            muteButton->setIcon(QIcon(QString(":/image/gnome/Image-audio-volume-muted-blocking-panel.png")));
        }else {
            muteButton->setIcon(QIcon(QString(":/image/gnome/Image-audio-volume-high.png")));
        }
#endif
    }
}

void PlayerControls::setPlaybackRate(float rate)
{
    for (int i = 0; i < rateBox->count(); ++i) {
        if (qFuzzyCompare(rate, float(rateBox->itemData(i).toDouble()))) {
            rateBox->setCurrentIndex(i);
            return;
        }
    }

    rateBox->addItem(QString("%1x").arg(rate), QVariant(rate));
    rateBox->setCurrentIndex(rateBox->count() - 1);
}

/*
 * 播放按钮点击事件
*/
void PlayerControls::playClicked()
{
    // 播放时点就是暂停,停止或暂停时点就是播放
    switch (playerState) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        emit play();
        break;
    case QMediaPlayer::PlayingState:
        emit pause();
        break;
    }
}

void PlayerControls::muteClicked()
{
    emit changeMuting(!playerMuted);
}

void PlayerControls::updateRate()
{
    emit changeRate(playbackRate());
}

void PlayerControls::onVolumeSliderValueChanged()
{
    emit changeVolume(volume());
}