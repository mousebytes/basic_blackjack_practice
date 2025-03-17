#ifndef DECK_H
#define DECK_H
#include"Card.h"
#include<vector>

struct Deck
{
    std::vector<Card> deck;

    Deck();

    void populate_deck();
    void print_deck(); // debugging
    void clear_deck();
    void shuffle_deck();
    Card choose_random_card();

};








#endif