//
// Created by Hunter Uman on 12/8/21.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    // temp main just so I can get used to clones, commits, pulls, et cetera
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

    cout << "Hit rate = " << float(hits)/float(count) << endl;

    return 0;
}



