#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int age;
    string address;
};

 vector<Student> students;

void addStudent() {
    Student student;
    cout << "Enter the student's name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter the student's roll number: ";
    cin >> student.rollNumber;
    cout << "Enter the student's age: ";
    cin >> student.age;
    cin.ignore();
    cout << "Enter the student's address: ";
    getline(cin, student.address);

    students.push_back(student);
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
    } else {
        cout << "Student Records:\n";
        for (const auto& student : students) {
            cout << "Name: " << student.name << "\n";
            cout << "Roll Number: " << student.rollNumber << "\n";
            cout << "Age: " << student.age << "\n";
            cout << "Address: " << student.address << "\n";
            cout << "-----------------------------\n";
        }
    }
}

void searchStudent(int rollNumber) {
    for (const auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Name: " << student.name << "\n";
            cout << "Roll Number: " << student.rollNumber << "\n";
            cout << "Age: " << student.age << "\n";
            cout << "Address: " << student.address << "\n";
            return;
        }
    }
            cout << "Student with Roll Number " << rollNumber << " not found.\n";
}

int main() {
    char option;
    int rollNumber;

    do {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case '1':
                addStudent();
                break;
            case '2':
                displayStudents();
                break;
            case '3':
                cout << "Enter the Roll Number to search: ";
                cin >> rollNumber;
                searchStudent(rollNumber);
                break;
            case '4':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (option != '4');

    return 0;
}
