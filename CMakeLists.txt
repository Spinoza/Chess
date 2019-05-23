cmake_minimum_required(VERSION 3.0)

project(Chess LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-lboost_program_options")
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

add_compile_options(-g -Wall -Wextra -Werror -pedantic -std=c++17
    -D_DEFAULT_SOURCE)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/
)

##LIBRARIES
##add_library(linked_list ${CMAKE_SOURCE_DIR}/src/utils/linked_list.c)
##EXECUTABLES

add_executable(Chess src/main.cc src/pgn-exception.cc src/pgn-move.cc src/pgn-parser.cc src/uci.cc src/chessboard.cc src/move.cc src/rock.cc src/bishop.cc src/knight.cc src/pawn.cc src/queen.cc src/king.cc src/rules.cc src/test_rules.cc)
TARGET_LINK_LIBRARIES(Chess ${Boost_LIBRARIES})
