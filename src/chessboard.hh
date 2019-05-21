#pragma once

#include <optional>
#include <bitset>
#include "color.hh"
#include "chessboard-interface.hh"

using namespace board;
using side_piece_t = std::pair<PieceType, Color>;
using opt_piece_t = std::optional<side_piece_t>;

class Chessboard : ChessboardInterface
{
    public :
        //king, queen, rook, bishop, knight, pawn 6 * 2
        //board_pieces[i % 2 == 0] --> color is white
        std::array< std::bitset<64> , 12> board_pieces;
        opt_piece_t  operator[](const Position& position) const;
        std::bitset<64> full_board() const;
        std::bitset<64> white_board() const;
        std::bitset<64> black_board() const;
};
