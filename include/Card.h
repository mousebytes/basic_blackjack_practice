#ifndef CARD_H
#define CARD_H

#include<string>

struct Card
{
    int card_value, card_type; 
    // card val = Faces/Digits
    // card type: 0 = heart; 1 = clubs; 2 = diamonds; 3 = spades
    std::string card_name;

    Card(int v, int t, std::string n);
    Card();
};










#endif