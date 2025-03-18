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
    std::cout << "\nDealer: " << dealer.calculate_player_score().first << " & " << dealer.calculate_player_score().second;
    std::cout << "\nPlayer: " << plyr.calculate_player_score().first << " & " << plyr.calculate_player_score().second;


}

void Game::check_for_end_of_game(std::pair<int,int> player_score, std::pair<int,int> dealer_score)
{
    // ternary operator to check for best score
    int player_best_score = (player_score.second <= 21) ? player_score.second : player_score.first;
    int dealer_best_score = (dealer_score.second <= 21) ? dealer_score.second : dealer_score.first;

    end_of_game = false;

    if(player_best_score > 21)
    {
        std::cout << "\nPlayer bust";
        end_of_game = true;
    }
    if(dealer_best_score > 21)
    {
        std::cout << "\nDealer bust";
        end_of_game = true;
    }


    if(standing)
    {
        if(dealer_best_score > player_best_score)
    {
        std::cout << "\nDealer wins";
        end_of_game = true;
    }
        if(player_best_score > dealer_best_score)
        {
            std::cout << "\nPlayer wins";
            end_of_game = true;
        }
        if(player_best_score == dealer_best_score)
        {
            std::cout << "\nDraw";
            end_of_game = true;
        }
    }
    
    
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


    } while (!end_of_game);
    

}
















