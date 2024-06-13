#include <iostream>
using namespace std;

int num;
int main() {
    cout << "Input a number: " << endl;
    cin >> num;

    if (num % 2 == 0){
        cout << "Your number " << num << " is even." << endl;
    }
    else if (num % 2 != 0){
        cout << "Your number " << num << " is odd." << endl;
    }
    return 0;
}