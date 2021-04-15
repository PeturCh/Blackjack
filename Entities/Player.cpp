#pragma once
#include <iostream>
#include "..\Services\string.cpp"

using usi = unsigned short int;

class Player //Maria uploaded this
{
    private:
    String name;
    usi years;
    usi wins;
    float winningCoef;
    usi currentPoints;
   
    const bool ValidateName(const String &_name) const 
    {
        for (usi i = 0; i < _name.getLength(); i++)   
        {
            if (name[i] >= 'A' || name[i] <= 'Z' || name[i] >= 'a' || name[i] <= 'z' || name[i] == ' ')
            {
                if (name[0] < 'A' || name[0] > 'Z')
                {
                    std::cout << "You have enterned invalid name. The first name must start with upper case letter!";
                    return false;
                }
                if (name[i] == ' ' && name[i + 1] == ' ')
                {
                    std::cout << "You have enterned invalid name. The name must have only one space!";
                    return false;
                }
                if (name[i] == ' ' && (name[i + 1] < 'A' || name[i + 1] > 'Z'))
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
            return true;
        }
    }

    bool ValidateYears(usi _years)
    {
        if (_years < 18 && _years > 90)
        {
            std::cout << "You have enterned invalid age. Age must be between 18 and 90!";
            return false;;
        }
        return true;
    }

    public:

    Player()
    {
        wins = 0;
        winningCoef = 0;
        currentPoints = 0;
    }

    Player(const String _name, const usi _years, usi _wins, float _winningCoef, usi _currentPoints)
    {
        if (ValidateName(_name))
            name = _name;

        if (ValidateYears(_years))
            years = _years;

        wins = _wins;
        winningCoef = _winningCoef;
        currentPoints = _currentPoints;
    }

    Player& operator=(const Player& other)
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

    friend std::ostream& operator<<(std::ostream& out, const Player& c);

};

std::ostream& operator<<(std::ostream& out, const Player& c)
{
    out << c.name << ' ' << c.years << ' ' << c.wins << ' ' << c.winningCoef << ' ' << c.currentPoints << std::endl;
    return out;
}


