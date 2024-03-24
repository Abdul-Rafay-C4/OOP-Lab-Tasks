#include <iostream>
#include <map>
using namespace std;

int main() {
    // Creating a map of string keys and integer values
    map<string, int> myMap;

    // Inserting elements into the map
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap["orange"] = 7;

    // Accessing elements using keys
    cout << "Number of apples: " << myMap["apple"] << endl;

    // Iterating over the map
    cout << "Map contents:";
    for (auto& pair : myMap) {
        cout << " (" << pair.first << ": " << pair.second << ")";
    }
    cout << endl;

    return 0;
}
