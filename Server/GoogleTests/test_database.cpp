//
// Created by bruno on 16-11-2023.
//

#include "gtest/gtest.h"
#include "../src/database/database.h"


// All tests done in the following DB
std::string path = "../src/database/files/test_database.txt";

TEST(load_database, notNull) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
}

TEST(load_database, Null) {
    database db;
    // Dont load DB
    ASSERT_EQ(0, db.size());
}

TEST(add_footballer, normalPlayer) {
    database db;
    footballer f;
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
}

TEST(delete_footballer, normalPlayer) {
    database db;
    footballer f;
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // Delete one footballer of the DB
    db.deleteFootballer(f);
    ASSERT_EQ(0, db.size());
}

TEST(search_footballer, availablePlayer) {
    database db;
    std::vector<std::string> teams = {"Real_Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    ASSERT_EQ(true, db.searchFootballer("Cristiano", "Ronaldo"));
}

TEST(search_footballer, unavailablePlayer) {
    database db;
    std::vector<std::string> teams = {"Real_Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    ASSERT_EQ(false, db.searchFootballer("Moussa", "Marega"));
}

TEST(get_footballer, availablePlayer) {
    database db;
    std::vector<std::string> teams = {"Real_Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    ASSERT_EQ(f, db.getFootballer("Cristiano", "Ronaldo"));
}

TEST(get_footballer, unavailablePlayer) {
    database db;
    std::vector<std::string> teams = {"Real_Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                 teams, false, true, true, true);
    // Add one footballer to the DB
    db.addFootballer(f);
    ASSERT_EQ(1, db.size());
    // search footballer in the DB
    // create null footballer to compare
    footballer null;
    ASSERT_EQ(null, db.getFootballer("Moussa", "Marega"));
}

TEST(search_Param, availableParamNames) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    ASSERT_EQ(true, db.searchParams(parameters::Name, (std::string) "Lionel"));
    ASSERT_EQ(true, db.searchParams(parameters::Surname, (std::string) "Messi"));
}

TEST(search_Param, availableParamTeams) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    ASSERT_EQ(true, db.searchParams(parameters::CareerTeams, (std::string) "Barcelona"));
    ASSERT_EQ(true, db.searchParams(parameters::CareerTeams, (std::string) "Inter_Miami"));
    ASSERT_EQ(true, db.searchParams(parameters::CareerTeams, (std::string) "PSG"));
    ASSERT_EQ(true, db.searchParams(parameters::CareerTeams, (std::string) "Porto"));
    ASSERT_EQ(true, db.searchParams(parameters::CareerTeams, (std::string) "All_Mossar"));
    ASSERT_EQ(true, db.searchParams(parameters::CareerTeams, (std::string) "Agucadoura"));
}

TEST(search_Param, unavailableParamTeams) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search unavailable param in the DB
    ASSERT_EQ(false, db.searchParams(parameters::CareerTeams, (std::string) "Bayern"));
    ASSERT_EQ(false, db.searchParams(parameters::CareerTeams, (std::string) "Varzim"));
    ASSERT_EQ(false, db.searchParams(parameters::CareerTeams, (std::string) "AC_Milan"));
}

TEST(search_Param, unavailableParamNames) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search unavailable param in the DB
    ASSERT_EQ(false, db.searchParams(parameters::Name, (std::string) "Cristiano"));
    ASSERT_EQ(false, db.searchParams(parameters::Surname, (std::string) "Ronaldo"));
}

TEST(search_Param, availableParamBirth) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    // Search messi age (Year and Month)
    ASSERT_EQ(true, db.searchParams(parameters::BirthMonth, 6));
    ASSERT_EQ(true, db.searchParams(parameters::BirthYear, 1987));
}

TEST(search_Param, unavailableParamBirth) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search unavailable param in the DB
    ASSERT_EQ(false, db.searchParams(parameters::BirthMonth, 1));
    ASSERT_EQ(false, db.searchParams(parameters::BirthYear, 2023));
}


TEST(search_Param, availableParamCups) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search available param in the DB
    ASSERT_EQ(true, db.searchParams(parameters::WorldCupWinner, true));
    ASSERT_EQ(true, db.searchParams(parameters::ChampionsLeagueWinner, true));
    ASSERT_EQ(true, db.searchParams(parameters::BallonDorWinner, true));
}

TEST(search_Param, unavailableParamCups) {
    database db;
    // Load DB with 3 players
    db.load(path);
    ASSERT_EQ(3, db.size());
    // Search unavailable param in the DB
    ASSERT_EQ(true, db.searchParams(parameters::EuropeanWinner, false));
}

TEST(parseLine, example) {
    std::string line = "Lionel, Messi, 1987, 06, Argentina, 1, 1, 1, 0, Barcelona PSG Inter_Miami,";
    database db;
    std::vector<std::string> parsed = db.parseLine(line);
    ASSERT_EQ("Lionel", parsed[0]);
    ASSERT_EQ("Messi", parsed[1]);
    ASSERT_EQ("1987", parsed[2]);
    ASSERT_EQ("06", parsed[3]);
    ASSERT_EQ("Argentina", parsed[4]);
    ASSERT_EQ("1", parsed[5]);
    ASSERT_EQ("1", parsed[6]);
    ASSERT_EQ("1", parsed[7]);
    ASSERT_EQ("0", parsed[8]);
    ASSERT_EQ("Barcelona PSG Inter_Miami", parsed[9]);
}

TEST(parseTeams, example) {
    std::string line = "Barcelona PSG Inter_Miami";
    database db;
    std::vector<std::string> parsed = db.parseTeams(line);
    ASSERT_EQ("Barcelona", parsed[0]);
    ASSERT_EQ("PSG", parsed[1]);
    ASSERT_EQ("Inter_Miami", parsed[2]);
}

TEST(loadTeams, example) {
    database db;
    db.load(path);
    std::vector<std::string> teams = db.getTeams();
    ASSERT_EQ("Barcelona", teams[0]);
    ASSERT_EQ("PSG", teams[1]);
    ASSERT_EQ("Inter_Miami", teams[2]);
    ASSERT_EQ("Agucadoura", teams[3]);
    ASSERT_EQ("Porto", teams[4]);
    ASSERT_EQ("All_Mossar", teams[5]);
}

TEST(loadNations, example) {
    database db;
    db.load(path);
    std::vector<std::string> nations = db.getNations();
    ASSERT_EQ("Argentina", nations[0]);
    ASSERT_EQ("Portugal", nations[1]);
    ASSERT_EQ("Cameroon", nations[2]);
}

TEST(isTeam, positive) {
    database db;
    db.load(path);
    ASSERT_EQ(true, db.isTeam("PSG"));
    ASSERT_EQ(true, db.isTeam("Barcelona"));
    ASSERT_EQ(true, db.isTeam("Porto"));
}

TEST(isTeam, negative) {
    database db;
    db.load(path);
    ASSERT_EQ(false, db.isTeam("Portugal"));
    ASSERT_EQ(false, db.isTeam("Argentina"));
    ASSERT_EQ(false, db.isTeam("Cameroon"));
}


TEST(isNation, positive) {
    database db;
    db.load(path);
    ASSERT_EQ(true, db.isNation("Portugal"));
    ASSERT_EQ(true, db.isNation("Argentina"));
    ASSERT_EQ(true, db.isNation("Cameroon"));
}

TEST(isNation, negative) {
    database db;
    db.load(path);
    ASSERT_EQ(false, db.isNation("Porto"));
    ASSERT_EQ(false, db.isNation("PSG"));
    ASSERT_EQ(false, db.isNation("Barcelona"));
}







