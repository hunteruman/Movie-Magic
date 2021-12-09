#include "Database.h"

void Database::addEdge(string movie, string person, string role) {
    Movies[movie].push_back(pair<string,string>(person,role));
    People[person].push_back(pair<string,string>(movie,role));
}

vector<string> Database::bfs(string person1, string person2) {
    vector<string> out; // movie list

    // deciding shorter start list for optimisation purposes
    string from;
    string to;
    if (People[person1].size() > People[person2].size())
    {
        from = person2;
        to = person1;
    }
    else
    {
        from = person1;
        to = person2;
    }

    // breadth-first search
    string currMovie;
    for (int i = 0; i < People[from].size(); i++)
    {
        currMovie = People[from][i].first;
        for (int j = 0; j < Movies[currMovie].size(); j++)
        {
            if (Movies[currMovie][j].first == to)
            {
                out.push_back(currMovie);
                break;
            }
        }
    }


    return out;
}

vector<string> Database::listCompare(string person1, string person2) {
    vector<string> out;


    return out;
}
