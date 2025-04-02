#include<cstdlib>
#include<iostream>
#include"include/Card.h"
#include"include/Deck.h"
#include"include/Game.h"
#include"include/Player.h"

// TODO: Create UI :)
// TODO: Add playability, duh -- DONE
// TODO: Lose mind -- DONE


int main(void)
{
    //Deck deck_instance;

    // debugging stuff
    //deck_instance.populate_deck();
    //deck_instance.print_deck();
    //Card random_card = deck_instance.choose_random_card();

    //std::cout << "\n" << random_card.card_name << " " << random_card.card_type << " " << random_card.card_value;
    

    Game game_instance;
    game_instance.start_game();




    

    return 0;
}