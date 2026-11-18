
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int acc, double bal) {
        accountNumber = acc;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal!\n";
        }
    }

    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount acc1(101, 5000);
    BankAccount acc2(102, 8000);

    cout << "===== ACCOUNT 1 =====\n";
    acc1.deposit(1000);
    acc1.withdraw(500);
    acc1.display();

    cout << "\n===== ACCOUNT 2 =====\n";
    acc2.deposit(2000);
    acc2.withdraw(1000);
    acc2.display();

    return 0;
}
