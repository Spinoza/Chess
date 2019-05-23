#include <iostream>
#include "chessboard.hh"

std::bitset<64> Chessboard::moveKingN(std::bitset<64> position) const
{
    std::bitset<64> nextMove = position << 8;

    return nextMove;
}

std::bitset<64> Chessboard::moveKingNE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);

    std::bitset<64> nextMove = position << 7;

    std::bitset<64> valid = nextMove & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKingE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);

    std::bitset<64> nextMove = position >> 1;

    std::bitset<64> valid = nextMove & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKingSE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);

    std::bitset<64> nextMove = position >> 9;

    std::bitset<64> valid = nextMove & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKingS(std::bitset<64> position) const
{
    std::bitset<64> nextMove = position >> 8;

    return nextMove;
}

std::bitset<64> Chessboard::moveKingSW(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);

    std::bitset<64> nextMove = position >> 7;

    std::bitset<64> valid = nextMove & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKingW(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);

    std::bitset<64> nextMove = position << 1;

    std::bitset<64> valid = nextMove & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKingNW(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);

    std::bitset<64> nextMove = position << 9;

    std::bitset<64> valid = nextMove & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKing(std::bitset<64> position, Color color) const
{
    std::bitset<64> king = moveKingN(position);

    king |= moveKingNE(position);
    king |= moveKingE(position);
    king |= moveKingSE(position);
    king |= moveKingS(position);
    king |= moveKingSW(position);
    king |= moveKingW(position);
    king |= moveKingNW(position);

    if (color == Color::WHITE)
        return king & ~white_board();
    else
        return king & ~black_board();

    return king;
}
