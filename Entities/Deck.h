#pragma once
#include <iostream>
#include "Card.cpp"
#include <stdlib.h>   
#include "..\Services\Vector.cpp"

using usi = unsigned short int;

class Deck 
{
    private:
    Vector<Card> cards;
    char *id;
    usi drawed = 0;

    void addCards();
    void swap(usi first, usi second);
    const bool contains(const Card &other) const;
    void shuffle();

    public:
    Deck();
    Deck(usi);
    Deck(const Vector<Card> &, char*);
    Card draw();
    usi getDeckSize() const;
    usi getDrawed() const;
    usi suit_count(Type) const;
    usi rank_count(int) const;
    ~Deck();
};