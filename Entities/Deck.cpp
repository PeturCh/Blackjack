#pragma once
#include <iostream>
#include "Card.cpp"
#include "Deck.h"
#include <stdlib.h>   
#include "..\Services\Vector.cpp"


void Deck::addCards()
{
    for (usi i = 1; i <= 4; i++)
    {
        Type type = Type(i);
        for (usi j = 2; j <= 14; j++)
        {
            cards.push_back(Card(type, j));
        }
    }

    for (size_t i = 0; i < 52; i++)
    {
        cards[i].setIdOfCard(true);
    }
    shuffle();
}

void Deck::swap(usi first, usi second)
{
    if (first > cards.getSize() || second > cards.getSize())
    {
        return;
    }
    Card temp = cards[first];
    cards[first] = cards[second];
    cards[second] = temp;
}

const bool Deck::contains(const Card &other) const 
{
    for (size_t i = 0; i < cards.getSize(); i++)
    {
        if (cards[i].getType() == other.getType() && cards[i].getValue() == other.getValue())
        {
            return true;
        }
    }
    return false;
}

void Deck::shuffle()
{
    srand(time(0));

    for (int i=0; i < cards.getSize() - 1; i++)
    {
        int randy = i + (rand() % (cards.getSize() - i - 1));
        swap(i, randy);
    }
}

Deck::Deck()
{
    id = new char[8];
    id = "Default";
    addCards();
}
    
Deck::Deck(usi count)
{
    id = new char[11];
    for (usi i = 0; i < count; i++)
    {
        usi value = 2 + rand() % (( 14 + 1 ) - 2);
        usi type = 1 + rand() % (( 4 + 1 ) - 1);
        strcpy(id, "Custom");
        Card c(type, value);
        if (count <= 52 && contains(c))
        {
            i--;
            continue;
        }

        else if(count > 52)
        {
            cards.push_back(c);
        }

        else cards.push_back(c);
    }
    for (size_t i = 0; i < count; i++)
    {
        cards[i].setIdOfCard(false);
    }
}

Deck::Deck(const Vector<Card> &_cards, char* _id)
{
    cards = _cards;
    id = _id;
}

Card Deck::draw()
{
    usi randy = drawed + rand() % ((cards.getSize()) - drawed);
    Card temp = cards[randy];                             
    for (usi i = randy; i > 0 ; i--)                      
    {                                                                   
       cards[i] = cards[i - 1];
    }
    cards[0] = temp;
    drawed++;
    return temp;
}

usi Deck::suit_count(Type type) const
{
    usi counter = 0;
    for (usi i = drawed; i < cards.getSize() - 1; i++)
    {
        if(cards[i].getType() == type)
        {
            counter++;
        }
    }
    return counter;
}

usi Deck::rank_count(int value) const
{
    usi counter = 0;
    for(usi i = drawed; i < cards.getSize() - 1; i++)
    {
        if(cards[i].getUsiValue() == value || cards[i].getUsiValue() - 10 == value)
        {
            counter++;
        }
    }
    return counter;
}

usi Deck::getDeckSize() const
{
    return cards.getSize();
}

usi Deck::getDrawed() const
{
    return drawed;
}

Deck::~Deck()
{
    delete [] id;
}


//int main()
//{
//    Deck d;
//    for (size_t i = 0; i < 40; i++)
//    {
//        std::cout<<d.draw().getId();
//    }
//}