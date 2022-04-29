#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMouseEvent>

enum Colour
{
    Red = 0,
    Green,
    Yellow,
    Blue,
    None
};

class Card : public QWidget
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = nullptr);
    void setup(QString, Colour);
    QString cardName();
    QString cardColour();
    void showFront();
    void showBack();
    void showCorners();
    //int cardPosition;

private:
    void mousePressEvent(QMouseEvent*);
    QLabel *lbl;
    QLabel *lblB;
    QLabel *lblRed;
    QLabel *lblGreen;
    QLabel *lblYellow;
    QLabel *lblBlue;
    QString name;
    QString colour;
    bool corners;

signals:
    void iWasClicked(Card*);

};

#endif // CARD_H
