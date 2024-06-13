#include <iostream>
using namespace std;

class BankAccount{
    public:
    string name;
    int balance;
    int amount;

    void depositMoney(){
        cout << "How much money would you like to deposit? " << endl;
        cin >> amount;
        balance = balance + amount;
        cout << "Your balance is now: " << balance << endl;
    }

    void withdrawMoney(){
        cout << "How much money would you like to withdraw? " << endl;
        cin >> amount;
        if (balance - amount < 0){
            cout << "Insufficient balance." << endl;
        }
        else{
            balance = balance - amount;
            cout << "Your balance is now: " << balance << endl;
        }
    }

    void checkBalance(){
        cout << "Your current balance is: " << balance << endl;
    }

};

int main(){
    BankAccount PrivateAccount;
    PrivateAccount.name = "John Pearson";
    PrivateAccount.balance = 25;
    PrivateAccount.checkBalance();
    PrivateAccount.withdrawMoney();
    PrivateAccount.checkBalance();
}