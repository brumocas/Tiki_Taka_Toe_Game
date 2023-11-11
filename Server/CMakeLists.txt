cmake_minimum_required(VERSION 3.26)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server
        Server.cpp
        System/database/database.cpp
        System/database/database.h
        System/database/footballer.cpp
        System/database/footballer.h
        System/communication/communication.cpp
        System/communication/communication.h
        System/gamelogic/board.cpp
        System/gamelogic/board.h
        System/gamelogic/game.cpp
        System/gamelogic/game.h
        System/game/gamerunner.cpp
        System/game/gamerunner.h
        System/player/player.cpp
        System/player/player.h
        SystemTests/Test.cpp
        System/database/parameters.h
)
