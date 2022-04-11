
#include "connect_four_main.hpp"

#include <iostream>

ConnectFourMain::ConnectFourMain(ConnectFourPlayer* player_red, ConnectFourPlayer* player_blue)
    : player_red(player_red), player_blue(player_blue)
{
}

void ConnectFourMain::Run()
{
    while (!connect_four.game_over)
    {
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "Player " << static_cast<int>(connect_four.GetCurrentPlayer()) << " is playing. " << std::endl;
        if (connect_four.GetCurrentPlayer() == Player::red)
        {
            player_red->Play(connect_four);
        }
        else
        {
            player_blue->Play(connect_four);
        }

        connect_four.PrintGameState();
    }

    std::cout << "Player " << static_cast<int>(connect_four.GetWinner()) << " has won the game. " << std::endl;
}