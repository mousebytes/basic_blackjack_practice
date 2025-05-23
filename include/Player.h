#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include"Card.h"

struct Player
{
    std::string name;
    std::vector<Card> hand;
    std::pair<int, int> player_score; // pair to tell the two different values if there's an ace present
    bool is_dealer, aces_present, face_present, standing;
    double bet;


    Player();

    void add_card_to_player_hand(Card c);
    void calculate_player_score();
    void reset_player_hand();

};














#endif