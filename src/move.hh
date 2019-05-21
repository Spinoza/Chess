#pragma once

#include <bitset>
#include <iostream>
#include "chessboard.hh"

using namespace board;

enum class Move
{
    DIAG,
    DIAG1,

    STRAIGHT,
    STRAIGHT1,
    STRAIGHT2,

    L,
};
