//
// Created by Hunter Uman on 12/8/21.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <Database.h>

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
                    catch (const std::out_of_range& e)
                    {
                        cout << line << endl;
                    }
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
                movieDatabase.addEgde(combined, a, "Actor");
            for (auto &d : directors)
                movieDatabase.addEgde(combined, d, "Director");
            for (auto &w : writers)
                movieDatabase.addEgde(combined, w, "Writer");
        }
    }
    fin.close();
    return 0;
}




