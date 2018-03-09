#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <QStringList>

class Q_DECL_EXPORT Playerlist
{
public: 
    Playerlist();
    Playerlist(QStringList *playerSong, QStringList *playerLyric,int playCount);
    ~Playerlist();

    void setPlayCount(int playCount);
    int getPlayCount();
    void addPlayerSong(QString playerSong);
    void songpathToSong();

public:
    QStringList *m_playerSongPath;
    QStringList *m_playerLyricPath;
    QStringList *m_playerSong;
    QStringList *m_playerLyric;
    int m_playCount;

};

#endif // PLAYERLIST_H
