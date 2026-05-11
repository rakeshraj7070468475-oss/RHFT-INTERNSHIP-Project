#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

    char calculateGradeInternal() const {
        if (marks >= 90) return 'A';
        if (marks >= 75) return 'B';
        if (marks >= 50) return 'C';
        return 'F';
    }

public:
    // Constructor with validation
    Student(string n, int r, float m) {
        setName(n);
        setRollNumber(r);
        setMarks(m);
    }

    // Setters with validation
    void setName(string n) {
        if (n.empty()) {
            throw invalid_argument("Name cannot be empty");
        }
        name = n;
    }

    void setRollNumber(int r) {
        if (r <= 0) {
            throw invalid_argument("Roll number must be positive");
        }
        rollNumber = r;
    }

    void setMarks(float m) {
        if (m < 0 || m > 100) {
            throw invalid_argument("Marks must be between 0 and 100");
        }
        marks = m;
    }

    // Getters
    string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }
    float getMarks() const { return marks; }

    char getGrade() const {
        return calculateGradeInternal();
    }

    void display() const {
        cout << "Name: " << name
             << ", Roll: " << rollNumber
             << ", Marks: " << marks
             << ", Grade: " << getGrade() << endl;
    }
};

// Utility functions
float calculateAverage(const vector<Student>& students) {
    if (students.empty()) return 0;

    float sum = 0;
    for (const auto& s : students) {
        sum += s.getMarks();
    }
    return sum / students.size();
}

Student findTopper(const vector<Student>& students) {
    if (students.empty()) {
        throw runtime_error("No students available");
    }

    Student topper = students[0];
    for (const auto& s : students) {
        if (s.getMarks() > topper.getMarks()) {
            topper = s;
        }
    }
    return topper;
}
int main() {
    vector<Student> students;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int roll;
        float marks;

        cout << "\nStudent " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Roll Number: ";
        cin >> roll;

        cout << "Marks: ";
        cin >> marks;

        try {
            students.emplace_back(name, roll, marks);
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
            i--; // retry
        }
    }

    cout << "\n--- Student Records ---\n";
    for (const auto& s : students) {
        s.display();
    }

    cout << "\nAverage Marks: " << calculateAverage(students) << endl;

    try {
        Student topper = findTopper(students);
        cout << "Topper: ";
        topper.display();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}