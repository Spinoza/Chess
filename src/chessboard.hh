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
            //k
            board_pieces[0] = std::bitset<64>(0x8);
            board_pieces[1] = std::bitset<64>(0x800000000000000);
            //q
            board_pieces[2] = std::bitset<64>(0x10);
            board_pieces[3] = std::bitset<64>(0x1000000000000000);
            //r
            board_pieces[4] = std::bitset<64>(0x81);
            board_pieces[5] = std::bitset<64>(0x8100000000000000);
            //b
            board_pieces[6] = std::bitset<64>(0x24);
            board_pieces[7] = std::bitset<64>(0x2400000000000000);
            //kg
            board_pieces[8] = std::bitset<64>(0x42);
            board_pieces[9] = std::bitset<64>(0x4200000000000000);
            //p
            board_pieces[10] = std::bitset<64>(0xff00);
            board_pieces[11] = std::bitset<64>(0xff000000000000);
        }

        std::bitset<64> moveRock(std::bitset<64> position, Color color) const;
        std::bitset<64> moveRockN(std::bitset<64> position) const;
        std::bitset<64> moveRockE(std::bitset<64> position) const;
        std::bitset<64> moveRockS(std::bitset<64> position) const;
        std::bitset<64> moveRockW(std::bitset<64> position) const;

        std::bitset<64> moveKnight(std::bitset<64> position, Color color) const;
        std::bitset<64> moveKnightNElow(std::bitset<64> position) const;
        std::bitset<64> moveKnightNEhigh(std::bitset<64> position) const;
        std::bitset<64> moveKnightSElow(std::bitset<64> position) const;
        std::bitset<64> moveKnightSEhigh(std::bitset<64> position) const;
        std::bitset<64> moveKnightSWlow(std::bitset<64> position) const;
        std::bitset<64> moveKnightSWhigh(std::bitset<64> position) const;
        std::bitset<64> moveKnightNWlow(std::bitset<64> position) const;
        std::bitset<64> moveKnightNWhigh(std::bitset<64> position) const;

        std::bitset<64> moveBishop(std::bitset<64> position, Color color) const;
        std::bitset<64> moveBishopNE(std::bitset<64> position) const;
        std::bitset<64> moveBishopNW(std::bitset<64> position) const;
        std::bitset<64> moveBishopSE(std::bitset<64> position) const;
        std::bitset<64> moveBishopSW(std::bitset<64> position) const;

        std::bitset<64> moveQueen(std::bitset<64> position, Color color) const;

        std::bitset<64> moveKing(std::bitset<64> position, Color color) const;
        std::bitset<64> moveKingN(std::bitset<64> position) const;
        std::bitset<64> moveKingNE(std::bitset<64> position) const;
        std::bitset<64> moveKingE(std::bitset<64> position) const;
        std::bitset<64> moveKingSE(std::bitset<64> position) const;
        std::bitset<64> moveKingS(std::bitset<64> position) const;
        std::bitset<64> moveKingSW(std::bitset<64> position) const;
        std::bitset<64> moveKingW(std::bitset<64> position) const;
        std::bitset<64> moveKingNW(std::bitset<64> position) const;

        std::bitset<64> movePawn(std::bitset<64> position, Color color) const;
        std::bitset<64> movePawnForward(std::bitset<64> position, Color color) const;
        std::bitset<64> movePawnForward2(std::bitset<64> position, Color color) const;
        std::bitset<64> movePawnDiag(std::bitset<64> position, Color color) const;

        bool isCheck(board::Color color) const;

        std::array< std::bitset<64> , 12> board_pieces;
        opt_piece_t  operator[](const Position& position) const;
        std::bitset<64> full_board() const;
        std::bitset<64> white_board() const;
        std::bitset<64> black_board() const;
};
