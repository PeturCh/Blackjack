#pragma once
#include <iostream>
#include "Player.h"
#include "..\Services\string.cpp"


const bool Player::ValidateName(const String &_name) const 
{
    
    if (_name[0] < 'A' || _name[0] > 'Z')
    {
        std::cout << "You have enterned invalid name. The first name must start with upper case letter!";
        return false;
    }

    for (usi i = 0; i < _name.getLength(); i++)   
    {
        if (_name[i] >= 'A' || _name[i] <= 'Z' || _name[i] >= 'a' || _name[i] <= 'z' || _name[i] == ' ')
        {
            if (_name[i] == ' ' && _name[i + 1] == ' ')
            {
                std::cout << "You have enterned invalid name. The name must have only one space!";
                return false;
            }
            if (_name[i] == ' ' && (_name[i + 1] < 'A' || _name[i + 1] > 'Z'))
            {
                std::cout << "You have enterned invalid name. The second name must start with upper case letter!";
                return false;
            }
        }
        else
        {
            std::cout << "You have enterned invalid name. The name must contains only latin letters!";  //правилно ли е??
            return false;
        }
    }
    return true;
}

bool Player::ValidateYears(usi _years)
{
    if (_years < 18 && _years > 90)
    {
        std::cout << "You have enterned invalid age. Age must be between 18 and 90!";
        return false;;
    }
    return true;
}

Player::Player()
{
    wins = 0;
    winningCoef = 0;
    currentPoints = 0;
}

Player::Player(const String _name, const usi _years, usi _wins, float _winningCoef)
{
    if (ValidateName(_name))
        name = _name;

    if (ValidateYears(_years))
        years = _years;

    wins = _wins;
    winningCoef = _winningCoef;
    currentPoints = 0;
}

String Player::getName() const
{
    return name;
}

usi Player::getWonGames() const
{
    return wins;
}

usi Player::getWinningCoef() const
{
    return winningCoef;
}

usi Player::getPoints() const
{
    return currentPoints;
}

void Player::addPoints(usi _points)
{
    if (_points == 11 && currentPoints + _points > 21)
    {
        currentPoints += 1;
    }
    else
    currentPoints += _points;
}

Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        name = other.name;
        years = other.years;
        wins = other.wins;
        winningCoef = other.winningCoef;
        currentPoints = other.currentPoints;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Player& c)
{
    out << c.name << ' ' << c.years << ' ' << c.wins << ' ' << c.winningCoef << ' ' << c.currentPoints << std::endl;
    return out;
}
