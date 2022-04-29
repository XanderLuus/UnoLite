#include "unolite.h"
#include <QRandomGenerator>
#include <QTimer>
#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include<windows.h>
#include <string>
#include "dialog.h"

bool bPlus2PickedUp = true;
int iPickupNum = 0;

UnoLite::UnoLite(QWidget *parent)
    : QMainWindow(parent)
{
    debugLabel = new QLabel(this);
    debugLabel->setGeometry(10, 550, 400, 200);
    debugLabel->setAlignment(Qt::AlignTop);
    debugLabel->show();

    winLabel = new QLabel(this);
    winLabel->setGeometry(0, 0, width(), height());
    winLabel->setStyleSheet("font-size: 64px");
    winLabel->setAlignment(Qt::AlignCenter);
    winLabel->setText("Player Wins");
    winLabel->hide();

    loseLabel = new QLabel(this);
    loseLabel->setGeometry(0, 0, width(), height());
    loseLabel->setStyleSheet("font-size: 64px");
    loseLabel->setAlignment(Qt::AlignCenter);
    loseLabel->setText("Computer Wins");
    loseLabel->hide();

    // This function creates the cards. Leave it alone.
    // You may only comment out the last bit of it where it creates the +4's if you need to.
    initCards();

    // Complete this function to shuffle the cards.
    // Question 1, 5 marks
    shuffleDeck();

    // Complete this function to prepare the player and computer's hands and initialize the card stack.
    // Question 2, 5 marks
    dealCards();

    // This function just prints the deck of cards as it is. Use it to demonstrate how you shuffled it.
    // Then comment it out as it is otherwise useless.
    //showDeck();

    // This function places the cards in the game's layout.
    // Call it every time the player or the computer moved, to update the display.
    //showArrangeHands();
}

UnoLite::~UnoLite()
{
}

void UnoLite::initCards()
{
    Card *c;
    for (int i = 0; i < 10; ++i)
    {
        c = new Card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i), Red);
    }
    c = new Card(this);
    deck.append(c);
    c->hide();
    c->setup("+2", Red);
    for (int i = 0; i < 10; ++i)
    {
        c = new Card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i), Green);
    }
    c = new Card(this);
    deck.append(c);
    c->hide();
    c->setup("+2", Green);
    for (int i = 0; i < 10; ++i)
    {
        c = new Card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i), Yellow);
    }
    c = new Card(this);
    deck.append(c);
    c->hide();
    c->setup("+2", Yellow);
    for (int i = 0; i < 10; ++i)
    {
        c = new Card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i), Blue);
    }
    c = new Card(this);
    deck.append(c);
    c->hide();
    c->setup("+2", Blue);

    // Handle the +4's correctly in the game, otherwise comment them out.
    // Question 5, 5 marks.
    // +4's
    c = new Card(this);
    deck.append(c);
    c->hide();
    c->setup("+4", None);
    c = new Card(this);
    deck.append(c);
    c->hide();
    c->setup("+4", None);
}

// Implement this function.
// Question 2, 5 marks.
void UnoLite::dealCards()
{
    Card *c;

    QListIterator<Card*> deckIterator(deck);

    for (int k = 1; k <= 14; k++)
    {
        c = deckIterator.next();
        if (k <= 7)
        {
            playerHand.append(c);
            deck.removeOne(c);
        } else
        {
            computerHand.append(c);
            deck.removeOne(c);
        }
    }
    c = deckIterator.next();
    stack.append(c);
    deck.removeOne(c);

    showArrangeHands();
}

void UnoLite::hideAll()
{
    QListIterator<Card*> deckIterator(deck);
    while (deckIterator.hasNext())
    {
        Card *c = deckIterator.next();
        c->hide();
    }
    QListIterator<Card*> stackIterator(stack);
    while (stackIterator.hasNext())
    {
        Card *c = stackIterator.next();
        c->hide();
    }
    QListIterator<Card*> computerHandIterator(computerHand);
    while (computerHandIterator.hasNext())
    {
        Card *c = computerHandIterator.next();
        c->hide();
    }
    QListIterator<Card*> playerHandIterator(playerHand);
    while (playerHandIterator.hasNext())
    {
        Card *c = playerHandIterator.next();
        c->hide();
    }
}

