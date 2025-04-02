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

        game_deck.populate_deck();
        game_deck.shuffle_deck(); // generate and populate the deck that the dealer and player will draw from

        game_deck.print_deck(); // debugging

        // dealer gets two cards into hand first
        dealer.add_card_to_player_hand(game_deck.choose_random_card());
        dealer.add_card_to_player_hand(game_deck.choose_random_card());

        // player gets two cards into hand second
        plyr.add_card_to_player_hand(game_deck.choose_random_card());
        plyr.add_card_to_player_hand(game_deck.choose_random_card());


        //debugging section
        plyr.calculate_player_score();
        dealer.calculate_player_score();

        std::cout << "\nPlayer Cards: " << plyr.hand[0].card_name << " " << plyr.hand[1].card_name << std::endl;
        std::cout << "\nDealer Cards: "<< dealer.hand[0].card_name << " " << dealer.hand[1].card_name << std::endl;


        std::cout <<plyr.player_score.first << " " << plyr.player_score.second << " " << dealer.player_score.first << " " << dealer.player_score.second << std::endl;

        

    game_loop(game_deck);

    //do a restart function here later

    // debugging
    //std::cout << "\nDealer: " << dealer.calculate_player_score().first << " & " << dealer.calculate_player_score().second;
    //std::cout << "\nPlayer: " << plyr.calculate_player_score().first << " & " << plyr.calculate_player_score().second;


}

// 0 for player win, 1 for dealer win, 2 for draw, 3 for undecided
int Game::check_for_end_of_game(std::pair<int,int> player_score, std::pair<int,int> dealer_score)
{
    /*
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

    // already handled bust cases so can use first and second freely
    // need cases here that take into account when aces are present (p.second)
    
    // maybe handle second cases (ace cases) first so if theyre true we can find a winner

    // case where player's ace case is less than 21 but greater than dealer's ace case
    if(standing && player_score.second < 21 && (player_score.second > dealer_score.second))
        return 0;



    // this is the last case where the dealer and player scores are the same
    if(player_score.first == dealer_score.first)
        return 2;


    */

    // work on the above logic later, for now try the best score situation

    int player_best_score, dealer_best_score;


    //checks if the ace condition is less than 21, if not then assign the first part of the pair (non-ace condition)
    if(player_score.first > 21)
        return 1; // dealer win player bust
    if(dealer_score.first > 21)
        return 0; //player win dealer bust
    
    // assign player's highest score
    if(player_score.second < 22)
        player_best_score = player_score.second;
    else
        player_best_score = player_score.first;

    // assign dealer's highest score
    if(dealer_score.second<22)
        dealer_best_score = dealer_score.second;
    else
        dealer_best_score = dealer_score.first;

    // compare scores logic
    if(standing && (player_best_score > dealer_best_score))
        return 0; // player win
    if(standing && (dealer_best_score > player_best_score))
        return 1; // dealer win
    if(standing && (player_best_score == dealer_best_score))
        return 2; // draw



    return 3; // continue game_loop()
}

void Game::game_loop(Deck &d)
{
    int game_state = 3; // 3 = undecided, 0 = player win, 1 = dealer win, 2 = draw
    int player_best_score, dealer_best_score;
    char stand_or_hit; // s or h
    do
    {
        // **need to offer to hit, stand in this loop
        // for now i'll do a cin for h = hit, s = stand

        
        plyr.calculate_player_score();
        dealer.calculate_player_score();
        
        
        
        // read stand or hit
        std::cout << "\nHit (h) or Stand (s)? ";
        std::cin >> stand_or_hit; // s or h

        // hit logic
        //TODO: add hits until bust
        if(stand_or_hit == 'h')
        {
            plyr.add_card_to_player_hand(d.choose_random_card());
            plyr.calculate_player_score();
            std::cout << "\nNew player scores: " << plyr.player_score.first << " & " << plyr.player_score.second;
        }
        

        if(stand_or_hit == 's')
            standing = true;

        if(plyr.player_score.second < 22)
            player_best_score = plyr.player_score.second;
        else
            player_best_score = plyr.player_score.first;

        // assign dealer's highest score
        if(dealer.player_score.second<22)
            dealer_best_score = dealer.player_score.second;
        else
            dealer_best_score = dealer.player_score.first;
        
        // check if the player's best score is better than the dealer's best score
        // TODO: Figure out why this block doesn't work
        if(player_best_score < 22 && (player_best_score > dealer_best_score))
        {
            while(dealer_best_score < player_best_score && dealer_best_score < 22)
            {
                Card temp_card = d.choose_random_card();
                dealer.add_card_to_player_hand(temp_card);
                dealer.calculate_player_score();
                dealer_best_score += temp_card.card_value;
            }
            
            std::cout << "\nNew Dealer scores: " << dealer.player_score.first << " & " << dealer.player_score.second;
            std::cout << "\nDealer's cards: ";
            for(Card c : dealer.hand)
            {
                std::cout << c.card_name << " ";
            }
        }

        // check if the game's over
        game_state = check_for_end_of_game(plyr.player_score, dealer.player_score);
        
        if(game_state < 3)
            end_of_game = true;

        //debugging to prevent infinite loop
        //end_of_game = true;


    } while (!end_of_game);
    
    if(game_state!=2)
        std::cout << "\nWinner: ";
    else
        std::cout <<"\nDraw";

    if(game_state == 0)
        std::cout << "Player";
    if(game_state==1)
        std::cout << "Dealer";


        // TODO: add restart logic
        // if()
        // game_start()
}
















