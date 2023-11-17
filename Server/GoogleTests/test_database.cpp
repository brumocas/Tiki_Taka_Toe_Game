//
// Created by bruno on 16-11-2023.
//

#include "gtest/gtest.h"
#include "../src/database/database.h"
#include "../src/database/footballer.h"
#include "../src/database/parameters.h"

TEST(load_database, notNull){
    database db;
    // Load DB with 3 players
    db.load();
    ASSERT_EQ(3, db.size());
}

TEST(load_database, Null){
    database db;
    // Dont load DB
    ASSERT_EQ(0, db.size());
}

TEST(add_footballer, normalPlayer){
    database db;
    footballer f;
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
}

TEST(delete_footballer, normalPlayer){
    database db;
    footballer f;
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // Delete one footballer of the DB
    db.deleteFootballer(f);
    ASSERT_EQ(0, db.size());
}

TEST(search_footballer, availablePlayer){
    database db;
    std::vector<std::string> teams = {"Real Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    ASSERT_EQ(true, db.searchFootballer("Cristiano", "Ronaldo"));
}

TEST(search_footballer, unavailablePlayer){
    database db;
    std::vector<std::string> teams = {"Real Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    ASSERT_EQ(false, db.searchFootballer("Moussa", "Marega"));
}

TEST(get_footballer, availablePlayer){
    database db;
    std::vector<std::string> teams = {"Real Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    ASSERT_EQ(f, db.getFootballer("Cristiano", "Ronaldo"));
}

TEST(get_footballer, unavailablePlayer){
    database db;
    std::vector<std::string> teams = {"Real Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    // create null footballer to compare
    footballer null;
    ASSERT_EQ(null,db.getFootballer("Moussa", "Marega"));
}

TEST(search_Param, availableParamNames){
    database db;
    // Load DB with 3 players
    db.load();
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    ASSERT_EQ(true, db.searchParams(parameters::Name, (std::string )"Lionel"));
    ASSERT_EQ(true, db.searchParams(parameters::Surname, (std::string )"Messi"));
}

TEST(search_Param, unavailableParamNames){
    database db;
    // Load DB with 3 players
    db.load();
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    ASSERT_EQ(false, db.searchParams(parameters::Name, (std::string )"Cristiano"));
    ASSERT_EQ(false, db.searchParams(parameters::Surname, (std::string )"Ronaldo"));
}

TEST(search_Param, unavailableParamBirth){
    database db;
    // Load DB with 3 players
    db.load();
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    ASSERT_EQ(true, db.searchParams(parameters::BirthMonth, 6));
    ASSERT_EQ(true, db.searchParams(parameters::BirthYear, 1987));
}








