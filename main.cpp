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
void print_busiest(const map<int, vector<string>>& airportBusiest);

// Main
int main() {

    // Open file + read raw data
    map<string, int> airportCounts;
    ifstream inFile(FILENAME);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    // Edit out C+P code
    string orig, dest;
    while (inFile >> orig >> dest) {
        airportCounts[orig]++;
        airportCounts[dest]++;
    }
    inFile.close();

    // Create a map to sort by busiest airports
    map<int, vector<string>> airportBusiest;
    for (const auto& pair : airportCounts) {
        airportBusiest[pair.second].push_back(pair.first);
    }

    // Print various
    print_airports(airportCounts);
    print_busiest(airportBusiest);



    return 0;
}

// Functions
void print_airports(const map<string, int>& airportCounts) {
    cout << "All airport traffic counts: " << endl;
    for (const auto& pair: airportCounts) {
        cout << pair.first << " " << pair.second << endl;
        cout << endl;
    }
}

void print_busiest(const map<int, vector<string>>& airportBusiest) {
    // C+P from EC2; prints highest by key
    auto last_it = --airportBusiest.end();
    cout << "Busiest airport(s) with count " << last_it->first << ":" << endl;
    for (const string& airportCode : last_it->second) {
        cout << airportCode << endl;
    }
    cout << endl;
}