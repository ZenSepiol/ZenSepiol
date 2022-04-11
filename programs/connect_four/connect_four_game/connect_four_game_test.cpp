#define CATCH_CONFIG_MAIN
#include "connect_four_game.hpp"

#include <catch.hpp>

TEST_CASE("Init Game is empty", "[single-file]")
{
    ConnectFourGame connect_four_game;

    auto state = connect_four_game.GetGameState();

    for (auto& row : state)
    {
        for (auto& player : row)
        {
            REQUIRE(player == Player::none);
        }
    }
}

TEST_CASE("Get Player", "[single-file]")
{
    ConnectFourGame connect_four_game;

    // clang-format off
  ConnectFourGame::GameState state = 
    {{
    {{Player::none, Player::none, Player::none, Player::red, Player::blue, Player::none, Player::none}},
    {{Player::none, Player::none, Player::none, Player::red, Player::none, Player::none, Player::none}},
    {{Player::none, Player::none, Player::none, Player::red, Player::none, Player::none, Player::none}},
    {{Player::none, Player::none, Player::none, Player::red, Player::none, Player::none, Player::none}},
    {{Player::none, Player::none, Player::none, Player::red, Player::none, Player::none, Player::none}},
    {{Player::none, Player::none, Player::none, Player::red, Player::none, Player::none, Player::none}}
    }};
    // clang-format on

    connect_four_game.SetGameState(state);

    REQUIRE(connect_four_game.GetPlayer(0, 0) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(0, 1) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(0, 2) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(0, 3) == Player::red);
    REQUIRE(connect_four_game.GetPlayer(0, 4) == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(0, 5) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(0, 6) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(1, 0) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(1, 1) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(1, 2) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(1, 3) == Player::red);
    REQUIRE(connect_four_game.GetPlayer(1, 4) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(1, 5) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(1, 6) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(2, 0) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(2, 1) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(2, 2) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(2, 3) == Player::red);
    REQUIRE(connect_four_game.GetPlayer(2, 4) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(2, 5) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(2, 6) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(3, 0) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(3, 1) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(3, 2) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(3, 3) == Player::red);
    REQUIRE(connect_four_game.GetPlayer(3, 4) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(3, 5) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(3, 6) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(4, 0) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(4, 1) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(4, 2) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(4, 3) == Player::red);
    REQUIRE(connect_four_game.GetPlayer(4, 4) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(4, 5) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(4, 6) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(5, 0) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(5, 1) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(5, 2) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(5, 3) == Player::red);
    REQUIRE(connect_four_game.GetPlayer(5, 4) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(5, 5) == Player::none);
    REQUIRE(connect_four_game.GetPlayer(5, 6) == Player::none);
}

TEST_CASE("Top Row returns the first empty row", "[single-file]")
{
    ConnectFourGame connect_four_game;

    int top_row = connect_four_game.GetTopRow(1);
    REQUIRE(top_row == 6);

    connect_four_game.Move(1);

    top_row = connect_four_game.GetTopRow(1);
    REQUIRE(top_row == 5);
}

TEST_CASE("Vertical Win Red", "[single-file]")
{
    ConnectFourGame connect_four_game;

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);

    Player winner = connect_four_game.Move(1);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(5, 1) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(5, 2) == Player::blue);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(1);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(4, 1) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(4, 2) == Player::blue);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(1);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(3, 1) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(3, 2) == Player::blue);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(1);
    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(2, 1) == Player::red);
    REQUIRE(winner == Player::red);
}

TEST_CASE("Vertical Win Blue", "[single-file]")
{
    ConnectFourGame connect_four_game;

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);

    Player winner = connect_four_game.Move(1);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(5, 1) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(5, 2) == Player::blue);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(1);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(4, 1) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(4, 2) == Player::blue);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(1);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(3, 1) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(3, 2) == Player::blue);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(3);
    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::blue);
    REQUIRE(connect_four_game.GetPlayer(5, 3) == Player::red);
    REQUIRE(winner == Player::none);

    winner = connect_four_game.Move(2);

    REQUIRE(connect_four_game.GetCurrentPlayer() == Player::red);
    REQUIRE(connect_four_game.GetPlayer(2, 2) == Player::blue);
    REQUIRE(winner == Player::blue);
}

TEST_CASE("Horizontal Win Red", "[single-file]")
{
    ConnectFourGame connect_four_game;

    connect_four_game.Move(0);
    connect_four_game.Move(6);
    connect_four_game.Move(1);
    connect_four_game.Move(6);
    connect_four_game.Move(2);
    connect_four_game.Move(6);
    Player winner = connect_four_game.Move(3);

    REQUIRE(winner == Player::red);
}

TEST_CASE("Horizontal Win Blue", "[single-file]")
{
    ConnectFourGame connect_four_game;

    connect_four_game.Move(0);
    connect_four_game.Move(6);
    connect_four_game.Move(0);
    connect_four_game.Move(5);
    connect_four_game.Move(0);
    connect_four_game.Move(4);
    connect_four_game.Move(1);
    Player winner = connect_four_game.Move(3);

    REQUIRE(winner == Player::blue);
}

TEST_CASE("Diagonal Win Red", "[single-file]")
{
    ConnectFourGame connect_four_game;

    connect_four_game.Move(0);
    connect_four_game.Move(1);
    connect_four_game.Move(1);
    connect_four_game.Move(2);
    connect_four_game.Move(3);
    connect_four_game.Move(2);
    connect_four_game.Move(2);
    connect_four_game.Move(3);
    connect_four_game.Move(6);
    connect_four_game.Move(3);
    Player winner = connect_four_game.Move(3);

    REQUIRE(winner == Player::red);
}

TEST_CASE("Anti-Diagonal Win Red", "[single-file]")
{
    ConnectFourGame connect_four_game;

    connect_four_game.Move(3);
    connect_four_game.Move(2);
    connect_four_game.Move(2);
    connect_four_game.Move(1);
    connect_four_game.Move(0);
    connect_four_game.Move(1);
    connect_four_game.Move(1);
    connect_four_game.Move(0);
    connect_four_game.Move(6);
    connect_four_game.Move(0);

    Player winner = connect_four_game.Move(0);
    connect_four_game.PrintGameState();

    REQUIRE(winner == Player::red);
}
