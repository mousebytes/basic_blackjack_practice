#include<Player.h>

Player::Player()
{
    name = "";
    hand = {};
    player_score = {};
    is_dealer = false;
    aces_present = false;
    jack_present = false;
    standing = false;
}

void Player::add_card_to_player_hand(Card c)
{
    if(c.card_value == 1)
        aces_present = true;
    if(c.card_value == 11)
        jack_present = true;
    hand.push_back(c);
}

std::pair<int,int> Player::calculate_player_score()
{
    player_score = {0,0}; // reset the score
    if((jack_present && aces_present) && hand.size() == 2) // blackjack!!
    {
        player_score.first = 21;
        player_score.second = 0;
    }
    else if(aces_present) // if aces exist in the hand then 
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
        player_score.second = 0;
    }
    return player_score;
}

void Player::reset_player_hand()
{
    hand.clear();
}