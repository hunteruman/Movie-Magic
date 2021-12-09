#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Database {

    // Adjacency List implementation of Map
    unordered_map<string, vector<pair<string, string>>> Movies;
    unordered_map<string, vector<pair<string, string>>> People;

    // Alt Adjacency List implementation of Map
    unordered_map<string, unordered_map<string, vector<string>>> AltMovies;
    unordered_map<string, unordered_map<string, vector<string>>> AltPeople;

public:

    // map creation
    void addEdge(string movie, string person, string role);

    // search algorithms
    vector<string> dfs(string person1, string person2);
    vector<string> sortedListCompare(string person1, string person2);
    vector<string> unsortedListCompare(string person1, string person2);

    // alt map creation
    void altAddEdge(string movie, string person, string role);

    // alt search algorithms
    vector<string> altDfs(string person1, string person2);
    vector<string> altSortedListCompare(string person1, string person2);
    vector<string> altUnsortedListCompare(string person1, string person2);

};
