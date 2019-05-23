#include <iostream>
#include "chessboard.hh"

std::bitset<64> Chessboard::moveBishopNE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position << 7;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = valid << 7;
        valid = currentPos & borders;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece << 7;

    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid << 7;
        valid = currentPos & borders;
    }

    return trace ^ otherTrace;

}

std::bitset<64> Chessboard::moveBishopSE(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position >> 9;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = valid >> 9;
        valid = currentPos & borders;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece >> 9;

    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid >> 9;
        valid = currentPos & borders;
    }

    return trace ^ otherTrace;
}

std::bitset<64> Chessboard::moveBishopSW(std::bitset<64> position) const
{
    std::bitset<64> borders = std::bitset<64>(0xfefefefefefefefe);
    std::bitset<64> otherPiece = full_board();

    std::bitset<64> trace (0x00);
    std::bitset<64> otherTrace (0x00);

    std::bitset<64> currentPos = position >> 7;
    std::bitset<64> valid = currentPos & borders;

    while(valid != 0)
    {
        trace |= valid;
        currentPos = valid >> 7;
        valid = currentPos & borders;
    }

    otherPiece = trace & otherPiece;
    currentPos = otherPiece >> 7;

    valid = currentPos & borders;

    while(valid != 0)
    {
        otherTrace |= valid;
        currentPos = valid >> 7;
        valid = currentPos & borders;
    }

    return trace ^ otherTrace;
}

std::bitset<64> Chessboard::moveBishopNW(std::bitset<64> position) const
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

std::bitset<64> Chessboard::moveBishop(std::bitset<64> position, Color color) const
{
    std::bitset<64> bishop = moveBishopNE(position);

    bishop |= moveBishopSE(position);
    bishop |= moveBishopSW(position);
    bishop |= moveBishopNW(position);

    if (color == Color::WHITE)
        return bishop & ~white_board();
    else
        return bishop & ~black_board();

    return bishop;
}
