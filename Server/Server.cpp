#include <iostream>
#include "src/database/footballer.h"
#include "src/database/database.h"
#include "gtest/gtest.h"


int main(int argc, char **argv) {
    // Testing implementation
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    /*
    // Create a vector of strings
    std::vector<std::string> words = {"Real Madrid", "Juventus", "M.United", "All_Mossar", "Sporting"};
    footballer cris("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                    words, false, true, true, true);

    footballer crisj("Cristiano", "Junior", 2010, 02, "Portugal",
                    words, false, false, false, false);

    database db;
    db.load();
    db.addFootballer(cris);
    db.addFootballer(crisj);
    db.print();

    std::cout << db.searchParams(parameters::Name, (std::string )"Bruno") << std::endl;
    std::cout << db.searchParams(parameters::WorldCupWinner, true) << std::endl;

    footballer messi;
    if (db.searchFootballer("Lionel", "Messi"))
        messi = db.getFootballer("Lionel", "Messi");

    messi.print();
    */


    return 0;
}
