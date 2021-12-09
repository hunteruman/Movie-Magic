#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Database.h"

using namespace std;

int main() {

    /* this is test code for the inputs/outputs / how you should use the class :)

    Database myDatabase;
    myDatabase.addEdge("movie","person1","role");
    myDatabase.addEdge("movie","person2","role");
    myDatabase.addEdge("movie2","person1","role");

    vector<string> print = myDatabase.bfs("person1", "person2");
    for (int i = 0; i < print.size(); i++)
    {
        cout << print[i] << endl;
    }

    */

    string fileName;
    cout << "Choose an input file to load: " << endl;
    cin >> fileName;

    string line;

    ifstream file(fileName); // basic file input stuff
    if (file.is_open()){     // will be replaced by function when I make one
        while (getline(file,line)){

            istringstream stream(line);

            string token;

            getline(stream,token, ' ');

        }
    }
    file.close();

    return 0;
}



