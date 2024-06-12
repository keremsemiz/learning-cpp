#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    for (int i = names.size() - 1; i >= 0; i--){
        cout << names[i] << endl;
    }
}