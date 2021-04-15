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

    Card()
    {
        type = spades;
        value = "A";
        id="0";
    }

    Card(const usi _type, const usi _value)
    {
        type = Type(_type);
        if (_value >= 10)
        {
            switch (_value)
            {
            case 10:
                value = "10";
                break;
            case 11:
                value = "J";
                break;
            case 12:
                value = "Q";
                break;
            case 13:
                value = "K";
                break;
            case 14:
                value = "A";
                break;
            default:
                break;
            }
        }
        else 
        {
            char v[2] = {('0' + _value)}; 
            value = v; 
        }
    }   

    Card(const Type _type, const String _value, const String _id)
    {
        type = _type;
        value = _value;
        id = _id;
    }

    usi getType() const 
    {
        return type;
    }

    String getValue() const 
    {
        return value;
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

    friend std::ostream& operator<<(std::ostream& out, const Card& c);
};

std::ostream& operator<<(std::ostream& out, const Card& c)
{
    out << c.type << ' ' << c.value << std::endl;
    return out;
}
