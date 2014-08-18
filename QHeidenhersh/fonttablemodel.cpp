#include "fonttablemodel.h"
#include <QDir>
#include <QFile>
#include <QDebug>

FontTableModel::FontTableModel( QObject *parent ) :
    QAbstractTableModel(parent)
{
    loadFonts();
}

int FontTableModel::rowCount( const QModelIndex & ) const
{
    return names.count();
}

int FontTableModel::columnCount( const QModelIndex & ) const
{
    return 3;
}

QVariant FontTableModel::data( const QModelIndex &index, int role ) const
{
    if( !index.isValid() || role != Qt::DisplayRole )
        return QVariant();

    switch( index.column() )
    {
        case Name:
            return names[index.row()];
        case FontPath:
            return font_paths[index.row()];
        case MapPath:
            return map_paths[index.row()];
        default:
            break;
    }

    return QVariant();
}

QString FontTableModel::getName( int row )
{
    if( row >= rowCount() )
        return QString();

    return names[row];
}

QString FontTableModel::getFontPath( int row )
{
    if( row >= rowCount() )
        return QString();

    return font_paths[row];
}

QString FontTableModel::getMapPath( int row )
{
    if( row >= rowCount() )
        return QString();

    return map_paths[row];
}

void FontTableModel::loadFonts()
{
    names.clear();
    font_paths.clear();
    map_paths.clear();

    QDir font_dir( "fonts" );
    QStringList font_names = font_dir.entryList( QStringList( "*.jhf" ), QDir::Files, QDir::Name );
    QString font_path = font_dir.absolutePath();

    QDir map_dir( "font_maps" );
    QStringList map_names = map_dir.entryList( QStringList( "*.hmp" ), QDir::Files, QDir::Name );
    QString map_path = map_dir.absolutePath();


    for( QString fn : font_names )
    {
        QString curr_font_name = fn.split( '.', QString::SkipEmptyParts )[0];

        for( QString mn : map_names )
        {
            QString curr_map_name = mn.split( '.', QString::SkipEmptyParts )[0];
            if( curr_font_name == curr_map_name )
            {
                names.append( curr_font_name );
                font_paths.append( font_path + QDir::separator() + fn );
                map_paths.append( map_path + QDir::separator() + mn );
                break;
            }
        }
    }
}

