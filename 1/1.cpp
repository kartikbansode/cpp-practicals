#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    const int bonus = 10;

    cout << "C++ FUNDAMENTALS \n";

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    double division = (num2 != 0) ? (double)num1 / num2 : 0;

    cout << "\n===== RESULTS =====\n";
    cout << "First Number: " << num1 << endl;
    cout << "Second Number: " << num2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;

    if (num2 != 0)
        cout << "Division: " << division << endl;
    else
        cout << "Division: Not possible\n";

    cout << "Sum with Bonus: " << sum + bonus << endl;

    cout << "\n===== OPERATORS =====\n";
    cout << "Is first number greater? " << (num1 > num2) << endl;
    cout << "Are both numbers positive? "
         << (num1 > 0 && num2 > 0) << endl;

    return 0;
}
