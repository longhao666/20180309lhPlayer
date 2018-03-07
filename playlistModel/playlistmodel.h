#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include "playlistmodel_global.h"
#include <QAbstractItemModel>

class QMediaPlaylist;

class PLAYLISTMODELSHARED_EXPORT PlaylistModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Column
    {
        Title = 0,
        ColumnCount
    };

public:
    PlaylistModel(QObject *parent = 0);
    ~PlaylistModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QMediaPlaylist *playlist() const;
    void setPlaylist(QMediaPlaylist *playlist);
    //Qt::DisplayRole   0   The key data to be rendered in the form of text. (QString)
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole) override;

private slots:
    void beginInsertItems(int start, int end);
    void endInsertItems();
    void beginRemoveItems(int start, int end);
    void endRemoveItems();
    void changeItems(int start, int end);

private:
    QMediaPlaylist *m_playlist;
    QMap<QModelIndex, QVariant> m_data;
};

#endif // PLAYLISTMODEL_H
