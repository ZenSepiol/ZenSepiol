#include <iostream>
#include <stdio.h>

#include "connect_four_game/connect_four_game.hpp"
#include "connect_four_main/connect_four_main.hpp"
#include "connect_four_player/connect_four_player_random.hpp"
#include "connect_four_player/connect_four_player_stdin.hpp"
#include "connect_four_player/connect_four_player_q.hpp"

int main(int, char**)
{
    ConnectFourPlayerQ player_red(Player::red, Player::blue);
    // ConnectFourPlayerRandom player_blue;
    ConnectFourPlayerQ player_blue(Player::blue, Player::red);

    ConnectFourMain connect_four_main(&player_red, &player_blue);
    connect_four_main.Run();

    return 0;
}

