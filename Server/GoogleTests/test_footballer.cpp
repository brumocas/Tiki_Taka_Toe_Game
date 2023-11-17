//
// Created by bruno on 17-11-2023.
//
#include "gtest/gtest.h"
#include "../src/database/footballer.h"

TEST(create_footballer, Normal){
    std::vector<std::string> teams = {"Real Madrid"};
    footballer f("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                teams, false, true, true, true);
    ASSERT_EQ("Cristiano", f.getName());
    ASSERT_EQ("Ronaldo", f.getSurname());
    ASSERT_EQ(2, f.getBirthMonth());
    ASSERT_EQ(1985, f.getBirthYear());
    ASSERT_EQ("Portugal", f.getNationality());
    // TODO: blah blah blah
}
