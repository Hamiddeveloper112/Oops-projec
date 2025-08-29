#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float gpa;

public:
    Student() {
        rollNo = 0;
        name = "";
        gpa = 0.0;
    }
    Student(int r, string n, float g) {
        rollNo = r;
        name = n;
        gpa = g;
    }
    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter GPA: ";
        cin >> gpa;
    }
    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", GPA: " << gpa << endl;
    }

    int getRollNo() const {
        return rollNo;
    }
};

class StudentManager {
private:
    Student students[100];
    int count;

public:
    StudentManager() {
        count = 0;
    }

    void addStudent() {
        if (count < 100) {
            Student s;
            s.input();
            students[count++] = s;
            cout << "Student added successfully.\n";
        } else {
            cout << "Limit reached. Cannot add more students.\n";
        }
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No students to display.\n";
            return;
        }
        for (int i = 0; i < count; ++i) {
            students[i].display();
        }
    }

    void searchStudent() const {
        int rno;
        cout << "Enter Roll Number to search: ";
        cin >> rno;
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (students[i].getRollNo() == rno) {
                cout << "Student Found:\n";
                students[i].display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student not found.\n";
        }
    }
};

int main() {
    StudentManager sm;
    int choice;

    do {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sm.addStudent();
            break;
        case 2:
            sm.displayAll();
            break;
        case 3:
            sm.searchStudent();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
