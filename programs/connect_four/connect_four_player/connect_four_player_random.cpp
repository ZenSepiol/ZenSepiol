#include <random>

#include "connect_four_player_random.hpp"

int ConnectFourPlayerRandom::Move(ConnectFourGame& game)
{
    return rand_column(mt);
}