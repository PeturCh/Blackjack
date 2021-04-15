#pragma once
#include <iostream>
#include "Card.cpp"
#include <stdlib.h>   
#include "..\Services\Vector.cpp"

using usi = unsigned short int;

class Deck 
{
    Vector<Card> cards;
    String id;
    usi drawed = 0;

    void addCards()
    {
        for (usi i = 1; i <= 4; i++)
        {
            Type type = Type(i);
            cards.push_back(Card(type, String("2"), id));
            cards.push_back(Card(type, String("3"), id));
            cards.push_back(Card(type, String("4"), id));
            cards.push_back(Card(type, String("5"), id));
            cards.push_back(Card(type, String("6"), id));
            cards.push_back(Card(type, String("7"), id));
            cards.push_back(Card(type, String("8"), id));
            cards.push_back(Card(type, String("9"), id));
            cards.push_back(Card(type, String("10"), id));
            cards.push_back(Card(type, String("A"), id));
            cards.push_back(Card(type, String("K"), id));
            cards.push_back(Card(type, String("Q"), id));
            cards.push_back(Card(type, String("J"), id));
        }
        shuffle();
    }

    void swap(usi first, usi second)
    {
        Card temp = cards[first];
        cards[first] = cards[second];
        cards[second] = temp;
    }

    const bool contains(const Card &other) const 
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

    void shuffle()
    {
        srand(time(0));
    
        for (int i=0; i < cards.getSize() - 1; i++)
        {
            int randy = i + (rand() % (cards.getSize() - i - 1));
            swap(i, randy);
        }
    }

    public:
    Deck()
    {
        id = "Default";
        addCards();
    }

    Deck(usi count, String _id = "Custom")
    {
        id = _id;
        for (size_t i = 0; i < count; i++)
        {
            usi value = 2 + rand() % (( 14 + 1 ) - 2);
            usi type = 1 + rand() % (( 4 + 1 ) - 1);
            Card c(type, value);
            if (count <= 52 && contains(c))
            {
                continue;
            }
            else cards.push_back(c);
        }
        cards.print();
    }

    Deck(const Vector<Card> &_cards, const String &_id)
    {
        cards = _cards;
        id = _id;
    }

    Card draw()
    {
        usi randy = rand() % (cards.getSize() - 1) + drawed;
        Card temp = cards[randy];                             
        for (usi i = randy; i > 0 ; i--)                      
        {                                                                   
           cards[i] = cards[i - 1];
        }
        cards[0] = temp;
        return temp;
    }
};

int main()
{   
    Deck d(20);
}