#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string first_name;
    string last_name;
    int student_id;
    double GPA;
    int credits;
};

void addStudent(vector<Student>& students) {
    Student new_student;
    cout << "Enter First Name: ";
    cin >> new_student.first_name;
    cout << "Enter Last Name: ";
    cin >> new_student.last_name;
    cout << "Enter Student ID: ";
    cin >> new_student.student_id;
    cout << "Enter GPA: ";
    cin >> new_student.GPA;
    cout << "Enter Credits: ";
    cin >> new_student.credits;
    students.push_back(new_student);
    cout << "Student added successfully!" << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }
    cout << "--- Student List ---" << endl;
    for (const auto& student : students) {
        cout << "First Name: " << student.first_name << endl;
        cout << "Last Name: " << student.last_name << endl;
        cout << "Student ID: " << student.student_id << endl;
        cout << "GPA: " << student.GPA << endl;
        cout << "Credits: " << student.credits << endl;
        cout << "------------------" << endl;
    }
}

void editStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (auto& student : students) {
        if (student.student_id == id) {
            cout << "Enter new First Name: ";
            cin >> student.first_name;
            cout << "Enter new Last Name: ";
            cin >> student.last_name;
            cout << "Enter new GPA: ";
            cin >> student.GPA;
            cout << "Enter new Credits: ";
            cin >> student.credits;
            cout << "Student updated successfully!" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void deleteStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->student_id == id) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "===== STUDENT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Edit Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                editStudent(students);
                break;
            case 4:
                deleteStudent(students);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
