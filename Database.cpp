#include "Database.h"

void Database::addEdge(string movie, string person, string role) {
    Movies[movie].push_back(pair<string,string>(person,role));
    People[person].push_back(pair<string,string>(movie,role));
}

vector<string> Database::dfs(string person1, string person2) {
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

    // depth-first search
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

vector<string> Database::sortedListCompare(string person1, string person2) {
    vector<string> out;

    vector<string> p1; // person1's movies
    vector<string> p2; // person2's movies

    for (int i = 0; i < People[person1].size(); i++)
        p1.push_back(People[person1][i].first);
    for (int i = 0; i < People[person2].size(); i++)
        p2.push_back(People[person2][i].first);

    sort(p1.begin(),p1.end()); // nlogn time
    sort(p2.begin(),p2.end()); // defines complexity for this search

    int i = 0;
    int j = 0;

    // searching two sorted lists for commonalities
    while((i < p1.size()) && (j < p2.size()))
    {
        if (p1[i] == p2[j])
        {
            out.push_back(p1[i]);
            i++;
            j++;
        }
        else if (p1[i] < p2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return out;
}

vector<string> Database::unsortedListCompare(string person1, string person2) {
    vector<string> out;

    unordered_map<string,string> p1; // person1's movies

    for (int i = 0; i < People[person1].size(); i++)
    {
        p1[People[person1][i].first] = "found";
    }
    for (int i = 0; i < People[person2].size(); i++)
    {
        if (p1[People[person2][i].first] == "found")
            out.push_back(People[person2][i].first);
    }

    return out;
}

void Database::altAddEdge(string movie, string person, string role) {
    AltMovies[movie][role].push_back(person);
    AltPeople[person][role].push_back(movie);
}

vector<string> Database::altDfs(string person1, string person2) {
    vector<string> out; // movie list

    // depth-first search
    string currMovie;
    bool leave;
    // iterates through roles
    for (auto it1 = AltPeople[person1].begin(); it1 != AltPeople[person1].end(); ++it1)
    {
        // iterates through movies in that role
        for (int i = 0; i < it1->second.size(); i++)
        {
            currMovie = it1->second[i]; // movie node
            leave = false;
            // movie node role iteration
            for (auto it2 = AltMovies[currMovie].begin(); it2 != AltMovies[currMovie].end(); ++it2)
            {
                for (int j = 0; j < it2->second.size(); j++)
                {
                    if (it2->second[j] == person2)
                    {
                        out.push_back(currMovie);
                        leave = true;
                        break;
                    }
                }
                if (leave)
                    break;
            }
        }
    }


    return out;
}

vector<string> Database::altSortedListCompare(string person1, string person2) {
    vector<string> out;

    vector<string> p1; // person1's movies
    vector<string> p2; // person2's movies

    // iterating through roles
    for (auto it = AltPeople[person1].begin(); it != AltPeople[person1].end(); ++it)
    {
        // iterates through movies in that role
        for (int i = 0; i < it->second.size(); i++)
        {
            p1.push_back(it->second[i]);
        }
    }
    // iterating through roles
    for (auto it = AltPeople[person2].begin(); it != AltPeople[person2].end(); ++it)
    {
        // iterates through movies in that role
        for (int i = 0; i < it->second.size(); i++)
        {
            p2.push_back(it->second[i]);
        }
    }

    sort(p1.begin(),p1.end());  // nlogn time
    sort(p2.begin(),p2.end());  // doesnt strictly define complexity
                                // as previous list formation was a double for loop

    int i = 0;
    int j = 0;

    // searching two sorted lists for commonalities
    while((i < p1.size()) && (j < p2.size()))
    {
        if (p1[i] == p2[j])
        {
            out.push_back(p1[i]);
            i++;
            j++;
        }
        else if (p1[i] < p2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return out;
}

vector<string> Database::altUnsortedListCompare(string person1, string person2) {
    vector<string> out;

    unordered_map<string,string> p1; // person1's movies

    for (auto it = AltPeople[person1].begin(); it != AltPeople[person1].end(); ++it)
    {
        // iterates through movies in that role
        for (int i = 0; i < it->second.size(); i++)
        {
            p1[it->second[i]] = "found";
        }
    }
    for (auto it = AltPeople[person2].begin(); it != AltPeople[person2].end(); ++it)
    {
        // iterates through movies in that role
        for (int i = 0; i < it->second.size(); i++)
        {
            if (p1[it->second[i]] == "found")
                out.push_back(it->second[i]);
        }
    }

    return out;
}
