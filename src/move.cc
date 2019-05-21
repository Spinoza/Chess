#include "move.hh"
/*
#define A_C std::bitset<64>(0x7f7f7f7f7f7f7f7f)
#define H_C std::bitset<64>(0xfefefefefefefefe)
#define 1_L std::bitset<64>(0xffffffffffffff00)
#define 8_L std::bitset<64>(0xffffffffffffff)
*/

std::bitset<64> Chessboard::rayTracing(std::bitset<64> test, int dir) const
{
    test = test;
    dir = dir;
    std::bitset<64> position  = std::bitset<64>(0x8000000000000000);
    std::bitset<64> findIndex = position;
    std::bitset<64> borders;
    std::bitset<64> pawn = std::bitset<64>(0x1200100000000000);
    if (dir == 1)
        borders = std::bitset<64>(0x7f7f7f7f7f7f7f7f);
    else if (dir == -1)
        borders = std::bitset<64>(0xfefefefefefefefe);

    std::bitset<64> trace (0x00);
    std::bitset<64> pawnTrace (0x00);

    unsigned index = -1;

    //on peut aussi faire log base 2
    while (findIndex != 0)
    {
        findIndex = findIndex >> 1;
        index++;
    }

    //std::cout << index << "\n";

    std::bitset<64> currentPos = position >> dir;
        std::cout << "curentpos  " << currentPos << "\n";
        std::cout << "borders  " << borders << "\n";
    std::bitset<64> valid = currentPos & borders;
        std::cout << "valid " << valid << "\n";

    while(valid != 0)
    {
        trace |= valid;
        currentPos = currentPos >> dir;
        valid = currentPos & borders;
        std::cout << "valid " << valid << "\n";
    }

    std::cout << trace << "\n";

    pawn = trace & pawn;

    currentPos = pawn >> dir;
    valid = currentPos & borders;

    while(valid != 0)
    {
        pawnTrace |= valid;
        currentPos = valid >> dir;
        valid = currentPos & borders;
        std::cout << "valid " << valid << "\n";
    }

    std::cout << pawnTrace << "\n";

    return findIndex;
}
/*
std::bitset<64> Chessboard::diag(std::bitset<64> position)
{

}

std::bitset<64> Chessboard::diag1(std::bitset<64> position)
{
    //right up diag
    std::bitset<64> t1(position);
    t1 &= H_C; // AND assign
    t1 &= 8_L;
    t1 >> 9;

    //right down diag
    std::bitset<64> t2(position);
    t2 &= H_C;
    t2 &= 1_L;
    t2 >> 9

    //left up diag
    std::bitset<64> t3(position);
    t3 &= A_C;
    t3 &= 8_L;
    t3 >> 7;
    //left down diag
    std::bitset<64> t4(position);
    t4 &= A_C;
    t4 &= 1_L;
    t4 << 7

    t1 |= t3; //OR assign ---> concatenation of the 2 tabs
    t2 |= t4;
    return t1 |= t2;
}

std::bitset<64> Chessboard::straight(std::bitset<64> position)
{

}

std::bitset<64> Chessboard::straight1(std::bitset<64> position)
{
    //up
    std::bitset<64> t1(position);
    t1 &= 8_L;
    t1 << 8; //shift top
    //down
    std::bitset<64> t2(position);
    t2 &= 1_L;
    t2 >> 8;//shift down

    //right
    std::bitset<64> t1(position);
    t3 &= H_C;
    t3 = t3 >> 1;

    //left
    std::bitset<64> t2(position);
    t4 &= A_C;
    t4 = t4 << 1;

    t1 |= t3;
    t1 |= t4;
    return t1 |= t2;
}


std::bitset<64> Chessboard::forward1(std::bitset<64> position, bool color)
{

}

std::bitset<64> Chessboard::forward2(std::bitset<64> position, bool color)
{

}

std::bitset<64> Chessboard::L(std::bitset<64> position)
{

}

std::bitset<64> Chessboard::generateMove(PieceType P, std::bitset<64> position) const
{
    switch(P)
    {
        case KING :
            std::bitset<64> result = diag1(position);
            return (result &= straight1(position));
            break;
        case QUEEN :
            std::bitset<64> result = diag(position);
            return (result &= straight(position));
        case ROOK :
            return straight(position);
        case BISHOP :
            return diag(position);
        case KNIGHT :
            return L();
        default :
        //need to handle the pawn in a different way
        //straight2 for the first moves
        //en passant as well
            return straight1();
    }
}
int numberMoves(const std::bitset<64>& table) const
{
    return table::count();
}*/
