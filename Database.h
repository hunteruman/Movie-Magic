#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Database {

    // Adjacency List implementation of Map
    unordered_map<string, vector<pair<string, string>>> Movies;
    unordered_map<string, vector<pair<string, string>>> People;

public:

    // Adjacency List implementation functions
    void addEdge(string movie, string person, string role);
    vector<string> bfs(string person1, string person2); //
    vector<string> listCompare(string person1, string person2);

};
