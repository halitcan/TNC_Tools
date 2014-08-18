#ifndef FONTTABLEMODEL_H
#define FONTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>

class FontTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Columns
    {
        Name = 0, FontPath = 1, MapPath = 2
    };

    explicit FontTableModel( QObject *parent = 0 );
    int rowCount( const QModelIndex &parent = QModelIndex() ) const;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const;
    QVariant data( const QModelIndex &index, int role ) const;
    QString getName( int row );
    QString getFontPath( int row );
    QString getMapPath( int row );

private:
    QStringList names;
    QStringList font_paths;
    QStringList map_paths;

    void loadFonts();

signals:

public slots:

};

#endif // FONTTABLEMODEL_H
