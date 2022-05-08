#include <icecream.hpp>
#include <iostream>

#include "connect_four_player.hpp"

void ConnectFourPlayer::Play(ConnectFourGame& game)
{
    auto planned_move = Move(game);

    // std::cout << "Player " << static_cast<int>(game.GetCurrentPlayer()) << " plays column " << planned_move <<
    // std::endl;
    game.Move(planned_move);
}