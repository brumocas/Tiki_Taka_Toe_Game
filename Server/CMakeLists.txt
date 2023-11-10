cmake_minimum_required(VERSION 3.26)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server
        Server.cpp
        database/database.cpp
        database/database.h
        database/footballer.cpp
        database/footballer.h
        communication/communication.cpp
        communication/communication.h
        gamelogic/board.cpp
        gamelogic/board.h
        gamelogic/game.cpp
        gamelogic/game.h
        gamelogic/gamerunner.cpp
        gamelogic/gamerunner.h)
