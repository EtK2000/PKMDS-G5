/*
Copyright (C) 2013  codemonkey85

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef PKMVIEWER_H
#define PKMVIEWER_H
#include <QDialog>
#include <../../QT Project/qt_sqlite.h>
namespace Ui {
class pkmviewer;
}
class pkmviewer : public QDialog
{
    Q_OBJECT
public:
    MouseEventEater *mouseEventEater;
    QGraphicsView * markingsgraphics[6];
    QPixmap markingspix[6];
    QGraphicsScene* markingsscene[6];

#ifdef __linux__
    void setPKM(pokemon_obj * pkm_, int box, bool isPartyPKM);
    void setPKM(party_pkm * ppkm_, int box, bool isPartyPKM = true);
    void displayPKM();
    void updatemarks();
    void updatestats();
    void updatestatcolors();
    void updatemovepp();
    void updatemoveflavor();
    void updateabilityflavor();
    void updategenderpic();
    void updatemoveimages();
    void updatemoveinfo();
#else
    void pkmviewer::setPKM(pokemon_obj * pkm_, int box, bool isPartyPKM);
    void pkmviewer::setPKM(party_pkm * ppkm_, int box, bool isPartyPKM = true);
    void pkmviewer::displayPKM();
    void pkmviewer::updatemarks();
    void pkmviewer::updatestats();
    void pkmviewer::updatestatcolors();
    void pkmviewer::updatemovepp();
    void pkmviewer::updatemoveflavor();
    void pkmviewer::updateabilityflavor();
    void pkmviewer::updategenderpic();
    void pkmviewer::updatemoveimages();
    void pkmviewer::updatemoveinfo();
#endif
    explicit pkmviewer(QWidget *parent = 0);
    ~pkmviewer();
private slots:
    void on_cbPKMItem_currentIndexChanged(int index);

    void on_sbLevel_valueChanged(int arg1);

    void on_btnSaveChanges_clicked();

    void on_btnExportPKMFile_clicked();

    void on_cbPKMSpecies_currentIndexChanged(int index);

    void on_sbSpecies_valueChanged(int arg1);

    void on_txtNickname_textChanged(const QString &arg1);

    void on_sbEXP_valueChanged(int arg1);

    void on_rbOTMale_toggled(bool checked);

    void on_rbOTFemale_toggled(bool checked);

    void on_cbNicknamed_toggled(bool checked);

    void on_txtOTName_textChanged(const QString &arg1);

    void on_sbTID_valueChanged(int arg1);

    void on_sbSID_valueChanged(int arg1);

    void on_sbHPIV_valueChanged(int arg1);

    void on_sbAtkIV_valueChanged(int arg1);

    void on_sbDefIV_valueChanged(int arg1);

    void on_sbSpAtkIV_valueChanged(int arg1);

    void on_sbSpDefIV_valueChanged(int arg1);

    void on_sbSpeedIV_valueChanged(int arg1);

    void on_sbHPEV_valueChanged(int arg1);

    void on_sbSpeedEV_valueChanged(int arg1);

    void on_sbSpDefEV_valueChanged(int arg1);

    void on_sbSpAtkEV_valueChanged(int arg1);

    void on_sbDefEV_valueChanged(int arg1);

    void on_sbAtkEV_valueChanged(int arg1);

    void on_cbNatures_currentIndexChanged(int index);

    void on_cbMove1_currentIndexChanged(int index);

    void on_cbMove2_currentIndexChanged(int index);

    void on_cbMove3_currentIndexChanged(int index);

    void on_cbMove4_currentIndexChanged(int index);

    void on_sbMove1PPUps_valueChanged(int arg1);

    void on_sbMove1PP_valueChanged(int arg1);

    void on_sbMove2PPUps_valueChanged(int arg1);

    void on_sbMove2PP_valueChanged(int arg1);

    void on_sbMove3PPUps_valueChanged(int arg1);

    void on_sbMove3PP_valueChanged(int arg1);

    void on_sbMove4PPUps_valueChanged(int arg1);

    void on_sbMove4PP_valueChanged(int arg1);

    void on_cbPKMAbility_currentIndexChanged(int index);

    void on_cbBall_currentIndexChanged(int index);

    void on_sbCurrentSlot_valueChanged(int value);

    void on_chkHex_toggled(bool checked);

private:
    Ui::pkmviewer *ui;
};
#endif // PKMVIEWER_H
