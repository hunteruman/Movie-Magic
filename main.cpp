#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Database.h"

using namespace std;

vector<string> stringToList(string input)
{
    size_t pos = 0;
    string token;
    vector<string> ans;
    while ((pos = input.find(", ")) != std::string::npos)
    {
        token = input.substr(0, pos);
        ans.push_back(token);
        input.erase(0, pos + 2);
    }
    ans.push_back(input);
    return ans;
}

int main() {

    Database movieDatabase;
    //  Create ifsream object for file
    ifstream fin("IMDB Movies.csv");
    if (fin.good())
    {
        //  Given a good ifstream object we then take each line iteratively
        std::string line;
        std::getline(fin, line);
        while (std::getline(fin, line))
        {
            //  Pass the line to ss object to tokenize based on comma delimeter
            std::istringstream iss(line);
            vector<string> intermediate_data;
            string temp;
            while (getline(iss, temp, ','))
            {
                //  Empty values are given Null to keep dimensions consistent
                if (temp.empty())
                {
                    intermediate_data.emplace_back("Null");
                    continue;
                }
                //  Lists of values are surrounded in quotes so here we check to see if the token is the start of a list
                if (temp.at(0) == '\"')
                {
                    //  Try-catch to eliminate the lines that contain poor formatting
                    try
                    {
                        temp += ',';
                        string token;
                        do
                        {
                            getline(iss, token, ',');
                            token += ',';
                            temp += token;
                        }
                        while (token.at(token.length()-2) != '\"');
                        temp = temp.substr(1, temp.length()-3);
                    }
                    catch (const std::out_of_range& e){}
                }
                intermediate_data.push_back(temp);
                //  Actors is the 13th attribute in the dataset so we can break the loop once we have the actors
                if (intermediate_data.size() == 13)
                    break;
            }
            //  Get string of actors, directors, and writers and push them to vector
            vector<string> actors       = stringToList(intermediate_data[12]);
            vector<string> directors    = stringToList(intermediate_data[8]);
            vector<string> writers      = stringToList(intermediate_data[9]);
            //  Add all to graph
            string title                = intermediate_data[2];
            string year                 = intermediate_data[3];
            string combined             = title + " [" + year + "]";
            for (auto &a : actors)
                movieDatabase.addEdge(combined, a, "Actor");
            for (auto &d : directors)
                movieDatabase.addEdge(combined, d, "Director");
            for (auto &w : writers)
                movieDatabase.addEdge(combined, w, "Writer");
        }
    }
    fin.close();

    string          person1, person2;
    int             algoSelection;
    vector<string>  movies;

    cout << "Move Magic: The movie search engine. By Hunter Uman and Michael Shapiro" << endl << endl;
    while (true)
    {
        cout << "Select search algorithm or exit program: " << endl;
        cout << "1. Depth-first search" << endl;
        cout << "2. Sorted list comparison" << endl;
        cout << "3. Unsorted list comparison" << endl;
        cout << "0. Exit program" << endl;
        cin >> algoSelection;
        if (algoSelection == 0)
            exit(0);
        else if (algoSelection < 0 || algoSelection > 3)
        {
            cout << "Input " << algoSelection << " is not a valid selection. Try again" << endl;
            continue;
        }
        cout << "Input first person to search: ";
        cin.ignore();
        getline(cin, person1);
        cout << "Input second person to search: ";
        getline(cin, person2);
        switch(algoSelection)
        {
            case 1:
                movies = movieDatabase.dfs(person1, person2);
                break;
            case 2:
                movies = movieDatabase.sortedListCompare(person1, person2);
                break;
            case 3:
                movies = movieDatabase.unsortedListCompare(person1, person2);
                break;
        }
        cout << person1 << " and " << person2 << " have worked on " << movies.size() << " movies together: " << endl;
        for (string &movie : movies)
            cout << movie << endl;
        cout << endl;
    }

    return 0;
}




