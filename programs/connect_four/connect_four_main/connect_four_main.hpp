#pragma once

#include "../connect_four_game/connect_four_game.hpp"
#include "../connect_four_player/connect_four_player.hpp"

class ConnectFourMain
{
  public:
    ConnectFourMain(ConnectFourPlayer* player_red, ConnectFourPlayer* player_blue);
    void Run();

  private:
    ConnectFourPlayer* player_red;
    ConnectFourPlayer* player_blue;

    int number_of_games = 1000000;

    int red_won = 0;
    int blue_won = 0;
    int draw = 0;

    bool output = true;
};