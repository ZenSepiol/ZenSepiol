#include "connect_four_game.hpp"

#include <algorithm>
#include <iostream>

ConnectFourGame::ConnectFourGame()
{
    game_state = GameState();
    for (auto& row : game_state)
    {
        std::fill(row.begin(), row.end(), Player::none);
    }
}

ConnectFourGame::GameState ConnectFourGame::GetGameState()
{
    return game_state;
}

void ConnectFourGame::SetGameState(const GameState& game_state)
{
    this->game_state = game_state;
}

void ConnectFourGame::PrintGameState()
{
    for (auto& row : game_state)
    {
        for (auto& player : row)
        {
            std::cout << static_cast<int>(player) << "  ";
        }
        std::cout << std::endl;
    }
}

Player ConnectFourGame::GetTopPlayer(int column)
{
    return game_state[GetTopRow(column)][column];
}

int ConnectFourGame::GetTopRow(int column)
{
    for (int row = 0; row <= 5; ++row)
    {
        if (GetPlayer(row, column) != Player::none)
        {
            return row;
        }
    }
    return 6;
}

Player ConnectFourGame::GetPlayer(int row, int column)
{
    return game_state[row][column];
}

Player ConnectFourGame::EvaluateMove(int column)
{
    auto row = GetTopRow(column);
    auto player = GetTopPlayer(column);

    if (EvaluateForRow(player, row, column) == player)
        return player;
    if (EvaluateForColumn(player, row, column) == player)
        return player;
    if (EvaluateForDiagonal(player, row, column) == player)
        return player;
    if (EvaluateForAntidiagonal(player, row, column) == player)
        return player;

    return Player::none;
}

Player ConnectFourGame::EvaluateForRow(Player player, int row, int column)
{
    int connected = 1;
    for (int local_row = row - 1; local_row >= 0; --local_row)
    {
        if (GetPlayer(local_row, column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
    }
    for (int local_row = row + 1; local_row <= 5; ++local_row)
    {
        if (GetPlayer(local_row, column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
    }

    if (connected >= 4)
    {
        return player;
    }
    return Player::none;
}

Player ConnectFourGame::EvaluateForColumn(Player player, int row, int column)
{
    int connected = 1;
    for (int local_column = column - 1; local_column >= 0; --local_column)
    {
        if (GetPlayer(row, local_column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
    }
    for (int local_column = column + 1; local_column <= 6; ++local_column)
    {
        if (GetPlayer(row, local_column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
    }

    if (connected >= 4)
    {
        return player;
    }
    return Player::none;
}

Player ConnectFourGame::EvaluateForDiagonal(Player player, int row, int column)
{
    int connected = 1;
    int local_column = column - 1;
    int local_row = row - 1;
    while (local_column >= 0 && local_row >= 0)
    {
        if (GetPlayer(local_row, local_column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
        --local_column;
        --local_row;
    }

    local_column = column + 1;
    local_row = row + 1;
    while (local_column <= 6 && local_row <= 5)
    {
        if (GetPlayer(local_row, local_column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
        ++local_column;
        ++local_row;
    }

    if (connected >= 4)
    {
        return player;
    }
    return Player::none;
}

Player ConnectFourGame::EvaluateForAntidiagonal(Player player, int row, int column)
{
    int connected = 1;
    int local_column = column - 1;
    int local_row = row + 1;
    while (local_column >= 0 && local_row <= 5)
    {
        if (GetPlayer(local_row, local_column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
        --local_column;
        ++local_row;
    }

    local_column = column + 1;
    local_row = row - 1;
    while (local_column <= 6 && local_row >= 0)
    {
        if (GetPlayer(local_row, local_column) == player)
        {
            ++connected;
        }
        else
        {
            break;
        }
        ++local_column;
        --local_row;
    }

    if (connected >= 4)
    {
        return player;
    }
    return Player::none;
}

void ConnectFourGame::Move(int column)
{
    if (!game_over)
    {
        auto row = GetTopRow(column);
        if (row > 6)
        {
            return;
        }

        game_state[row - 1][column] = current_player;
    }

    if (current_player == Player::red)
    {
        current_player = Player::blue;
    }
    else
    {
        current_player = Player::red;
    }

    if (!game_over)
    {
        winner = EvaluateMove(column);
    }

    if (CalculatePossibleMoves().empty() || winner != Player::none)
    {
        game_over = true;
    }
}

Player ConnectFourGame::GetCurrentPlayer()
{
    return current_player;
}

Player ConnectFourGame::GetWinner()
{
    return winner;
}

std::set<int> ConnectFourGame::CalculatePossibleMoves()
{
    std::set<int> all_moves = {0, 1, 2, 3, 4, 5, 6};
    std::set<int> possible_moves = {};

    for (auto& move : all_moves)
    {
        if (GetTopRow(move) > 0)
        {
            possible_moves.emplace(move);
        }
    }
    return possible_moves;
}