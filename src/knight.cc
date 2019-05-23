#include <iostream>
#include "chessboard.hh"

std::bitset<64> Chessboard::moveKnightNElow(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x3f3f3f3f3f3f3f3f);

    std::bitset<64> currentPos = position << 6;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightNEhigh(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);

    std::bitset<64> currentPos = position << 15;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightSElow(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);

    std::bitset<64> currentPos = position >> 10;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightSEhigh(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x3f3f3f3f3f3f3f3f);

    std::bitset<64> currentPos = position >> 17;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightSWlow(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);

    std::bitset<64> currentPos = position >> 15;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightSWhigh(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfcfcfcfcfcfcfcfc);

    std::bitset<64> currentPos = position >> 6;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightNWlow(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfcfcfcfcfcfcfcfc);

    std::bitset<64> currentPos = position << 10;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnightNWhigh(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);

    std::bitset<64> currentPos = position << 17;

    std::bitset<64> valid = currentPos & borders;

    return valid;
}

std::bitset<64> Chessboard::moveKnight(std::bitset<64> position, Color color) const
{
    std::bitset<64> knight = moveKnightNElow(position);

    knight |= moveKnightNEhigh(position);
    knight |= moveKnightSElow(position);
    knight |= moveKnightSEhigh(position);
    knight |= moveKnightSWlow(position);
    knight |= moveKnightSWhigh(position);
    knight |= moveKnightNWlow(position);
    knight |= moveKnightNWhigh(position);

    if (color == Color::WHITE)
        return knight & ~white_board();
    else
        return knight & ~black_board();

    return knight;
}
