#include "chessboard.hh"


bool Chessboard::isCheckB(board::Color color) const
{
    int k, k2, q, r, b, kn, p;
    if (color == board::Color::White)
    {
        k = 0;
        k2 = 1;
        q = 3;
        r = 5;
        b = 7;
        kn = 9;
        p = 11;
        color = board::Color::Black;
    }
    else
    {
        k = 1;
        k2 = 0;
        q = 2;
        r = 4;
        b = 6;
        kn = 8;
        p = 10;
        color = board::Color::White;
    }

    std::bitset<64> king = board_pieces[k];

    //generate move of opponent's pieces
    std::bitset<64> threat = moveQueen(board_pieces[q], color);
    threat ^= moveKing(board_pieces[k2], color);
    threat ^= moveRock(board_pieces[r], color);
    threat ^= moveBishop(board_pieces[b], color);
    threat ^= moveKnight(board_pieces[kn], color);
    threat ^= movePawn(board_pieces[p], color);

    if ((king & threat) != 0)
        return false;
    return true;
}


bool Chessboard::isCheckW() const
{
    std::bitset<64> w_k = board_pieces[0];

    //check for w_k, move black piece
    std::bitset<64> b_threat = moveRock(board_pieces[2]);
    b_threat &= moveBishop(board_pieces[4]);
    b_threat &= moveKnight(board_pieces[6]);
    b_threat &= movePawn(board_pieces[8]);
    return true;
}
