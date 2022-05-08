#include "connect_four_player_q.hpp"
#include <icecream.hpp>
#include <algorithm>

ConnectFourPlayerQ::ConnectFourPlayerQ(Player self, Player other) : ConnectFourPlayer(), self(self), other(other)
{
}

int ConnectFourPlayerQ::Move(ConnectFourGame& game)
{
    if (Q.find(game.GetGameState()) == Q.end())
    {
        Q[game.GetGameState()] = std::unordered_map<int, float>();
        for (auto& action : game.CalculatePossibleMoves())
        {
            Q[game.GetGameState()].emplace(std::make_pair(action, 0.0f));
        }
    }

    if (is_learning)
    {
        float reward = 0.f;
        float maximum_future_reward = 0.f;

        // Update Q Matrix for the last move
        if (!first_move)
        {
            // Get reward for old action
            if (game.game_over)
            {
                if (game.GetWinner() == self)
                {
                    reward = 1.F;
                }
                else if (game.GetWinner() == other)
                {
                    reward = -1.F;
                }
                else
                {
                    reward = 0.F;
                }
            }            

            if (!Q[game.GetGameState()].empty() && !game.game_over)
            {
                maximum_future_reward = Q[game.GetGameState()].begin()->second;
                for (auto& action : Q[game.GetGameState()])
                {
                    maximum_future_reward = std::max(maximum_future_reward, action.second);
                }
            }
            float delta = learning_rate *
                          (reward + discount_rate * maximum_future_reward - Q[previous_game.GetGameState()][previous_action]);
            Q[previous_game.GetGameState()][previous_action] += delta;
        }
        else
        {
            first_move = false;
        }

        // Choose action according to epsilon-greedy policy
        int action = 0;
        if (!game.game_over)
        {
            if (rand_percent(mt) < static_cast<int>(explore_rate * 100.f))
            {
                auto possible_moves = game.CalculatePossibleMoves();
                std::vector<int> out;
                std::sample(possible_moves.begin(), possible_moves.end(), std::back_inserter(out), 1, mt);
                action = out.back();
                
            }
            else
            {
                auto possible_moves = game.CalculatePossibleMoves();
                float max_value = Q[game.GetGameState()][*possible_moves.begin()];
                action = *possible_moves.begin();
                for (auto& move : possible_moves)
                {
                    if (Q[game.GetGameState()][move] > max_value)
                    {
                        max_value = Q[game.GetGameState()][move];
                        action = move;
                    }
                }
            }
        }

        if (self == Player::red && debug_output)
        {
            game.PrintGameState();
            IC(Q[game.GetGameState()]);
            IC(reward);
            IC(maximum_future_reward);
            IC(action);

            IC(Q[previous_game.GetGameState()]);
            IC(Q.size());
            std::cout << std::endl;
        }

        previous_game = game;
        previous_action = action;

        return action;
    }
    else
    {
        auto possible_moves = game.CalculatePossibleMoves();
        float max_value = Q[game.GetGameState()][*possible_moves.begin()];
        int action = 0;

        for (auto& move : possible_moves)
        {
            if (Q[game.GetGameState()][move] > max_value)
            {
                max_value = Q[game.GetGameState()][move];
                action = move;
            }
        }
        return action;
    }

    return rand_column(mt);
}