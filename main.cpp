#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

const string card_types[14] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};



struct Card
{
    int card_value, card_type; 
    // card val = Faces/Digits
    // card type: 0 = heart; 1 = clubs; 2 = diamonds; 3 = spades
    string card_name;
};

vector<Card> populate_deck();
void shuffle_deck(vector<Card> &deck);
void print_deck(vector<Card> &deck);

int main(void)
{
    vector<Card> deck = populate_deck();

    print_deck(deck);
    

    return 0;
}

vector<Card> populate_deck()
{
    Card temp_card;
    vector<Card> return_deck;
    int vals = 0;
    

    for(int i = 0; i < 52; ++i)
    {
        if(vals == 14)
            vals = 0;
        temp_card.card_type = i % 4;
        temp_card.card_value = vals+1;
        temp_card.card_name = card_types[vals];
        return_deck.push_back(temp_card);
        ++vals;
    }

    

    return return_deck;
}

void shuffle_deck(vector<Card> &deck)
{

}

void print_deck(vector<Card> &deck)
{
    for(int i =0; i < deck.size(); i++)
    {
        cout << "\n" << "card type: " << deck[i].card_type << "\tcard val: " << deck[i].card_value<< "\tcard name: " << deck[i].card_name;
    }
    cout << "\n" << deck.size();
    
}