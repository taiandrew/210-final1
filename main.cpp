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
void print_airports(const map<string, int>& airportCounts);

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
        stringstream ss(line);
        string orig, dest;
        getline(ss, orig, ' ');
        cout << orig << endl;
        getline(ss, dest);
        cout << dest << endl;

        airportCounts[orig]++;
        airportCounts[dest]++;
    }
    inFile.close();

    // Print all airport counts
    print_airports(airportCounts);

    return 0;
}

// Functions
void print_airports(const map<string, int>& airportCounts) {
    cout << "All airport traffic counts: " << endl;
    for (const auto& pair: airportCounts) {
        cout << pair.first;
        cout << pair.second << endl;
    }
}