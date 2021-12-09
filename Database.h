#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Database {

    //
    unordered_map<string, vector<pair<string, string>>> Movies;
    unordered_map<string, vector<pair<string, string>>> People;

public:

    void addEdge(string movie, string person, string role);

};
