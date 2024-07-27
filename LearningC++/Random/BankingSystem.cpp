#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(const std::string& accNum, const std::string& holderName, double initialBalance)
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    std::string getAccountNumber() const {
        return accountNumber;
    }

    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " to account " << accountNumber << std::endl;
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber
                  << " | Holder: " << accountHolderName
                  << " | Balance: $" << balance << std::endl;
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(const std::string& accNum, const std::string& holderName, double initialBalance) {
        accounts.emplace_back(accNum, holderName, initialBalance);
    }

    void deleteAccount(const std::string& accNum) {
        auto it = std::remove_if(accounts.begin(), accounts.end(), [&](const BankAccount& account) {
            return account.getAccountNumber() == accNum;
        });
        if (it != accounts.end()) {
            accounts.erase(it, accounts.end());
            std::cout << "Deleted account " << accNum << std::endl;
        } else {
            std::cout << "Account not found.\n";
        }
    }

    void displayAccounts() const {
        for (const auto& account : accounts) {
            account.display();
        }
    }
};

int main() {
    Bank bank;
    bank.addAccount("1001", "Alice Johnson", 1500.0);
    bank.addAccount("1002", "Bob Smith", 2000.0);

    std::cout << "Bank Accounts:\n";
    bank.displayAccounts();

    std::cout << "\nAlice deposits $500...\n";
    bank.accounts[0].deposit(500);
    bank.displayAccounts();

    std::cout << "\nBob withdraws $1000...\n";
    bank.accounts[1].withdraw(1000);
    bank.displayAccounts();

    std::cout << "\nDeleting Bob's account...\n";
    bank.deleteAccount("1002");
    bank.displayAccounts();

    return 0;
}
