#ifndef GAME_H
#define GAME_H
#include"Card.h"
#include"Deck.h"
#include"Player.h"

struct Game
{
    bool standing; // standing is to check if the player is standing
    bool end_of_game; // check whether dealer/player bust or win

    Game();

    void start_game();
    void check_for_end_of_game(std::pair<int,int> player_score, std::pair<int,int> dealer_score);
    void game_loop();
};














#endif