#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "unolite.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnRed_clicked();
    void on_btnBlue_clicked();
    void on_btnGreen_clicked();
    void on_btnYellow_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
