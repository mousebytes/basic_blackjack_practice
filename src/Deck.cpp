#include"Deck.h"
#include<iostream>
#include <random> // for mt19937
#include<algorithm> // for shuffle
const std::string card_names[14] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};


Deck::Deck()
{
    deck = {};
}

void Deck::populate_deck()
{
    Card temp_card;
    
    int vals = 0;
    

    for(int i = 0; i < 52; ++i) // populate all 52 cards
    {
        if(vals == 13) // if it reaches the end of a set (Ace (1) through King (13) -> reset to new set)
            vals = 0;
        temp_card.card_type = i % 4; // change the type (hearts, clubs, etc) based on what its i remainder is
        temp_card.card_value = vals+1; // change the card value based on the int being changed per iteration and set
        temp_card.card_name = card_names[vals]; // change the cards name based on the previously mentioned int from a globally defined araay
        deck.push_back(temp_card); // push the new card into the vector that will be sent back
        ++vals; // increment the value that keeps track of the set
    }
}

void Deck::print_deck()
{
    for(Card c : deck)
        std::cout << "\n" << "card type: " << c.card_type << "\tcard val: " << c.card_value<< "\tcard name: " << c.card_name;
 
    std::cout << "\n" << deck.size();
}

void Deck::clear_deck()
{
    deck.clear();
}

void Deck::shuffle_deck()
{
    std::random_device rd; // i would usually use srand(time(NULL)) and rand(), however i found this online and i'm trying it out :)
    std::mt19937 m(rd()); // mersenne twister engine (rng)

    shuffle(deck.begin(),deck.end(), m); // integrated shuffle function from algorithm
}

Card Deck::choose_random_card()
{
    std::random_device rd;
    std::mt19937 m(rd());
    std::uniform_int_distribution<int> dist(0,deck.size()-1); // found all of this online
    Card rand_card;

    rand_card = deck[dist(m)]; // populate this variable with a random card

    for(int i =0;i<deck.size();i++)
    {
        // if the card exists -> remove it
        if(rand_card.card_name == deck[i].card_name && rand_card.card_type == deck[i].card_type && rand_card.card_value == deck[i].card_value)
            deck.erase(deck.begin() + i); // iterate to card's location in deck to erase
    }

    return rand_card;
}



