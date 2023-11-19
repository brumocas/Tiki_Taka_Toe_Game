//
// Created by bruno on 17-11-2023.
//
#include "gtest/gtest.h"
#include "../src/database/footballer.h"

TEST(create_footballer, Normal){
    std::vector<std::string> teams = {"RealMadrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                teams, false, true, true, true);

    ASSERT_EQ("Cristiano", f.getName());
    ASSERT_EQ("Ronaldo", f.getSurname());
    ASSERT_EQ(2, f.getBirthMonth());
    ASSERT_EQ(1985, f.getBirthYear());
    ASSERT_EQ("Portugal", f.getNationality());
    ASSERT_EQ("RealMadrid", f.getCareerTeams()[0]);
    ASSERT_EQ(false, f.isWorldCupWinner());
    ASSERT_EQ(true, f.isChampionsLeagueWinner());
    ASSERT_EQ(true, f.isBallonDorWinner());
    ASSERT_EQ(true, f.isEuropeanWinner());
}

TEST(create_footballer, null){
    footballer f;
    ASSERT_EQ("", f.getName());
    ASSERT_EQ("", f.getSurname());
    ASSERT_EQ(-1, f.getBirthMonth());
    ASSERT_EQ(-1, f.getBirthYear());
    ASSERT_EQ("", f.getNationality());
    ASSERT_EQ(false, f.isWorldCupWinner());
    ASSERT_EQ(false, f.isChampionsLeagueWinner());
    ASSERT_EQ(false, f.isBallonDorWinner());
    ASSERT_EQ(false, f.isEuropeanWinner());
}

