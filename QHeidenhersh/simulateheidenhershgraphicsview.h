#ifndef SIMULATEHEIDENHERSHGRAPHICSVIEW_H
#define SIMULATEHEIDENHERSHGRAPHICSVIEW_H

#include <QGraphicsView>

class SimulateHeidenhershGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SimulateHeidenhershGraphicsView(QWidget *parent = 0);

signals:

protected:
    virtual void wheelEvent( QWheelEvent *event );

public slots:

};

#endif // SIMULATEHEIDENHERSHGRAPHICSVIEW_H
