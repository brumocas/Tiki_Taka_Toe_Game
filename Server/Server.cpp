#include <iostream>
#include "database/footballer.h"
#include "database/database.h"

int main() {

    // Testing implementation

    // Create a vector of strings
    std::vector<std::string> words = {"Real Madrid", "Juventus", "M.United", "All Mossar", "Sporting"};
    footballer cris("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                    words, false, true, true, true);

    footballer crisj("Cristiano", "Junior", 2010, 02, "Portugal",
                    words, false, true, true, true);

    database db;
    db.load();
    db.addFootballer(cris);
    db.addFootballer(crisj);
    db.print();

    std::cout << db.searchFootballer("Cristiano", "Ronaldo");

    //db.print();

    return 0;
}
