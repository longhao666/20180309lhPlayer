#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include "histogramwidget_global.h"

#include <QThread>
#include <QVideoFrame>
#include <QAudioBuffer>
#include <QWidget>

class QAudioLevel;

class FrameProcessor : public QObject
{
    Q_OBJECT

public slots:
    void processFrame(QVideoFrame frame, int levels);

signals:
    void histogramReady(QVector<qreal> histogram);
};

class HISTOGRAMWIDGETSHARED_EXPORT HistogramWidget : public QWidget
{
    Q_OBJECT

public:
    HistogramWidget(QWidget *parent = 0);
    ~HistogramWidget();
    void setLevels(int levels)
    {
        m_levels = levels;
    }

public slots:
    void processFrame(QVideoFrame frame);
    void processBuffer(QAudioBuffer buffer);
    void setHistogram(QVector<qreal> histogram);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<qreal> m_histogram;
    int m_levels;
    FrameProcessor m_processor;
    QThread m_processorThread;
    bool m_isBusy;
    QVector<QAudioLevel *> audioLevels;
};

#endif // HISTOGRAMWIDGET_H
