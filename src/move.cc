#include "move.hh"

std::bitset<64> Chessboard::diag()
{

}

std::bitset<64> Chessboard::diag1()
{

}

std::bitset<64> Chessboard::straight()
{

}

std::bitset<64> Chessboard::straight1()
{

}

std::bitset<64> Chessboard::straight2()
{

}

std::bitset<64> Chessboard::L()
{

}

std::bitset<64> Chessboard::generateMove(PieceType P, int pos) const
{
    switch(P)
    {
        case KING :
            std::bitset<64> result = diag1();
            return (result &= straight1());
            break;
        case QUEEN :
            std::bitset<64> result = diag();
            return (result &= straight());
        case ROOK :
            return straight();
        case BISHOP :
            return diag();
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
}
