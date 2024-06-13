#include <iostream>
using namespace std;

bool prime;
bool isPrime(int num){
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < (num / 2) + 1; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main () {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number) == false){
        cout << "This number is not a prime number " << endl;
    } else {
        cout << "This number is a prime number " << endl;
    }
}