void UnoLite::showDeck()
{
    int x = 0;
    int y = 0;
    QListIterator<Card*> deckIterator(deck);
    while (deckIterator.hasNext())
    {
        Card *c = deckIterator.next();
        c->move(70*x, 102*y);
        c->show();
        ++x;
        if (x == 11)
        {
            ++y;
            x = 0;
        }
    }
}


// Implement this function.
// Question 1, 5 marks.
void UnoLite::shuffleDeck()
{
//    int highestNumber = 47;
//    int lowestNumber = 1;
//    int iCardValue = 0;
//    int iDeckValues[46];
//    bool valueSet = false;

//    for (int k = 0; k <= 45; k++)
//    {
//        valueSet = false;
//        while (valueSet == false)
//        {
//            iCardValue = rand() % ((highestNumber - lowestNumber)) + lowestNumber;
//            if (k == 0)
//            {
//                iDeckValues[k] = iCardValue;
//                valueSet = true;
//            } else
//            {
//                valueSet = true;
//                for (int iC = 0; iC < k; iC++)
//                {
//                    if (iCardValue == iDeckValues[iC]) valueSet = false;
//                }
//                if (valueSet == true)
//                {
//                    iDeckValues[k] = iCardValue;
//                }
//            }
//        }
//    }
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(deck.begin(), deck.end());
//    Card *c;
//    QListIterator<Card*> deckIt(deck);

//    int k = 0;
//    while (deckIt.hasNext())
//    {
//        c = deckIt.next();
//        c->cardPosition = iDeckValues[k];
//        k++;
//    }

//    std::sort(deck.begin(), deck.end(), [](Card* c1, Card* c2) {
//        return (c1->cardPosition < c2->cardPosition);
//    });
}

// Call this to update the game view after every move.
// Otherwise leave it alone.
void UnoLite::showArrangeHands()
{
    hideAll();
    Card *c;
    int i = 0;

    QListIterator<Card*> computerHandIterator(computerHand);
    while (computerHandIterator.hasNext())
    {
        c = computerHandIterator.next();
        c->move(i*70+10, 10);
        ++i;
        if (debugView)
            c->showFront();
        else
            c->showBack();
    }

    i = 0;
    QListIterator<Card*> playerHandIterator(playerHand);
    while (playerHandIterator.hasNext())
    {
        c = playerHandIterator.next();
        c->move(i*70+10, 400);
        ++i;
        c->showFront();
        if (c->cardName() == "+4")
            c->showCorners();
    }

    if (stack.length() > 0)
    {
        c = stack.first();
        c->move(100, 200);
        c->showFront();
    }

    if (deck.length() > 0)
    {
        c = deck.first();
        c->move(300, 200);
        if (debugView)
            c->showFront();
        else
            c->showBack();
    }
}

