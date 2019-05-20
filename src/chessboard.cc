#include "chessboard.hh"

opt_piece_t Chessboard::operator[](const Position& position) const
{
    int index = position.index_get();
    for(int i = 0; i < 12; i++)
    {
        if(board_pieces[i][index])
        {
            if(i % 2 == 0)
                return std::make_pair((PieceType) (i / 2), Color::WHITE);
            return std::make_pair((PieceType) ((i + 1)/ 2), Color::BLACK);
        }
    }
    return std::nullopt;
}
