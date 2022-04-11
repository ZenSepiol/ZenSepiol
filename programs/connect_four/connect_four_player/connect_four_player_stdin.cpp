#include <iostream>

#include "connect_four_player_stdin.hpp"

int ConnectFourPlayerStdin::Move(ConnectFourGame& game)
{
    int column;
    std::cin >> column;

    return column;
}