#include "heidenhersh.h"
#include "ui_heidenhersh.h"

#include "heidenhershsimulatedialog.h"
#include <QMessageBox>

Heidenhersh::Heidenhersh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Heidenhersh)
{
    ui->setupUi(this);

    cmbFontsModel = new FontTableModel;
    ui->cmbFont->setModel( cmbFontsModel );
}

Heidenhersh::~Heidenhersh()
{
    delete ui;
}

void Heidenhersh::loadFont()
{
    int index = ui->cmbFont->currentIndex();

    if( index < 0 )
        return;

    font.load( cmbFontsModel->getFontPath( index ).toStdString() );
    font_map.load( cmbFontsModel->getMapPath( index ).toStdString() );
}

void Heidenhersh::create_glyphs()
{
    glyphs.clear();

    if( ui->txtInput->text().length() <= 0 )
        return;

    loadFont();

    try
    {
        glyphs = font.getGlyphs( ui->txtInput->text().toStdWString(), font_map );
    }
    catch( hersh::Font::NoSuchGlyph & )
    {
        glyphs.clear();
        QMessageBox::critical( this, "Error", "No such glyph" );
    }

    double scale = ui->dspnTextHeight->value();
    double spacing = ui->dspnSpacing->value();
    for( auto g = glyphs.begin(); g != glyphs.end(); g++ )
    {
        if( scale != 1.0f )
            g->scale( scale );

        if( ui->chkMirror->isChecked() )
            g->mirror( true, false );

        if( !ui->chkRotary->isChecked() && g != glyphs.begin() )
        {
            auto prev = g - 1;
            g->translate( (float)prev->getRPos() + (g->getLPos() * -1) + spacing + (float)(g->getLPos() * -1), 0.0f );
        }
    }
}

void Heidenhersh::on_buttGenerate_clicked()
{
    create_glyphs();

    if( glyphs.size() <= 0 )
        return;
}

void Heidenhersh::on_buttSimulate_clicked()
{
    create_glyphs();

    if( glyphs.size() <= 0 )
        return;

    HeidenhershSimulateDialog *d = new HeidenhershSimulateDialog;

    d->setDepth( ui->dspnDepth->value() );
    d->setGlyphs( &glyphs );
    d->setHeight( ui->dspnTextHeight->value() );
    d->draw();

    d->show();
}
