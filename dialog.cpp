#include "dialog.h"
#include "ui_dialog.h"
#include "unolite.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnRed_clicked()
{
    //UnoLite.cColor = 'r';
}

void Dialog::on_btnBlue_clicked()
{

}

void Dialog::on_btnGreen_clicked()
{

}

void Dialog::on_btnYellow_clicked()
{

}
