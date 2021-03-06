#pragma once
#include <iostream>
#include <cstring>
#include "Card.h"
#include "..\Services\string.cpp"


void Card::setIdOfCard(bool def)
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

Card::Card()
{
    type = spades;
    value = "A";
    id = new char[10];
}

Card::Card(const usi _type, const usi _value)
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

Card::Card(const Type _type, const String _value)
{
    type = _type;
    value = _value;
}

usi Card::getType() const 
{
    return type;
}

String Card::getValue() const 
{
    return value;
}

usi Card::getUsiValue() const 
{
    if (value.getLength() != 1) // the value is 10
    {
        return 10;
    }
    else 
    {
        switch (value[0])
        {
        case '2': return 2; break;
        case '3': return 3; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 7; break;
        case '8': return 8; break;
        case '9': return 9; break;
        case 'J': return 10; break;
        case 'Q': return 10; break;
        case 'K': return 10; break;
        case 'A': return 11; break;    
        
        default: break;
        }
    }
}

char* Card::getId() const 
{
    return id;
}

Card& Card::operator=(const Card& other)
{
    if (this != &other)
    {
        type = other.type;
        value = other.value;
        id = other.id;
    }
    return *this;
}


/*~Card()
{
    delete [] id;
}*/


std::ostream& operator<<(std::ostream& out, const Card& c)
{
    out << c.type << ' ' << c.value << std::endl;
    return out;
}
