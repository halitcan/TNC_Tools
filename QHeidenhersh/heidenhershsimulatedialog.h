#ifndef HEIDENHERSHSIMULATEDIALOG_H
#define HEIDENHERSHSIMULATEDIALOG_H

#include <QDialog>
#include <Font.h>
#include <QGraphicsScene>
#include <QPainter>

namespace Ui {
class HeidenhershSimulateDialog;
}

class HeidenhershSimulateDialog : public QDialog
{
    Q_OBJECT

public:
    HeidenhershSimulateDialog( QWidget *parent = 0 );
//    HeidenhershSimulateDialog( QWidget *parent = 0, double depth = 0.3, std::vector<hersh::Glyph> *g = nullptr );
    ~HeidenhershSimulateDialog();
    void setDepth( double value );
    void setGlyphs( std::vector<hersh::Glyph> *g );
    void setHeight( double value );

public slots:
    void draw();

private:
    Ui::HeidenhershSimulateDialog *ui;
    double depth;
    double height;
    std::vector<hersh::Glyph> *glyphs;
    QGraphicsScene scene;

    double calc_pen_width();

};

#endif // HEIDENHERSHSIMULATEDIALOG_H
