#include <random>
#include <algorithm>

#include "connect_four_player_random.hpp"

int ConnectFourPlayerRandom::Move(ConnectFourGame& game)
{
    auto possible_moves = game.CalculatePossibleMoves();
    std::vector<int> out;
    std::sample(possible_moves.begin(), possible_moves.end(), std::back_inserter(out), 1, mt);

    return out.back();
}