#include"Game.h"
#include<iostream>

//TODO: ADD PEEK FUNCTION TO PEEK REST OF DECK (WHEN I DO UI)

Deck game_deck;
Player plyr, dealer;


Game::Game()
{
    standing = false;
    end_of_game = false;
}

void Game::start_game()
{
    dealer.is_dealer = true;

    game_loop();

    // debugging
    //std::cout << "\nDealer: " << dealer.calculate_player_score().first << " & " << dealer.calculate_player_score().second;
    //std::cout << "\nPlayer: " << plyr.calculate_player_score().first << " & " << plyr.calculate_player_score().second;


}

// 0 for player win, 1 for dealer win, 2 for draw
int Game::check_for_end_of_game(std::pair<int,int> player_score, std::pair<int,int> dealer_score)
{
    // this function needs to check for win conditions, such as when the dealer or player bust
    // some other win cons can be
    // player has 21 while dealer does not and vice versa
    // player has a greater score than dealer that does not exceed 21 or vice versa

    if (player_score.first > 21) // this is the case where aces are worth 1 pt, meaning if this is greater than 21 they bust
    {
        return 1; // dealer won since player bust
    }
    if(dealer_score.first > 21) // same as above but for dealer
    {
        return 0; // player won since dealer bust
    }

    



    // TODO: i don't think this works, check back on it later
    // this is the last case where the dealer and player scores are the same
    if(player_score.first == dealer_score.first && player_score.second == dealer_score.second)


    std::cout << "\np.first: " << player_score.first << "p.second: " << player_score.second << "d.first: " << dealer_score.first << "d.second: " << dealer_score.second;
    
    
}

void Game::game_loop()
{

    do
    {
        // **need to offer to hit, stand in this loop
        // for now i'll do a cin for 0 = hit, 1 = stand

        game_deck.populate_deck();
        game_deck.shuffle_deck(); // generate and populate the deck that the dealer and player will draw from

        // dealer gets two cards into hand first
        dealer.add_card_to_player_hand(game_deck.choose_random_card());
        dealer.add_card_to_player_hand(game_deck.choose_random_card());

        // player gets two cards into hand second
        plyr.add_card_to_player_hand(game_deck.choose_random_card());
        plyr.add_card_to_player_hand(game_deck.choose_random_card());


        //debugging section
        plyr.calculate_player_score();
        dealer.calculate_player_score();

        check_for_end_of_game(plyr.player_score, dealer.player_score);
        end_of_game = true;


    } while (!end_of_game);
    

}
















