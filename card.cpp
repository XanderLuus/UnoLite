#include "card.h"

Card::Card(QWidget *parent) : QWidget(parent)
{
    corners = false;

    lbl = new QLabel(this);
    setFixedSize(64, 96);
    lbl->setFixedSize(64, 96);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setText("??");
    lbl->show();

    lblB = new QLabel(this);
    lblB->setFixedSize(64, 96);
    lblB->setAlignment(Qt::AlignCenter);
    lblB->setStyleSheet("border: 8px solid gray; background-color: #c0c0c0; font-size: 16px;");
    lblB->setText("UnO\nLitE");
    lblB->hide();

    lblRed = new QLabel(this);
    lblRed->setGeometry(0, 0, 16, 16);
    lblRed->setStyleSheet("background-color: red;");
    lblRed->hide();
    lblGreen = new QLabel(this);
    lblGreen->setGeometry(48, 0, 16, 16);
    lblGreen->setStyleSheet("background-color: green;");
    lblGreen->hide();
    lblYellow = new QLabel(this);
    lblYellow->setGeometry(0, 80, 16, 16);
    lblYellow->setStyleSheet("background-color: yellow;");
    lblYellow->hide();
    lblBlue = new QLabel(this);
    lblBlue->setGeometry(48, 80, 16, 16);
    lblBlue->setStyleSheet("background-color: cyan;");
    lblBlue->hide();

    connect(this, SIGNAL(iWasClicked(Card*)), parent, SLOT(cardClick(Card*)));
}

void Card::setup(QString text, Colour clr)
{
    //cardPosition = 0;
    name = text;
    lbl->setText(text);
    switch(clr)
    {
    case Red:
        lbl->setStyleSheet("border: 10px solid red; background-color: white; font-size: 32px;");
        colour = "Red";
        break;
    case Green:
        lbl->setStyleSheet("border: 10px solid green; background-color: white; font-size: 32px;");
        colour = "Green";
        break;
    case Yellow:
        lbl->setStyleSheet("border: 10px solid yellow; background-color: white; font-size: 32px;");
        colour = "Yellow";
        break;
    case Blue:
        lbl->setStyleSheet("border: 10px solid cyan; background-color: white; font-size: 32px;");
        colour = "Blue";
        break;
    case None:
        lbl->setStyleSheet("border: 10px solid gray; background-color: white; font-size: 32px;");
        colour = "";
        break;
    }
}

QString Card::cardName()
{
    return name;
}

QString Card::cardColour()
{
    return colour;
}

void Card::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        if ((name == "+4") && corners)
        {
            if ((e->x() < 16) && (e->y() < 16))
                setup("+4", Red);
            else if ((e->x() > 48) && (e->y() < 16))
                setup("+4", Green);
            else if ((e->x() < 16) && (e->y() > 80))
                setup("+4", Yellow);
            else if ((e->x() > 48) && (e->y() > 80))
                setup("+4", Blue);
            else if (colour != "")
                emit iWasClicked(this);
        }
        else
            emit iWasClicked(this);
    }
}

void Card::showFront()
{
    corners = false;
    lblB->hide();
    lblRed->hide();
    lblGreen->hide();
    lblYellow->hide();
    lblBlue->hide();
    show();
}

void Card::showBack()
{
    corners = false;
    lblB->show();
    lblRed->hide();
    lblGreen->hide();
    lblYellow->hide();
    lblBlue->hide();
    show();
}

void Card::showCorners()
{
    corners = true;
    lblRed->show();
    lblGreen->show();
    lblYellow->show();
    lblBlue->show();
}
