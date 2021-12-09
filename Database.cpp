#include "Database.h"

void Database::addEdge(string movie, string person, string role) {
    Movies[movie].push_back(pair<string,string>(person,role));
    People[person].push_back(pair<string,string>(movie,role));
}
