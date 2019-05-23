#include "chessboard-interface.hh"
#include "chessboard.hh"
#include "listener.hh"
#include "pgn-move.hh"
#include "pgn-parser.hh"
#include "position.hh"
#include "report-type.hh"

#include <iostream> 
#include <string> 
#include <vector>


void test_checkB1()
{
    Chessboard board{};

    //b k
    board.board_pieces[1] = std::bitset<64>(0x800);

    //w rock
    board.board_pieces[4] = std::bitset<64>(0x80000000000);
    //w bishop
    board.board_pieces[6] = std::bitset<64>(0x20000000);
    //w knight
    board.board_pieces[8] = std::bitset<64>(0x0);
    //w pawn
    board.board_pieces[10] = std::bitset<64>(0x0);

    std::cout << board.isCheckB() << "\n";
}
