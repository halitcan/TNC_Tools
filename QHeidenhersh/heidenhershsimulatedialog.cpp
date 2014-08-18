#include "heidenhershsimulatedialog.h"
#include "ui_heidenhershsimulatedialog.h"

#include <QPolygonF>
#include <QDebug>
#include <QGraphicsPathItem>

HeidenhershSimulateDialog::HeidenhershSimulateDialog( QWidget *parent ) :
    QDialog( parent ), ui( new Ui::HeidenhershSimulateDialog ), depth( 0.3f ), glyphs( nullptr )
{
    ui->setupUi( this );

    ui->gvDisplay->setScene( &scene );

    connect( ui->dspnAngle, SIGNAL( valueChanged( double ) ), this, SLOT( draw() ) );
    connect( ui->dspnTipGrind, SIGNAL( valueChanged( double ) ), this, SLOT( draw() ) );
}

HeidenhershSimulateDialog::~HeidenhershSimulateDialog()
{
    delete ui;
}

void HeidenhershSimulateDialog::setDepth(double value)
{
    depth = value;
}

void HeidenhershSimulateDialog::setGlyphs(std::vector<hersh::Glyph> *g)
{
    glyphs = g;
}

void HeidenhershSimulateDialog::setHeight( double value )
{
    height = value;
}

void HeidenhershSimulateDialog::draw()
{
    scene.clear();

    QPen pen( Qt::black, calc_pen_width(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin );

    if( glyphs != nullptr )
    {
        if( glyphs->size() > 0 )
            scene.setSceneRect( (qreal)glyphs->at( 0 ).getLPos(),
                                (qreal)-height / 2,
                                (qreal)glyphs->at( glyphs->size() - 1 ).getRPos(),
                                (qreal)height );

        for( hersh::Glyph g : *glyphs )
        {
            for( std::vector<hersh::Vertex> p : g.getPaths() )
            {
                QPainterPath path;
                for( auto v = p.begin(); v != p.end(); v++ )
                {
                    if( v == p.begin() )
                        path.moveTo( v->getX(), v->getY() );
                    else
                        path.lineTo( v->getX(), v->getY() );
                }

                scene.addPath( path, pen );
            }
        }
    }
}

double HeidenhershSimulateDialog::calc_pen_width()
{
    double angle = (ui->dspnAngle->value() / 2) * (M_PI / 180.0f ); //Radians
    double adjacent = depth + ui->dspnTipGrind->value();
    double opposite = tan( angle ) / adjacent;

    return opposite * 2;
}
