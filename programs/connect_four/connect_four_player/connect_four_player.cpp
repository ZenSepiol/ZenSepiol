#include <iostream>
#include <icecream.hpp>

#include "connect_four_player.hpp"

void ConnectFourPlayer::Play(ConnectFourGame& game)
{  
  auto possible_moves = game.CalculatePossibleMoves();
  auto planned_move = Move(game);
  while (possible_moves.find(planned_move) == possible_moves.end())
  {
    planned_move = Move(game);
  }

  std::cout << "Player " << static_cast<int>(game.GetCurrentPlayer()) << " plays column " << planned_move << std::endl;
  game.Move(planned_move);
}