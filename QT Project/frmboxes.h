/*
***********************************************
PKMDS Code Library - Gen V

Created by Michael Bond (aka Codemonkey85)
https://plus.google.com/116414067936940758871/

Feel free to use and reuse this code as you see fit, but I
implore you to always link back to me as the original creator.
***********************************************

Thanks to Alex "eevee" Munroe at http://veekun.com/
for his SQLite Pokedex database, which powers this software.

Thanks to the fine folks at SQLite.org for making it possible
to use the Pokedex database... the source files "sqlite3.c"
and "sqlite3.h" came from these people.

Thanks to those of Project Pokemon (http://projectpokemon.org/)
who have helped research and document the underlying structure
of Pokemon game save files.

Special thanks to SCV, Sabresite, loadingNOW, Poryhack,
GatorShark, Jiggy-Ninja, Codr, Bond697, mingot, Guested,
coolbho3000 and of course, COM.

Some documentation available at: http://www.projectpokemon.org/wiki/
*/
#ifndef FRMBOXES_H
#define FRMBOXES_H
#include <QMainWindow>
#include "qt_sqlite.h"
#include "mouseeventeater.h"
namespace Ui {
class frmBoxes;
}
class frmBoxes : public QMainWindow
{
    Q_OBJECT
public:
    explicit frmBoxes(QWidget *parent = 0);
    MouseEventEater *mouseEventEater; // = new MouseEventEater(this);
    QGraphicsView * partygraphics[6];
    QPixmap partypix[6];
    QGraphicsScene* partyscenes[6];
    QGraphicsView* boxgraphics[30];
    QPixmap boxpix[30];
    QGraphicsScene* boxscenes[30];
    ~frmBoxes();
private slots:
    void on_actionLoad_SAV_triggered();
    void on_cbBoxes_currentIndexChanged(int index);
    void changebox(int index);
    void on_sbBoxIncrem_valueChanged(int value);
private:
    Ui::frmBoxes *ui;
};
#endif // FRMBOXES_H
