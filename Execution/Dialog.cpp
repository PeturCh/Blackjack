#pragma once
#include <iostream>
#include <fstream>
#include "..\Entities\Deck.cpp"
#include "..\Entities\Player.cpp"

using usi = unsigned short int;

void deserialize() 
{
    std::ifstream input ("..\\PlayersData\\Data.txt");
    char row[50];

    if(!input.eof())
    {
        input.getline(row , 50 , '\n');
    }
    
    usi index = 0;

    usi rowSize = 0;
    for (size_t i = 0; row[i] != '\0'; i++)
    {
        rowSize++;
    }
    
    String name;
    usi spaces = 0;
    for (; row[index] != '\0'; index++)
    {

        if(row[index] == ' ') spaces++;

        if(row[index] == ' ' && spaces == 2) 
        {
            index++;
            spaces = 0;
            break;
        }
        name.push_back(row[index]);
    }
    std::cout<<name<<' ';

    if(!input.eof())
    {
        input.getline(row, 5 , '\n');
    }

    usi playedGamesFF = 0;
    for (; row[index] != '\0'; index++)
    {
        if (row[index] == ' ')
        {
            ++index;
            break;
        }
        playedGamesFF *= 10;
        playedGamesFF += row[index] - '0';
    }
    std::cout<<playedGamesFF<<' ';

    float winningCoef = 0;
    for (; row[index] != '0'; index++)
    {
        if (row[index] == ' ')
        {
            ++index;
            break;
        }
        if (row[index] == '.' || row[index] == ',')
	    {
		    index++;
		    winningCoef += float(row[index++] - '0') / 10;
            if(row[index]!='\0')
		    winningCoef += float(row[index] - '0') / 100;
		    continue;
	    }
        winningCoef *= 10;
        winningCoef += row[index] - '0';
    }
    std::cout<<winningCoef;
}

int main()
{
    deserialize();
}
