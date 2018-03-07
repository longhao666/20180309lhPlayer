#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
//#include <QWidget>

class QAbstractItemView;
class QLabel;
class QMediaPlayer;
class QModelIndex;
class QPushButton;
class QSlider;
class QVideoProbe;
class QVideoWidget;
class QAudioProbe;

class PlaylistModel;
class HistogramWidget;
class PlayerControls;

namespace Ui {
class Player;
}

class Player : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    ~Player();

    bool isPlayerAvailable() const;

    void addToPlaylist(const QList<QUrl> urls);

signals:
    void fullScreenChanged(bool fullScreen);

private slots:
    void open();
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
    void metaDataChanged();

    void previousClicked();

    void seek(int seconds);
    void jump(const QModelIndex &index);
    void playlistPositionChanged(int currentItem);

    void statusChanged(QMediaPlayer::MediaStatus status);
    void stateChanged(QMediaPlayer::State state);
    void bufferingProgress(int progress);
    void videoAvailableChanged(bool available);

    void displayErrorMessage();

    void showColorDialog();

private:
    void clearHistogram();
    void setTrackInfo(const QString &info);
    void setStatusInfo(const QString &info);
    void handleCursor(QMediaPlayer::MediaStatus status);
    void updateDurationInfo(qint64 currentInfo);

private:
    Ui::Player *ui;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget *videoWidget;
    QLabel *coverLabel;

    QSlider *slider;
    QLabel *labelDuration;
    QPushButton *fullScreenButton; // 全屏按钮
    QPushButton *colorButton; // 颜色按钮
    QDialog *colorDialog;

    QLabel *labelHistogram;
    HistogramWidget *videoHistogram;
    HistogramWidget *audioHistogram;
    QVideoProbe *videoProbe;
    QAudioProbe *audioProbe;

    PlaylistModel *playlistModel;
    QAbstractItemView *playlistView;
    QString trackInfo;
    QString statusInfo;
    qint64 duration;

    PlayerControls *controls;
};

#endif // PLAYER_H
