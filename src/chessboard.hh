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
        Chessboard()
        {
            board_pieces[0] = std::bitset<64>(0x8);
            board_pieces[1] = std::bitset<64>(0x800000000000000);
            board_pieces[2] = std::bitset<64>(0x10);
            board_pieces[3] = std::bitset<64>(0x1000000000000000);
            board_pieces[4] = std::bitset<64>(0x81);
            board_pieces[5] = std::bitset<64>(0x8100000000000000);
            board_pieces[6] = std::bitset<64>(0x24);
            board_pieces[7] = std::bitset<64>(0x2400000000000000);
            board_pieces[8] = std::bitset<64>(0x42);
            board_pieces[9] = std::bitset<64>(0x4200000000000000);
            board_pieces[10] = std::bitset<64>(0xff00);
            board_pieces[11] = std::bitset<64>(0xff000000000000);

        }
        std::bitset<64> moveBishopNE(std::bitset<64> position) const;
        std::bitset<64> moveBishopNW(std::bitset<64> position) const;
        std::bitset<64> moveBishopSE(std::bitset<64> position) const;
        std::bitset<64> moveBishopSW(std::bitset<64> position) const;

        std::bitset<64> moveRockN(std::bitset<64> position) const;
        std::bitset<64> moveRockE(std::bitset<64> position) const;
        std::bitset<64> moveRockS(std::bitset<64> position) const;
        std::bitset<64> moveRockW(std::bitset<64> position) const;

        std::array< std::bitset<64> , 12> board_pieces;
        opt_piece_t  operator[](const Position& position) const;
        std::bitset<64> full_board() const;
        std::bitset<64> white_board() const;
        std::bitset<64> black_board() const;
};
