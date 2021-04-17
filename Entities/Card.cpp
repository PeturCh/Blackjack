#pragma once
#include <iostream>
#include <cstring>
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
    char* id;

    public:
    void setIdOfCard(bool def)
    {
        id = new char[10];
        for(int i=0 ; i < 10 ; i++)
        {
            id[i] = ' ';
        }

        if(def)
        {
            strcpy(id , "Default");
            int i = 7;
            id[i++] = '0' + type;
            if (value == "10")
            {
                id[i++] = '1';
                id[i] = '0';
            }
            else id[i] = value[0];
        }
        else
        {
            strcpy(id, "Custom");
            int i = 6;
            id[i++] = '0' + type;
            if (value == "10")
            {
                id[i++] = '1';
                id[i] = '0';
            }
            else id[i] = value[0];
        }
    }

    Card()
    {
        type = spades;
        value = "A";
        id = new char[10];
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
            value.push_back('0' + _value);
        }
    }

    Card(const Type _type, const String _value)
    {
        type = _type;
        value = _value;
    }

    usi getType() const 
    {
        return type;
    }

    String getValue() const 
    {
        return value;
    }

    char* getId() const 
    {
        return id;
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

    /*~Card()
    {
        delete [] id;
    }*/
};

std::ostream& operator<<(std::ostream& out, const Card& c)
{
    out << c.type << ' ' << c.value << std::endl;
    return out;
}
