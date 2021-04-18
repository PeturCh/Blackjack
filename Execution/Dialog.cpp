#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "..\Entities\Deck.cpp"
#include "..\Entities\Player.cpp"

using usi = unsigned short int;


usi getSizeOfDeck()
{
    short int sizeOfDeck;
    do
    {
        std::cin>>sizeOfDeck;
        if (sizeOfDeck < 4)
        {
            std::cout<<"You can not play with less than 4 cards! Try again: \n";
        }
    } while (sizeOfDeck < 4);
    std::cout<<"Start!\n";
    return sizeOfDeck;
}

void addToFile(Player &pl)
{
    std::ofstream output("..\\PlayersData\\Data.txt" , std::fstream::app);
    output <<'\n'<< pl.getName() << " " << pl.getWonGames() << " " << std::fixed << std::setprecision(2) << pl.getWinningCoef();
    output.close();
}

void play(Deck &deck, Player &player)
{
    Card card = deck.draw();

    std::cout<<card.getValue() << ' ';

    switch (card.getType())
    {
    case 1: std::cout<<"Spades "; break;
    case 2: std::cout<<"Hearts "; break;
    case 3: std::cout<<"Diamonds "; break;
    case 4: std::cout<<"Clubs "; break;
    
    default: break;
    }

    if (card.getValue().getLength() != 1) // the value is 10
    {
        player.addPoints(10);
        std::cout<<"(Points: 10)\n";
    }
    else 
    {
        usi points = 0;

        switch (card.getValue()[0])
        {
        case '2': player.addPoints(2);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '3': player.addPoints(3);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '4': player.addPoints(4);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '5': player.addPoints(5);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '6': player.addPoints(6);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '7': player.addPoints(7);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '8': player.addPoints(10);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case '9': player.addPoints(10);
        std::cout<<"(Points: "<< card.getValue()[0] <<")\n"; break;
        case 'J': player.addPoints(10);
        std::cout<<"(Points: "<< 10 <<")\n"; break;
        case 'Q': player.addPoints(10);
        std::cout<<"(Points: "<< 10 <<")\n"; break;
        case 'K': player.addPoints(10);
        std::cout<<"(Points: "<< 10 <<")\n"; break;
        case 'A': player.addPoints(10);
        std::cout<<"(Points: "<< 10 <<")\n"; break;    
        
        default: break;
        }
    }
    
    std::cout<<"Hit/Stand/Probability. Hint: You can use just the first letter: H/S/P. \n";
    std::cin.ignore();
    char command2[20];
    std::cin.getline(command2, 20);

    switch (command2[0])
    {
        case 'S': 
        break;
        case 'H': 
        break;
        case 'P': 
        break;
        default: "You have enterned invlid command! Default command executed: Stand.";
        break;
    }
}

void deserialize(const char *fileName, Vector<Player> &players) 
{
    std::ifstream input(fileName);
    char row[50];

    while(!input.eof())
    {
        input.getline(row , 70 , '\n');
    
        usi index = 0;

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
        for (; row[index] != '\0'; index++)
        {
            if (row[index] == ' ')
            {
                ++index;
                break;
            }
            if (row[index] == '.' || row[index] == ',')
	        {
	    	    index++;
	    	    winningCoef += float(row[index] - '0') / 10;
                if(row[index+1]!='\0')
	    	        winningCoef += float(row[++index] - '0') / 100;
	    	    continue;
	        }
            winningCoef *= 10;
            winningCoef += row[index] - '0';
        }

        std::cout<<winningCoef<<'\n';
        Player p(name,18,playedGamesFF,winningCoef);
        players.push_back(p);
    }
}

int main()
{
    Vector<Player> players;
    deserialize("..\\PlayersData\\Data.txt", players);
    //Player p("Peshko Be",18,5,0.8);
    //Player c("Mims Be",18,6,0.8);
    //Player d("Mitko Be",18,12,0.5);
    //players.push_back(p);
    //players.push_back(c);
    //players.push_back(d);

    std::cout<<"\nChoose a player or enter a new player:\n";

    char command[50];
    std::cin.getline(command, 50);

    String commandFC(command);
    short int playerIndex = -1;
    for (usi i = 0; i < players.getSize(); i++)
    {
        if (players[i].getName() == commandFC)
        {
            playerIndex = i;
            break;
        }
    }
    
    if(playerIndex <= - 1)
    {
        String newPlayerName;
        usi newPlayerAge = 0;
        usi spaces = 0;
        for (size_t i = 0; i < commandFC.getLength(); i++)
        {
            if(commandFC[i] == ' ') spaces++;

            if(commandFC[i] == ' ' && spaces == 2) 
            {
                newPlayerAge = (commandFC[++i] - '0') * 10;
                if (commandFC[i] < '0' || commandFC[i]>'9')
                {
                    break;
                }
                newPlayerAge += commandFC[i] - '0';
                break;
            }
            newPlayerName.push_back(commandFC[i]);
        }

        if (newPlayerAge<18)
        {
            std::cout<<"Sorry, this name isn't in the list or you have enterned invalid age for new player.\nPlayers must be atleast 18 years old!";
            main();
        }
        
        Player newPlayer(newPlayerName,newPlayerAge,0,0);
        addToFile(newPlayer);
        std::cout<<"\nYou will play as "<< newPlayerName << ". Choose the size of the deck: \n";
        usi deckSize = getSizeOfDeck();
        if (deckSize == 52)
        {
            Deck deck;
            play(deck, newPlayer);
        }
        else 
        {
            Deck deck(deckSize);
            play(deck, newPlayer);
        }
    }
    else
    {
        std::cout<<"\nYou will play as "<<players[playerIndex].getName()<<". Choose the size of the deck: \n";
        usi deckSize = getSizeOfDeck();
        if (deckSize == 52)
        {
            Deck deck;
            play(deck, players[playerIndex]);
        }
        else 
        {
            Deck deck(deckSize);
            play(deck, players[playerIndex]);
        }
    }
}
