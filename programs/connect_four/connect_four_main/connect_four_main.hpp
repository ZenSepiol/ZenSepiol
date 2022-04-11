#pragma once

#include "../connect_four_game/connect_four_game.hpp"
#include "../connect_four_player/connect_four_player.hpp"

class ConnectFourMain
{
  public:
    ConnectFourMain(ConnectFourPlayer* player_red, ConnectFourPlayer* player_blue);
    void Run();

  private:
    ConnectFourGame connect_four;
    ConnectFourPlayer* player_red;
    ConnectFourPlayer* player_blue;
};