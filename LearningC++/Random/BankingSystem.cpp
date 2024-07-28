#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;
    std::string accountHolderName;

public:
    BankAccount(const std::string& accNum, const std::string& holderName, double initialBalance)
        : accountNumber(accNum), balance(initialBalance), accountHolderName(holderName) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " into account " << accountNumber << std::endl;
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid amount.\n";
        }
    }

    virtual void displayDetails() const {
        std::cout << "Account Number: " << accountNumber
                  << "\nAccount Holder: " << accountHolderName
                  << "\nBalance: $" << balance << std::endl;
    }

    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accNum, const std::string& holderName, double initialBalance, double rate)
        : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        std::cout << "Applied $" << interest << " interest to account " << accountNumber << std::endl;
    }

    void displayDetails() const override {
        BankAccount::displayDetails();
        std::cout << "Interest Rate: " << interestRate * 100 << "%" << std::endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(const std::string& accNum, const std::string& holderName, double initialBalance, double overdraft)
        : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftLimit >= amount)) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Overdraft limit exceeded or invalid amount.\n";
        }
    }

    void displayDetails() const override {
        BankAccount::displayDetails();
        std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
    }
};

int main() {
    SavingsAccount savings("SA1001", "Alice Johnson", 5000.0, 0.02);
    CheckingAccount checking("CA2001", "Bob Smith", 2000.0, 500.0);

    savings.displayDetails();
    checking.displayDetails();

    std::cout << "\nApplying interest to savings account...\n";
    savings.applyInterest();
    savings.displayDetails();

    std::cout << "\nWithdrawing $3000 from checking account...\n";
    checking.withdraw(3000);
    checking.displayDetails();

    return 0;
}
