#pragma once
#include <iostream>
#include "..\Services\string.cpp"

using usi = unsigned short int;

enum Type 
{
    spades = 1, hearts = 2, diamonds = 3, clubs = 4
};

class Card
{
    private:
    Type type;
    String value; 
    char* id;

    public:
    void setIdOfCard(bool);

    Card();
    Card(const usi, const usi);
    Card(const Type, const String);
    usi getType() const;
    String getValue() const;
    char* getId() const;
    Card& operator=(const Card&);

    friend std::ostream& operator<<(std::ostream& out, const Card& c);

};