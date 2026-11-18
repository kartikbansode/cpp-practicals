
#include <iostream>
#include <utility>
using namespace std;

class Array {
    int *data;
    int size;

public:
    Array() {
        size = 0;
        data = nullptr;
        cout << "Default Constructor\n";
    }

    Array(int s) {
        size = s;
        data = new int[size]{};
        cout << "Parameterized Constructor\n";
    }

    Array(const Array &a) {
        size = a.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
        cout << "Copy Constructor\n";
    }

    Array& operator=(const Array &a) {
        if (this != &a) {
            delete[] data;
            size = a.size;
            data = new int[size];
            for (int i = 0; i < size; i++)
                data[i] = a.data[i];
        }
        cout << "Copy Assignment\n";
        return *this;
    }

    Array(Array &&a) noexcept {
        size = a.size;
        data = a.data;
        a.size = 0;
        a.data = nullptr;
        cout << "Move Constructor\n";
    }

    Array& operator=(Array &&a) noexcept {
        if (this != &a) {
            delete[] data;
            size = a.size;
            data = a.data;
            a.size = 0;
            a.data = nullptr;
        }
        cout << "Move Assignment\n";
        return *this;
    }

    void set(int i, int value) {
        if (i >= 0 && i < size)
            data[i] = value;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    ~Array() {
        delete[] data;
        cout << "Destructor\n";
    }
};

int main() {
    Array a1;
    Array a2(3);

    a2.set(0, 10);
    a2.set(1, 20);
    a2.set(2, 30);

    Array a3(a2);

    Array a4;
    a4 = a2;

    Array a5(move(a2));

    Array a6(2);
    a6 = move(a4);

    cout << "\nOriginal Array: ";
    a3.display();

    cout << "Moved Array: ";
    a5.display();

    cout << "Move Assigned Array: ";
    a6.display();

    return 0;
}
