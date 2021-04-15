#pragma once
#include <iostream>
#include "Card.cpp"
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
    }

    public:
    Deck()
    {
        id = "Default";
        addCards();
    }

    Deck(const Vector<Card> &_cards, const String &_id)
    {
        cards = _cards;
        id = _id;
    }

    Card draw()
    {
        Card temp = cards[cards.getSize() - 1];                             
        for (usi i = cards.getSize() - 1; i > 0 ; i--)                      
        {                                                                   
           cards[i] = cards[i - 1];
        }
        cards[0] = temp;
        drawed++;
        return temp;
    }

    usi suit_count(Type type)
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

    usi rank_count(String value)
    {
        usi counter = 0;
        for(usi i = drawed; i < cards.getSize() - 1; i++)
        {
            if(cards[i].getValue() == value)
            {
                counter++;
            }
        }
        return counter;
    }
};

int main()
{
    Deck d;
    d.draw();
}