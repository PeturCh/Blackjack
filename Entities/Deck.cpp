#pragma once
#include <iostream>
#include "Card.cpp"
#include "Vector.cpp"

using usi = unsigned short int;

class Deck 
{
    Vector<Card> cards;
    String id;

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
};

int main()
{
    
}