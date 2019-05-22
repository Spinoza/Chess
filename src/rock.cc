#include <iostream>
#include "chessboard.hh"

std::bitset<64> Chessboard::moveRockN(std::bitset<64> position) const
{
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position << 8;

    while(currentPos != 0)
    {
        trace |= currentPos;
        currentPos = currentPos << 8;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece << 8;

    while(currentPos != 0)
    {
        otherTrace |= currentPos;
        currentPos = currentPos << 8;
    }

    return trace ^ otherTrace;
}

std::bitset<64> Chessboard::moveRockE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position >> 1;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = valid >> 1;
        valid = currentPos & borders;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece >> 1;

    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid >> 1;
        valid = currentPos & borders;
    }

    return trace ^ otherTrace;
}

std::bitset<64> Chessboard::moveRockS(std::bitset<64> position) const
{
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position >> 8;

    while(currentPos != 0)
    {
        trace |= currentPos;
        currentPos = currentPos >> 8;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece >> 8;

    while(currentPos != 0)
    {
        otherTrace |= currentPos;
        currentPos = currentPos >> 8;
    }

    return trace ^ otherTrace;

}

std::bitset<64> Chessboard::moveRockW(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position << 1;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = valid << 1;
        valid = currentPos & borders;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece << 1;

    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid << 1;
        valid = currentPos & borders;
    }

    return trace ^ otherTrace;
}
