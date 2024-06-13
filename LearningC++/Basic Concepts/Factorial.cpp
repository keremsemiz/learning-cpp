#include <iostream>
using namespace std;

int num;
int factorial = 1;

int main() {
    cout << "Input a number" << endl;
    cin >> num;
    
    while (num > 1){
        factorial *= num;
        num--;
    }

    cout << "The factorial is " << factorial << endl;
}