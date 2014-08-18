#include "simulateheidenhershgraphicsview.h"
#include <QWheelEvent>

SimulateHeidenhershGraphicsView::SimulateHeidenhershGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    setDragMode( ScrollHandDrag );
}

void SimulateHeidenhershGraphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor( AnchorUnderMouse );
    double scaleFactor = 1.15;

    if( event->delta() > 0 )
        scale( scaleFactor, scaleFactor );
    else
        scale( 1.0f / scaleFactor, 1.0f / scaleFactor );
}
