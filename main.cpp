
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Student {
public:
    int id, marks;
    string name, course;

    Student(int i, string n, string c, int m) {
        id = i;
        name = n;
        course = c;
        marks = m;
    }

    string getGrade() {
        if (marks >= 90) return "A+";
        if (marks >= 75) return "A";
        if (marks >= 60) return "B";
        if (marks >= 40) return "C";
        return "Fail";
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nCourse: " << course
             << "\nMarks: " << marks
             << "\nGrade: " << getGrade() << "\n";
    }
};

class StudentPortal {
    vector<Student> students;

public:
    void addStudent() {
        int id, marks;
        string name, course;

        try {
            cout << "Enter ID: ";
            cin >> id;

            if (id <= 0 || find_if(students.begin(), students.end(),
                [id](Student s) { return s.id == id; }) != students.end())
                throw invalid_argument("Invalid or duplicate ID!");

            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Course: ";
            getline(cin, course);

            cout << "Enter Marks (0-100): ";
            cin >> marks;

            if (marks < 0 || marks > 100)
                throw invalid_argument("Marks must be between 0 and 100!");

            students.emplace_back(id, name, course, marks);
            cout << "Student added successfully!\n";
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter Student ID: ";
        cin >> id;

        auto it = find_if(students.begin(), students.end(),
            [id](Student s) { return s.id == id; });

        if (it != students.end())
            it->display();
        else
            cout << "Student not found!\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No student records found!\n";
            return;
        }

        for (auto &s : students)
            s.display();
    }

    void saveRecords() {
        ofstream file("students.txt");

        if (!file)
            throw runtime_error("Unable to save records!");

        for (auto &s : students)
            file << s.id << "\n" << s.name << "\n"
                 << s.course << "\n" << s.marks << "\n";

        file.close();
        cout << "Records saved successfully!\n";
    }

    void loadRecords() {
        ifstream file("students.txt");

        if (!file) {
            cout << "No saved records found!\n";
            return;
        }

        students.clear();
        int id, marks;
        string name, course;

        while (file >> id) {
            file.ignore();
            getline(file, name);
            getline(file, course);
            file >> marks;
            file.ignore();

            if (id <= 0 || marks < 0 || marks > 100)
                throw runtime_error("Invalid data in file!");

            students.emplace_back(id, name, course, marks);
        }

        cout << "Records loaded successfully!\n";
        file.close();
    }
};

int main() {
    StudentPortal portal;
    int choice;

    do {
        cout << "\n===== STUDENT PORTAL =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Save Records\n";
        cout << "5. Load Records\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: portal.addStudent(); break;
                case 2: portal.searchStudent(); break;
                case 3: portal.displayStudents(); break;
                case 4: portal.saveRecords(); break;
                case 5: portal.loadRecords(); break;
                case 6: cout << "Exiting Student Portal...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 6);

    return 0;
}
