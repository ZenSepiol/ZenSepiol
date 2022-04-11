#pragma once

#include <random>
#include <chrono>

#include "../connect_four_game/connect_four_game.hpp"
#include "../connect_four_player/connect_four_player.hpp"

// Abstract Base Class for Connect Four Players
class ConnectFourPlayerRandom : public ConnectFourPlayer
{
  public:
    ConnectFourPlayerRandom() = default;
    ~ConnectFourPlayerRandom() = default;

    virtual int Move(ConnectFourGame& game);

  private:
    std::mt19937 mt = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> rand_column{0, 6};
};