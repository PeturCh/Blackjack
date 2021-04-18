#pragma once
#include <iostream>
#include "..\Services\string.cpp"

using usi = unsigned short int;

class Player 
{
    private:
    String name;
    usi years;
    usi wins;
    float winningCoef;
    usi currentPoints;

    const bool ValidateName(const String&) const;
    bool ValidateYears(usi);

    public:
    Player();
    Player(const String, const usi, usi, float);
    String getName() const;
    usi getWonGames() const;
    usi getWinningCoef() const;
    usi getPoints() const;
    void addPoints(usi);
    Player& operator=(const Player&);

    friend std::ostream& operator<<(std::ostream& out, const Player& c);
};