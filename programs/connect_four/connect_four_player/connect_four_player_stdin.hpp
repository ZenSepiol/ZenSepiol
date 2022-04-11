#pragma once

#include <iostream>

#include "../connect_four_game/connect_four_game.hpp"
#include "../connect_four_player/connect_four_player.hpp"

// Abstract Base Class for Connect Four Players
class ConnectFourPlayerStdin : public ConnectFourPlayer
{
  public:
    ConnectFourPlayerStdin() = default;
    ~ConnectFourPlayerStdin() = default;

    virtual int Move(ConnectFourGame& game);
};