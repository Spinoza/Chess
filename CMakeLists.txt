cmake_minimum_required(VERSION 3.0)

project(Chess LANGUAGES CXX)

add_compile_options(-g -Wall -Wextra -Werror -pedantic -std=c++17
    -D_DEFAULT_SOURCE)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/
)

##LIBRARIES
##add_library(linked_list ${CMAKE_SOURCE_DIR}/src/utils/linked_list.c)
##EXECUTABLES

add_executable(Chess src/main.cc src/pgn-exception.cc src/pgn-move.cc src/pgn-parser.cc src/uci.cc src/chessboard.cc)
