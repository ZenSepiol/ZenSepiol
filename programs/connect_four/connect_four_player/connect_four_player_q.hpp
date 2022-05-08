#pragma once

#include "../connect_four_game/connect_four_game.hpp"
#include "../connect_four_player/connect_four_player.hpp"
#include <unordered_map>
#include <random>
#include <chrono>

template<>
struct std::hash<ConnectFourGame::GameState> {
    std::size_t operator()(const ConnectFourGame::GameState& e) const {
        std::size_t hash_result = 0;
        // calculate the hash result
        int index = 0;
        for (auto& row : e) {
            for (auto& player : row) {
                hash_result += static_cast<int>(player) << (index*2);
                index++;
            }
        }
        return hash_result;
    }
};

class ConnectFourPlayerQ : public ConnectFourPlayer
{
  public:
    ConnectFourPlayerQ(Player self, Player other);
    ~ConnectFourPlayerQ() = default;

    virtual int Move(ConnectFourGame& game);

  private:
    Player self;
    Player other;

    float learning_rate = 0.8;
    float discount_rate = 0.9;
    float explore_rate = 0.20;

    bool is_learning = true;

    std::unordered_map<ConnectFourGame::GameState, std::unordered_map<int, float>> Q;
    
    std::mt19937 mt = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> rand_percent{0, 99};

    int previous_action = 0; 
    ConnectFourGame previous_game;
    bool first_move = true;
};
