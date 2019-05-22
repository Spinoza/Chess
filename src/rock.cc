#include <iostream>

#include "chessboard.hh"

std::bitset<64> Chessboard::moveRockN(std::bitset<64> position) const
{
    return position;
}

std::bitset<64> Chessboard::moveRockE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);
    std::bitset<64> pawn = std::bitset<64>(0x1200100000000000); // Will be removed

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position >> 1;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = currentPos >> 1;
        valid = currentPos & borders;
        std::cout << "valid " << valid << "\n";
    }

    std::cout << trace << "\n";

    pawn = trace & pawn;

    currentPos = pawn >> 1;
    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid >> 1;
        valid = currentPos & borders;
        std::cout << "valid " << valid << "\n";
    }

    std::cout << otherTrace << "\n";

    return position;
}

std::bitset<64> Chessboard::moveRockS(std::bitset<64> position) const
{
    return position;
}

std::bitset<64> Chessboard::moveRockW(std::bitset<64> position) const
{
    return position;
}
