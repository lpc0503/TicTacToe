cmake_minimum_required(VERSION 3.23)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe
        main.cpp
        Board.cpp Entity.h Instruction.h UpdateData.h Game.cpp Game.h PlayerInstruction.cpp PlayerInstruction.h Player.cpp Player.h Exception.h Exception.cpp App.cpp App.h)
