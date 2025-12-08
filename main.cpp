// COMSC 210 | Final 1 | 8 Dec 2025
// IDE: VS Code

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// Constants
const string FILENAME = "/Users/andrewtai/Desktop/COMSC_210/final1/210-final-1-FA25.txt";

// Fn prototypes

// Main
int main() {

    // Open file + read raw data
    map<string, int> airportCounts;
    ifstream inFile(FILENAME);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    // Below c&p from EC2
    string line;
    while (getline(inFile, line)) {
        // Read line and parse into parts (addapted from stackoverflow)
        stringstream ss(line);
        string nameStr, ratingStr;
        getline(ss, nameStr, ' ');
        getline(ss, ratingStr);
        int ratingInt = stoi(ratingStr);

        movies[nameStr].push_back(ratingInt);
        
    }
    inFile.close();

    return 0;
}