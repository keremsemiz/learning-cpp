#include <iostream>
using namespace std;

int age;
string color;
string name;

int main () {
    cout << "Enter your name " << endl;
    cin >> name;

    cout << "Enter your favourite color " << endl;
    cin >> color;

    cout << "Finally, enter your age " << endl;
    cin >> age;

    cout << "Hey, " << name << "! Your favourite color is " << color << " and you are " << age << " years old.";
    
    return 0;
}