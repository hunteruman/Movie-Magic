#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Database.h"

using namespace std;

int main() {

    /* this is test code for the inputs / how you should define the class :)

    Database myDatabase;
    //myDatabase.addEdge("movie","person","role");

    */

    // okay this time the comment should be on my branch
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

int test(int x)
{
    return x;
}



