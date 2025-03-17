#include<Player.h>

Player::Player()
{
    name = "";
    hand = {};
    player_score = {};
    is_dealer = false;
    aces_present = false;
}

void Player::add_card_to_player_hand(Card c)
{
    if(c.card_value == 1)
        aces_present = true;
    hand.push_back(c);
}

void Player::calculate_player_score()
{
    if(aces_present) // if aces exist in the hand then 
    {
        for(Card c : hand)
            player_score.first += c.card_value;
        for(Card c : hand)
            {
                if(c.card_value == 1)
                    player_score.second += 11;
                else
                    player_score.second += c.card_value;
            }
    }
    else
    {
        for(Card c : hand)
            player_score.first += c.card_value;
    }
}

void Player::reset_player_hand()
{
    hand.clear();
}