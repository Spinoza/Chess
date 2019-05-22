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


std::bitset<64> Chessboard::moveKnightNW(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position << 9;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = valid << 9;
        valid = currentPos & borders;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece << 9;

    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid << 9;
        valid = currentPos & borders;
    }

    return trace ^ otherTrace;
}

std::bitset<64> Chessboard::moveKnight(std::bitset<64> position) const
{
    std::bitset<64> knight = moveKnightNElow(position);

    knight |= moveKnightNEhigh(position);
    knight |= moveKnightSElow(position);
    knight |= moveKnightSEhigh(position);
    knight |= moveKnightSWlow(position);
    knight |= moveKnightSWhigh(position);
    knight |= moveKnightNWlow(position);
    knight |= moveKnightNWhigh(position);

    return knight;
}
