#pragma once

#include <optional>

#include "color.hh"
#include "piece-type.hh"
#include "position.hh"
#include "chessboard.hh"
#include "chessboard-interface.hh"

namespace board
{
    class ChessboardAdapter : ChessboardInterface
    {
    public:
        using side_piece_t = std::pair<PieceType, Color>;
        using opt_piece_t = std::optional<side_piece_t>;

        Chessboard board;
        
    };
}
