// COMSC 210 | Final 1 | 8 Dec 2025
// IDE: VS Code

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Constants
const string FILENAME = "/Users/andrewtai/Desktop/COMSC_210/210-final1/210-final-1-FA25 test.txt";

// Fn prototypes
void print_airports(const map<string, int>& airportCounts);
void print_busiest(const map<int, vector<string>>& airportBusiest);
void print_range(const map<string, int>& airportCounts, int lower, int upper);

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

    // Create a map to sort by count instead of name
    map<int, vector<string>> airportBusiest;
    for (const auto& pair : airportCounts) {
        airportBusiest[pair.second].push_back(pair.first);
    }

    // Print various
    print_airports(airportCounts);
    print_busiest(airportBusiest);
    print_range(airportCounts, 5, 8);
    print_range(airportCounts, 1, 5);

    return 0;
}

// Functions
void print_airports(const map<string, int>& airportCounts) {
    // Prints all airports + counts by name
    // Arg: airportCounts - map of airport codes to counts

    cout << "All airport traffic counts: " << endl;
    for (const auto& pair: airportCounts) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl;
}

void print_busiest(const map<int, vector<string>>& airportBusiest) {
    // C+P from EC2; prints highest by key
    // Arg: airportBusiest - map of counts to vector of airport codes

    auto last_it = --airportBusiest.end();
    cout << "Busiest airport(s) with count " << last_it->first << ":" << endl;
    for (const string& airportCode : last_it->second) {
        cout << airportCode << endl;
    }
    cout << endl;
}

void print_range(const map<string, int>& airportCounts, int lower, int upper) {
    // Prints airports with counts in [lower, upper]
    // Args: airportCounts - map of airport codes to counts
    //      lower - lower bound (inclusive)
    //      upper - upper bound (inclusive)

    cout << "Airports with traffic in range [" << lower << ", " << upper << "]:" << endl;
    for (const auto& pair : airportCounts) {
        if (pair.second >= lower && pair.second <= upper) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    cout << endl;
}