//
// Created by bruno on 18-11-2023.
//
#include "gtest/gtest.h"
#include "../src/gamelogic/game.h"

TEST(load_database, notNull) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
}