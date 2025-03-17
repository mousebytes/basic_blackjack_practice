#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include <random> // for mt19937
#include<algorithm> // for shuffle
using namespace std;

// TODO: Create UI :)
// TODO: Add playability, duh
// TODO: Lose mind -- DONE

const string card_names[14] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};



struct Card
{
    int card_value, card_type; 
    // card val = Faces/Digits
    // card type: 0 = heart; 1 = clubs; 2 = diamonds; 3 = spades
    string card_name;
};

vector<Card> populate_deck(); // done
void shuffle_deck(vector<Card> &deck); // done
void print_deck(vector<Card> &deck); // debugging purposes


int main(void)
{
    vector<Card> deck = populate_deck();

    print_deck(deck);
    shuffle_deck(deck);
    print_deck(deck);

    return 0;
}

vector<Card> populate_deck()
{
    Card temp_card;
    vector<Card> return_deck;
    int vals = 0;
    

    for(int i = 0; i < 52; ++i) // populate all 52 cards
    {
        if(vals == 13) // if it reaches the end of a set (Ace (1) through King (13) -> reset to new set)
            vals = 0;
        temp_card.card_type = i % 4; // change the type (hearts, clubs, etc) based on what its i remainder is
        temp_card.card_value = vals+1; // change the card value based on the int being changed per iteration and set
        temp_card.card_name = card_names[vals]; // change the cards name based on the previously mentioned int from a globally defined araay
        return_deck.push_back(temp_card); // push the new card into the vector that will be sent back
        ++vals; // increment the value that keeps track of the set
    }

    

    return return_deck;
}

void shuffle_deck(vector<Card> &deck)
{
    random_device rd; // i would usually use srand(time(NULL)) and rand(), however i found this online and i'm trying it out :)
    mt19937 m(rd()); // mersenne twister engine (rng)

    shuffle(deck.begin(),deck.end(), m); // integrated shuffle function from algorithm
}

void print_deck(vector<Card> &deck)
{
    for(Card c : deck)
        cout << "\n" << "card type: " << c.card_type << "\tcard val: " << c.card_value<< "\tcard name: " << c.card_name;
 
    cout << "\n" << deck.size();
}