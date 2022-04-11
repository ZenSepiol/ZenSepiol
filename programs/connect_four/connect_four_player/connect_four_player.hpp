#pragma once

#include <set>
#include "../connect_four_game/connect_four_game.hpp"

// Abstract Base Class for Connect Four Players
class ConnectFourPlayer
{
  public:
    ConnectFourPlayer() = default;
    virtual ~ConnectFourPlayer() = default;

    virtual int Move(ConnectFourGame& game) = 0;

    void Play(ConnectFourGame& game);
};