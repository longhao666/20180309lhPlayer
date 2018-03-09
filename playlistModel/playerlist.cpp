#include "playerlist.h"

#include <QDebug>

#define LHTEST 1

Playerlist::Playerlist()
{
    m_playerSong = new QStringList;
    m_playerLyric = new QStringList;
    m_playerSongPath = new QStringList;
    m_playerLyricPath = new QStringList;
    m_playCount = 0;
}

Playerlist::Playerlist(QStringList *playerSong, QStringList *playerLyric, int playCount)
    : m_playerSong(playerSong)
    , m_playerLyric(playerLyric)
    , m_playCount(playCount)
{

}

Playerlist::~Playerlist()
{
    delete m_playerSong;
    delete m_playerLyric;
}

void Playerlist::setPlayCount(int playCount)
{
    m_playCount = playCount;
}

int Playerlist::getPlayCount()
{
    return m_playCount;
}

void Playerlist::addPlayerSong(QString playerSong)
{
    Q_UNUSED(playerSong);
}

void Playerlist::songpathToSong()
{
    QString qstr;
    std::string str;
    std::size_t index;
    for(int i=0; i<this->m_playerSongPath->length(); i++) {
        qstr = this->m_playerSongPath->at(i);
#if LHTEST
        qDebug() << i << qstr;
#endif
        str = qstr.toStdString();
        index = str.rfind("/");
#if LHTEST
        qDebug() << index;
#endif
        this->m_playerSong->append(qstr.right(qstr.length() - index - 1));
        this->m_playCount++;
#if LHTEST
        qDebug() << i << this->m_playerSong->at(i);
#endif
    }
}
