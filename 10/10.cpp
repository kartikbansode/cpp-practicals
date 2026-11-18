
#include <iostream>
#include <exception>
#include <string>
#include <cmath>
using namespace std;

class BankException : public exception {
protected:
    string message;

public:
    BankException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidAmount : public BankException {
public:
    InvalidAmount(double amount)
        : BankException("Invalid amount: " + to_string(amount)) {}
};

class InsufficientFunds : public BankException {
public:
    InsufficientFunds(double balance, double requested)
        : BankException("Insufficient funds! Balance: " +
          to_string(balance) + ", Requested: " + to_string(requested)) {}
};

class BankAccount {
private:
    string owner;
    double balance;

    void validateAmount(double amount) const {
        if (!isfinite(amount) || amount <= 0)
            throw InvalidAmount(amount);
    }

public:
    BankAccount(const string& name, double amount)
        : owner(name), balance(amount) {
        if (!isfinite(amount) || amount < 0)
            throw InvalidAmount(amount);
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        validateAmount(amount);

        if (!isfinite(balance + amount))
            throw InvalidAmount(amount);

        balance += amount;
    }

    void withdraw(double amount) {
        validateAmount(amount);

        if (amount > balance)
            throw InsufficientFunds(balance, amount);

        balance -= amount;
    }

    void transfer(BankAccount& to, double amount) {
        validateAmount(amount);

        if (amount > balance)
            throw InsufficientFunds(balance, amount);

        if (!isfinite(to.balance + amount))
            throw InvalidAmount(amount);

        if (this == &to)
            return;

        balance -= amount;
        to.balance += amount;
    }

    void show() const {
        cout << owner << "'s balance: " << balance << "\n";
    }
};

void tryWithdraw(BankAccount& acc, double amount) {
    cout << "\nWithdraw " << amount << ":\n";

    try {
        acc.withdraw(amount);
        cout << "Success!\n";
    }
    catch (const InvalidAmount& e) {
        cout << "InvalidAmount: " << e.what() << "\n";
    }
    catch (const InsufficientFunds& e) {
        cout << "InsufficientFunds: " << e.what() << "\n";
    }

    acc.show();
}

int main() {
    BankAccount kartik("Kartik", 5000);
    BankAccount rahul("Rahul", 1000);

    cout << "===== STARTING BALANCES =====\n";
    kartik.show();
    rahul.show();

    cout << "\n===== WITHDRAWALS =====\n";

    tryWithdraw(kartik, 1500);
    tryWithdraw(kartik, 10000);
    tryWithdraw(kartik, -200);
    tryWithdraw(kartik, 0);

    cout << "\n===== TRANSFERS =====\n";

    try {
        kartik.transfer(rahul, 1000);
        cout << "Transfer of 1000 successful!\n";

        kartik.transfer(rahul, 50000);
        cout << "Transfer successful!\n";
    }
    catch (const InvalidAmount& e) {
        cout << "InvalidAmount: " << e.what() << "\n";
    }
    catch (const InsufficientFunds& e) {
        cout << "InsufficientFunds: " << e.what() << "\n";
    }

    cout << "\n===== FINAL BALANCES =====\n";
    kartik.show();
    rahul.show();

    return 0;
}
