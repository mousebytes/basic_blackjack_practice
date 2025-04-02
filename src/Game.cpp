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

        //game_deck.print_deck(); // debugging

        // dealer gets two cards into hand first
        dealer.add_card_to_player_hand(game_deck.choose_random_card());
        dealer.add_card_to_player_hand(game_deck.choose_random_card());


        // player gets two cards into hand second
        plyr.add_card_to_player_hand(game_deck.choose_random_card());
        plyr.add_card_to_player_hand(game_deck.choose_random_card());


        

        //debugging section
        plyr.calculate_player_score();
        dealer.calculate_player_score();

        //std::cout << "\nPlayer Cards: " << plyr.hand[0].card_name << " " << plyr.hand[1].card_name << std::endl;
        //std::cout << "\nDealer Cards: "<< dealer.hand[0].card_name << " " << dealer.hand[1].card_name << std::endl;


        //std::cout <<plyr.player_score.first << " " << plyr.player_score.second << " " << dealer.player_score.first << " " << dealer.player_score.second << std::endl;

        

    game_loop(game_deck);

    //do a restart function here later

    // debugging
    //std::cout << "\nDealer: " << dealer.calculate_player_score().first << " & " << dealer.calculate_player_score().second;
    //std::cout << "\nPlayer: " << plyr.calculate_player_score().first << " & " << plyr.calculate_player_score().second;


}

// 0 for player win, 1 for dealer win, 2 for draw, 3 for undecided
int Game::check_for_end_of_game(std::pair<int,int> player_score, std::pair<int,int> dealer_score)
{
    int player_best_score, dealer_best_score;

    

    //checks if the ace condition is less than 21, if not then assign the first part of the pair (non-ace condition)
    if(player_score.first > 21)
        return 1; // dealer win player bust
    if(dealer_score.first > 21)
        return 0; //player win dealer bust
    
    player_best_score = return_best_scores(plyr);
    dealer_best_score = return_best_scores(dealer);

    // compare scores logic
    //debugging
    //std::cout << "\nPlayer best score: " << player_best_score;
    //std::cout << "\nDealer best score: " << dealer_best_score;
    if(standing && (player_best_score == dealer_best_score))
        return 2; // draw
    if(standing && (player_best_score > dealer_best_score))
        return 0; // player win
    if(standing && (dealer_best_score > player_best_score))
        return 1; // dealer win
    



    return 3; // continue game_loop()
}

void Game::game_loop(Deck &d)
{
    standing = false;
    int game_state = 3; // 3 = undecided, 0 = player win, 1 = dealer win, 2 = draw
    int player_best_score, dealer_best_score;
    char stand_or_hit; // s or h
    do
    {
        print_dealer_and_player_cards();

        // **need to offer to hit, stand in this loop
        // for now i'll do a cin for h = hit, s = stand

        
        plyr.calculate_player_score();
        dealer.calculate_player_score();
        player_best_score = return_best_scores(plyr);
        dealer_best_score = return_best_scores(dealer);

        
        // hit/stand logic
        do
        {
            // read stand or hit
            std::cout << "\n\nHit (h) or Stand (s)? ";
            std::cin >> stand_or_hit; // s or h

            if(stand_or_hit == 'h')
            {
                plyr.add_card_to_player_hand(d.choose_random_card());
                plyr.calculate_player_score();
                print_dealer_and_player_cards();
                //std::cout << "\nNew player scores: " << plyr.player_score.first << " & " << plyr.player_score.second;
            }

            if(stand_or_hit == 's')
                standing = true;

            if(return_best_scores(plyr) > 21)
                break;
        } while (!standing);
                
        // check if the player's best score is better than the dealer's best score
        // TODO: Figure out why this block doesn't work
        if(player_best_score < 22 && (player_best_score > dealer_best_score) || dealer_best_score < 17)
        {
            while(dealer_best_score <= player_best_score && dealer_best_score < 22)
            {
                Card temp_card = d.choose_random_card();
                dealer.add_card_to_player_hand(temp_card);
                dealer.calculate_player_score();
                dealer_best_score = return_best_scores(dealer);
            }
            
            //std::cout << "\n\nNew Dealer scores: " << dealer.player_score.first << " & " << dealer.player_score.second;
            print_dealer_and_player_cards();
        }

        // check if the game's over
        game_state = check_for_end_of_game(plyr.player_score, dealer.player_score);
        
        if(game_state < 3)
            end_of_game = true;

        //debugging to prevent infinite loop
        //end_of_game = true;


    } while (!end_of_game);
    
    std::cout << '\n';
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





//TODO: Make a function that returns the best score between the score pairs

int Game::return_best_scores(Player p)
{
    int player_best_score;

    // assign player's highest score
    if(p.player_score.second < 22 && p.player_score.second != 0)
        player_best_score = p.player_score.second;
    else
        player_best_score = p.player_score.first;

    return player_best_score;
}

void Game::print_dealer_and_player_cards()
{
    std::cout << "\n\nPlayer's Cards: ";
    for(Card c : plyr.hand)
    {
        std::cout << c.card_name << " ";
    }

    std::cout << "\nPlayer Score: ";
    if(plyr.player_score.first<22)
    {
        std::cout<< plyr.player_score.first;
        if(plyr.player_score.second != 0 && plyr.player_score.second < 22)
            std::cout << " or " << plyr.player_score.second; 
    }
        
    else
    {
        std::cout << " BUST!";
    }
     
    
    
    std::cout << "\n\nDealer's Cards: ";
    for(Card c : dealer.hand)
    {
        std::cout << c.card_name << " ";
    }
    std::cout << "\nDealer Score: ";
    if(dealer.player_score.first<22)
    {
        std::cout << dealer.player_score.first;
        if(dealer.player_score.second != 0 && dealer.player_score.second < 22)
            std::cout << " or " << dealer.player_score.second; 
    }
    else
        std::cout << " BUST!";
    
    
}







