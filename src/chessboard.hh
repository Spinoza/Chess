#pragma once

#include <optional>

#include "color.hh"
#include "piece-type.hh"
#include "position.hh"

namespace board
{
    class Chessboard
    {
    public:
        using side_piece_t = std::pair<PieceType, Color>;
        using opt_piece_t = std::optional<side_piece_t>;

    };
}
