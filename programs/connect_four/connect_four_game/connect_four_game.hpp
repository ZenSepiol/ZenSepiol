#pragma once

#include <array>
#include <set>

enum class Player
{
    red,
    blue,
    none
};

class ConnectFourGame
{
  public:
    using GameState = std::array<std::array<Player, 7>, 6>;

    ConnectFourGame();

    // Makes a move for the current player between 1 and 7
    // Changes the game state
    // Evaluates the move
    void Move(int column);

    // Returns the game state
    GameState GetGameState();

    void PrintGameState();

    // Returns the value of the game state at row/column
    Player GetPlayer(int row, int column);

    // Returns the current player
    Player GetCurrentPlayer();

    // Returns the winner
    Player GetWinner();

    // Returns the top most row in the given column
    int GetTopRow(int column);

    void SetGameState(const GameState& game_state);

    std::set<int> CalculatePossibleMoves();

    bool game_over = false;

  private:
    // Returns the value of the top most row in the given column
    Player GetTopPlayer(int column);

    // Evaluates the last stone in column
    // Returns true if the stone lead to a win
    Player EvaluateMove(int column);

    // Given a player and a position, evaluates if that position leads to a win in
    // the column
    Player EvaluateForColumn(Player player, int row, int column);
    // Given a player and a position, evaluates if that position leads to a win in
    // the row
    Player EvaluateForRow(Player player, int row, int column);
    // Given a player and a position, evaluates if that position leads to a win in
    // the diag
    Player EvaluateForDiagonal(Player player, int row, int column);
    // Given a player and a position, evaluates if that position leads to a win in
    // the anti-diag
    Player EvaluateForAntidiagonal(Player player, int row, int column);

    GameState game_state;

    Player winner = Player::none;

    Player current_player = Player::red;
};
