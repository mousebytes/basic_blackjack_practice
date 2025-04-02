#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include"Card.h"

struct Player
{
    std::string name;
    std::vector<Card> hand;
    std::pair<int, int> player_score; // pair to tell the two different values if there's an ace present
    bool is_dealer, aces_present, jack_present, standing;

    Player();

    void add_card_to_player_hand(Card c);
    std::pair<int, int> calculate_player_score();
    void reset_player_hand();

};














#endif