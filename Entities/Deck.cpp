#pragma once
#include <iostream>
#include "Card.cpp"
#include <stdlib.h>   
#include "..\Services\Vector.cpp"

using usi = unsigned short int;

class Deck 
{
    Vector<Card> cards;
    char *id;
    usi drawed = 0;

    void addCards()
    {
        for (usi i = 1; i <= 4; i++)
        {
            Type type = Type(i);
            cards.push_back(Card(type, String("2")));
            cards.push_back(Card(type, String("3")));
            cards.push_back(Card(type, String("4")));
            cards.push_back(Card(type, String("5")));
            cards.push_back(Card(type, String("6")));
            cards.push_back(Card(type, String("7")));
            cards.push_back(Card(type, String("8")));
            cards.push_back(Card(type, String("9")));
            cards.push_back(Card(type, String("10")));
            cards.push_back(Card(type, String("A")));
            cards.push_back(Card(type, String("K")));
            cards.push_back(Card(type, String("Q")));
            cards.push_back(Card(type, String("J")));
        }

        for (size_t i = 0; i < 52; i++)
        {
            cards[i].setIdOfCard(true);
        }
        shuffle();
    }

    void swap(usi first, usi second)
    {
        if (first > cards.getSize() || second > cards.getSize())
        {
            return;
        }
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
        id = new char[8];
        id = "Default";
        addCards();
    }
    
    Deck(usi count)
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
            else cards.push_back(c);
        }
        for (size_t i = 0; i < count; i++)
        {
            cards[i].setIdOfCard(false);
        }
        
        cards.print();
    }

    Deck(const Vector<Card> &_cards, char* _id)
    {
        cards = _cards;
        id = _id;
    }

    Card draw()
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

    ~Deck()
    {
        delete [] id;
    }
};


int main()
{
    Deck d(10);
    for (size_t i = 0; i < 10; i++)
    {
        std::cout<<d.draw().getId();
    }
}