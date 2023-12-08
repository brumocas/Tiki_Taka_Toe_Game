cmake_minimum_required(VERSION 3.26)
project(Server)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

add_executable(Server
        Main.cpp
        src/database/database.cpp
        src/database/database.h
        src/database/footballer.cpp
        src/database/footballer.h
        src/communication/communication.cpp
        src/communication/communication.h
        src/gamelogic/board.cpp
        src/gamelogic/board.h
        src/gamelogic/game.cpp
        src/gamelogic/game.h
        src/player/player.cpp
        src/player/player.h
        src/database/parameters.h
        GoogleTests/test_database.cpp
        GoogleTests/test_database.cpp
        GoogleTests/test_footballer.cpp
        GoogleTests/test_board.cpp
        src/gamelogic/gameRunner.cpp
        src/gamelogic/gameRunner.h
        GoogleTests/test_game.cpp
        src/communication/server.cpp
        src/communication/server.h
)
target_link_libraries(Server ${GTEST_LIBRARIES})
