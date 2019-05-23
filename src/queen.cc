#include <iostream>
#include "chessboard.hh"

std::bitset<64> Chessboard::moveQueen(std::bitset<64> position, Color color) const
{
    std::bitset<64> rock = moveRock(position, color);

    rock |= moveBishop(position, color);

    if (color == Color::WHITE)
        return rock & ~white_board();
    else
        return rock & ~black_board();
}
