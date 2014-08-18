#ifndef HEIDENHERSH_H
#define HEIDENHERSH_H

#include <QWidget>
#include "fonttablemodel.h"
#include <Font.h>

namespace Ui {
class Heidenhersh;
}

class Heidenhersh : public QWidget
{
    Q_OBJECT

public:
    explicit Heidenhersh(QWidget *parent = 0);
    ~Heidenhersh();

private slots:
    void on_buttGenerate_clicked();

    void on_buttSimulate_clicked();

private:
    Ui::Heidenhersh *ui;
    FontTableModel *cmbFontsModel;
    hersh::Font font;
    hersh::FontMap font_map;
    std::vector<hersh::Glyph> glyphs;

    void loadFont();
    void create_glyphs();
};

#endif // HEIDENHERSH_H