// This function gets called when any card is clicked on.
// Implement this function to handle the player side of the game.
// Question 3, 10 marks.
void UnoLite::cardClick(Card *c)
{
    //plus4(c);
    bool bPlayed = false;
    char cDeck = 'n'; //n = none, p = player, d = deck

    if (deck.size() <= 1)
    {
        replaceDeck();
    }

    Card* cc;
    QListIterator<Card*> playerHandIterator(playerHand);
    QListIterator<Card*> deckIterator(deck);

    while (playerHandIterator.hasNext())
    {
        cc = playerHandIterator.next();
        if (cc == c)
        {
            cDeck = 'p';
        }
    }
    if (cDeck == 'n')
    {
        while (deckIterator.hasNext())
        {
            cc = deckIterator.next();
            if (cc == c)
            {
                cDeck = 'd';
            }
        }
    }

    if (bPlus2PickedUp == true)
    {
        if (cDeck == 'p')
        {
            if (stack.isEmpty())
            {
                stack.prepend(c);
                playerHand.removeOne(c);
                bPlayed = true;
                plus2(c);
            }
            else if (c->cardName() == "+4")
            {

            }
            else if (c->cardColour() == stack.constFirst()->cardColour())
                {
                    stack.prepend(c);
                    playerHand.removeOne(c);
                    bPlayed = true;
                    plus2(c);
                }
            else if (c->cardName() == stack.constFirst()->cardName())
            {
                stack.prepend(c);
                playerHand.removeOne(c);
                bPlayed = true;
                plus2(c);
            }
        } else if (cDeck == 'd')
        {
            cc = deck.constLast();
            playerHand.append(cc);
            deck.removeOne(cc);
            bPlayed = true;
        }
    }
    else  //Player has to play +2 or pickup
    {
        if (c->cardName() == "+2")
        {
            stack.prepend(c);
            playerHand.removeOne(c);
            bPlayed = true;

            bPlus2PickedUp = false;
            iPickupNum += 2;
        } else if (cDeck == 'd')
        {
            QListIterator<Card*> deckIterator2(deck);
            for (int i = 0; i < iPickupNum; i++)
            {
                cc = deckIterator2.next();
                playerHand.append(cc);
                deck.removeOne(cc);
            }
            bPlus2PickedUp = true;
            iPickupNum = 0;
        }
    }

    showArrangeHands();

    if (bPlayed == true)
    {
        computerMove();
    }

}

void UnoLite::plus2(Card *c)
{
    if (c->cardName() == "+2")
    {
        bPlus2PickedUp = false;
        iPickupNum += 2;
    }
}

char UnoLite::plus4(Card *)
{
    Dialog secDialog;
    secDialog.setModal(true);
    secDialog.exec();

    return cColor;
}

// Call this function yourself when the computer must make its move.
// Implement this function to handle the "AI" / rule based player's side of the game.
// Question 4, 10 marks.
void UnoLite::computerMove()
{
    if (deck.size() <= 1)
    {
        replaceDeck();
    }

    Card *c, *cc;
    QListIterator<Card*> computerHandIterator(computerHand);
    bool bPlayed = false;


    if (bPlus2PickedUp == true)
    {
        while (computerHandIterator.hasNext() && bPlayed == false)
        {
            c = computerHandIterator.next();

            if (c->cardColour() == stack.constFirst()->cardColour())
                {
                    stack.prepend(c);
                    computerHand.removeOne(c);
                    bPlayed = true;
                    plus2(c);
                }
            else if (c->cardName() == stack.constFirst()->cardName())
            {
                stack.prepend(c);
                computerHand.removeOne(c);
                bPlayed = true;
                plus2(c);
            }
        }
        if (bPlayed == false)
        {
            c = deck.constLast();
            computerHand.append(c);
            deck.removeOne(c);
        }
    }
    else //If a plus to was thrown by the player
    {
        while (computerHandIterator.hasNext() && bPlayed == false)
        {
            c = computerHandIterator.next();

            if (c->cardName() == "+2")
            {
                stack.prepend(c);
                computerHand.removeOne(c);
                bPlayed = true;

                bPlus2PickedUp = false;
                iPickupNum += 2;
            }
        }
        if (bPlayed == false)
        {
            QListIterator<Card*> deckIterator2(deck);
            for (int i = 0; i < iPickupNum; i++)
            {
                cc = deckIterator2.next();
                computerHand.append(cc);
                deck.removeOne(cc);
            }
            bPlus2PickedUp = true;
            iPickupNum = 0;
        }
    }


    showArrangeHands();
}

void UnoLite::replaceDeck()
{
    Card *c;
    QListIterator<Card*> stackIterator(stack);

    c = stackIterator.next();

    while (stackIterator.hasNext())
    {
        c = stackIterator.next();
        deck.append(c);
        stack.removeOne(c);
    }
    shuffleDeck();
    showArrangeHands();
}

// You are welcome to call this function with useful text to help you debug the program.
// Hint: use it to output which rule gets triggered during computer play and player play,
// so that you can see in the output what is going on in your code and why things happen
// like they do.
void UnoLite::debug(QString s)
{
    debugLabel->setText(s + "\n" + debugLabel->text());
}
