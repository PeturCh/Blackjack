#pragma once
#include <iostream>
#include <fstream>
#include "..\Entities\Deck.cpp"

using usi = unsigned short int;

void deserialize(const char * fileName) 
{
    std::ifstream input ("players.txt");
    char row[50];

    while(!input.eof())
    {
        input.getline(row , 50 , '\n');
    }
}


int main()
{
    
}
