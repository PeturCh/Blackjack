#pragma once
#include <iostream>
#include "..\Services\string.cpp"

enum Type 
{
    spades = 1, hearts = 2, diamonds = 3, clubs = 4
};

class Card
{
    private:
    Type type;
    String value; 
    String id;

    public:

    Card() // Card c;
    {
        type = spades;
        value = "A";
        id="0";
    }

    Card(const Type _type, const String _value, const String _id)
    {
        type = _type;
        value = _value;
        id = _id;
    }

    Card& operator=(const Card& other)
    {
        if (this != &other)
        {
            type = other.type;
            value = other.value;
            id = other.id;
        }
        return *this;
    }

    Type getType()
    {
        return type;
    }

    String getValue()
    {
        return value;
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& c);
};

std::ostream& operator<<(std::ostream& out, const Card& c)
{
    out << c.type << ' ' << c.value << std::endl;
    return out;
}

