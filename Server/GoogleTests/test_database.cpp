//
// Created by bruno on 16-11-2023.
//

#include "gtest/gtest.h"
#include "../src/database/database.h"

TEST(load_database, notNull){
    // Load database with 3 players
    database db;
    db.load();
    ASSERT_EQ(3, db.size());
}
