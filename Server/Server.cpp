#include <iostream>
#include "database/footballer.h"
#include "database/database.h"

int main() {

    // Testing implementation

    // Create a vector of strings
    std::vector<std::string> words = {"Real Madrid", "Juventus", "M.United", "All Mossar", "Sporting"};
    footballer cris("Cristiano", "Ronaldo", 1985, 02, "Portugal",
                    words, false, true, true, true);

    //cris.print();

    database db;
    db.addFootballer(cris);
    db.print();

    return 0;
}
