
#include "connect_four_main.hpp"
#include "../connect_four_player/connect_four_player_q.hpp"

#include <iostream>

ConnectFourMain::ConnectFourMain(ConnectFourPlayer* player_red, ConnectFourPlayer* player_blue)
    : player_red(player_red), player_blue(player_blue)
{
}

void ConnectFourMain::Run()
{
    int games_played = 0; 
    while(1)
    {
        games_played++;
        ConnectFourGame connect_four;
        while (!connect_four.game_over)
        {
            // std::cout << std::endl << std::endl;
            // std::cout << "Player " << static_cast<int>(connect_four.GetCurrentPlayer()) << " is playing. " << std::endl;
            if (connect_four.GetCurrentPlayer() == Player::red)
            {
                player_red->Play(connect_four);
            }
            else
            {
                player_blue->Play(connect_four);
            }

            // connect_four.PrintGameState();
        }
        if(connect_four.game_over)
        {
            if (dynamic_cast<ConnectFourPlayerQ*>(player_red))
            {
                player_red->Play(connect_four);
            }
            if (dynamic_cast<ConnectFourPlayerQ*>(player_blue))
            {
                player_blue->Play(connect_four);
            }

            if (connect_four.GetWinner() == Player::red)
            {
                ++red_won;
            }
            else if (connect_four.GetWinner() == Player::blue)
            {
                ++blue_won;
            }
            else
            {
                ++draw;
            }
            player_red->debug_output = false;
        }

        // std::cout << "Player " << static_cast<int>(connect_four.GetWinner()) << " has won the game. " << std::endl;

        if(output)
        {
            std::cout << "Games played: " << games_played << std::endl;
            std::cout << "Red won: " << red_won << std::endl;
            std::cout << "Blue won: " << blue_won << std::endl;
            std::cout << "Draw: " << draw << std::endl;
            std::cout << "Percentage: " << static_cast<float>(red_won) / (red_won + blue_won + draw) << std::endl << std::endl;
            red_won = 0;
            blue_won = 0;
            draw = 0;  

            output = false;
        }
        if (games_played % 100000 == 0)
        {
            player_red->debug_output = true;
            output = true;
        }
        
    }
}