#include <iostream>
#include "chessboard.hh"

std::bitset<64> Chessboard::movePawnForward(std::bitset<64> position, Color color) const
{
    std::bitset<64> nextMove;

    if (color == Color::WHITE)
    {
        nextMove = position << 8;
    }
    else
    {
        nextMove = position >> 8;
    }

    return nextMove & ~full_board();
}

std::bitset<64> Chessboard::movePawnForward2(std::bitset<64> position, Color color) const
{
    std::bitset<64> initialPos;
    std::bitset<64> validInitialPos;
    std::bitset<64> nextMove;

    if (color == Color::WHITE)
    {
        initialPos = std::bitset<64>(0xff00);
        validInitialPos = position & initialPos;
        nextMove = validInitialPos << 16;
    }
    else
    {
        initialPos = std::bitset<64>(0xff000000000000);
        validInitialPos = position & initialPos;
        nextMove = validInitialPos >> 16;
    }

    return nextMove & ~full_board();
}

std::bitset<64> Chessboard::movePawnDiag(std::bitset<64> position, Color color) const
{
    std::bitset<64> nextMove;

    if (color == Color::WHITE)
    {
        nextMove = position << 7;
        nextMove |= position << 9;
        nextMove &= black_board();
    }
    else
    {
        nextMove = position >> 7;
        nextMove |= position >> 9;
        nextMove &= white_board();
    }

    return nextMove;
}

std::bitset<64> Chessboard::movePawn(std::bitset<64> position, Color color) const
{
    std::bitset<64> pawn = movePawnForward(position, color);

    pawn |= movePawnForward2(position, color);
    pawn |= movePawnDiag(position, color);

    return pawn;
}
