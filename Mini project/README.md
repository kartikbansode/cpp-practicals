# Student Portal – C++

A simple console-based Student Portal application developed using C++ and Object-Oriented Programming.

## Features
- Add student records (ID, Name, Course, Marks).
- Search students using Student ID.
- Display all student records.
- Calculate grades based on marks.
- Save and load records using file handling.
- Validate student IDs and marks.
- Handle errors using exception handling.

## Concepts Used
- Classes and Objects
- Object-Oriented Programming (OOP)
- STL Vector Container
- STL Algorithms (`find_if`)
- File Handling (`ifstream`, `ofstream`)
- Exception Handling (`try`, `catch`, `throw`)

## Compile and Run

```bash
g++ student.cpp -o student
./student
```

For Windows:

```bash
g++ student.cpp -o student.exe
student.exe
```

## Storage
Student records are stored in `students.txt` in the application directory.

## Language
C++