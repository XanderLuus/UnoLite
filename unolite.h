#ifndef UNOLITE_H
#define UNOLITE_H

#include <QMainWindow>
#include "card.h"
#include <QList>
#include <QLabel>
#include "dialog.h"

class UnoLite : public QMainWindow
{
    Q_OBJECT

public:
    UnoLite(QWidget *parent = nullptr);
    ~UnoLite();
    void initCards();
    void dealCards();
    void hideAll();
    void showDeck();
    void shuffleDeck();
    void showArrangeHands();
    void debug(QString);
    void plus2(Card*);
    void replaceDeck();
    char plus4(Card*);

    char cColor;


private:
    // Hands of cards.
    // deck is the pack of cards, facing down.
    // stack is the growing pack of upwards facing cards onto which you play.
    // computerHand and playerHand are the cards in the "hand" of the computer and the player, respectively.
    QList<Card*> deck;
    QList<Card*> stack;
    QList<Card*> computerHand;
    QList<Card*> playerHand;

    QLabel *debugLabel;
    QLabel *winLabel;
    QLabel *loseLabel;

    // Flick this to true so that you can see the computer player's hand and the next card.
    // Useful for debugging stuff.
    static const bool debugView = false;


private slots:
    void cardClick(Card*);
    void computerMove();

};
#endif // UNOLITE_H
