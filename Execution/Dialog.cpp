#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "..\Entities\Deck.cpp"
#include "..\Entities\Player.cpp"

using usi = unsigned short int;

void probabilityCheck(Player &player, Deck &deck)
{
    float found = 0;
    usi wanted = 21 - player.getPoints();
    found = deck.rank_count(wanted);
    std::cout<< "The probability of reaching 21 points is "<< std::fixed << std::setprecision(2) << found / (deck.getDeckSize() - deck.getDrawed())<< '\n';
}

bool drawCard(Player &player, Deck &deck)
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
        std::cout<<"(Points: "<<player.getPoints()<<")\n";
    }
    else 
    {
        switch (card.getValue()[0])
        {
        case '2': player.addPoints(2);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '3': player.addPoints(3);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '4': player.addPoints(4);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '5': player.addPoints(5);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '6': player.addPoints(6);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '7': player.addPoints(7);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '8': player.addPoints(8);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case '9': player.addPoints(9);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case 'J': player.addPoints(10);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case 'Q': player.addPoints(10);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case 'K': player.addPoints(10);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;
        case 'A': player.addPoints(11);
        std::cout<<"(Points: "<< player.getPoints() <<")\n"; break;    
        
        default: break;
        }
    }

    if (player.getPoints() > 21)
    {
        if(player.getName() == "Casino Dealer")
        {
            std::cout<<"Congratulations! \nYou win!\nThe casino dealer drew "<< player.getPoints() << '\n';
            return false;
        }
        std::cout<< "You drew "<< player.getPoints() <<" therefore you lose!";
        return false;
    }
    else return true;
}

void stand(Player &player, Deck &deck)
{
    Player dealer("Casino Dealer", 50, 50, 0.3);
    std::cout<<"The dealer is now drawing: \n";
    drawCard(dealer, deck);
    while (dealer.getPoints() <= 17)
    {
        if(!drawCard(dealer,deck))
            return;
    }

    if(dealer.getPoints() > player.getPoints())
    {
        std::cout<<"Poor you! You Lose!\n";
    }
    else 
    {
        std::cout<<"Congratulations! \nYou win!\n The casino dealer drew just "<< dealer.getPoints()<< " points";
    }
    
}

char makeChoice(Player &player, Deck &deck)
{
    std::cout<<"Hit/Stand/Probability. Hint: You can use just the first letter: H/S/P. \n";
    char command2[20];
    std::cin.ignore();
    std::cin.getline(command2, 20);

    if (command2[0] == '\0') // The cin.ignore() works whenever it wants to
    {
        std::cout<<"Could you please repeat the command?\n";
        std::cin.getline(command2, 20);
    }

    switch (command2[0])
    {
        case 'S': return 'S';
        break;
        case 'H': return 'H';
        break;
        case 'P': return 'P';
        break;
        default: "You have enterned invlid command! Default command executed: Stand.";
        break;
    }
}



usi setSizeOfDeck()
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
    char choice;
    do
    {
        if(!drawCard(player, deck))
            break;
        else
            choice = makeChoice(player, deck);

    }while(choice == 'H');

    if(choice == 'S')
    {
        stand(player, deck);
    }

    else 
    {
        probabilityCheck(player, deck);
        choice = makeChoice(player, deck);
        do
        {
            if(!drawCard(player, deck))
                break;
            else
            choice = makeChoice(player, deck);
            if(choice == 'P')
            {
                std::cout<<"Sorry, no more probability checks!\n";
                choice = makeChoice(player, deck);
            }

        }while(choice == 'H');

        if(choice == 'S')
        {
            stand(player, deck);
        }
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
            std::cout<<"Sorry, this name isn't in the list or you have enterned invalid age for new player.\nPlayers must be atleast 18 years old!\n";
            main();
        }
        
        Player newPlayer(newPlayerName,newPlayerAge,0,0);
        addToFile(newPlayer);
        std::cout<<"\nYou will play as "<< newPlayerName << ". Choose the size of the deck: \n";
        usi deckSize = setSizeOfDeck();
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
        usi deckSize = setSizeOfDeck();
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
