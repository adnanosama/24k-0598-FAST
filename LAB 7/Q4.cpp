#include <iostream>
#include <string>
#include <vector>
using namespace std;
class person {
protected:
    string name;
    string id;
    string address;
    int phoneno;
    string email;
public:
    person(string n, string id, string a, int b, string c): name(n), id(id), address(a), phoneno(b), email(c) {}
    string getname() {
        return name;
    }
    virtual void displayinfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone number: " << phoneno << endl;
        cout << "Email: " << email << endl;
        
    }
    void updateinfo(string n, string id, string a, int b, string c) {
        name = n;
        this->id = id;
        address = a;
        phoneno = b;
        email = c;
    }
};

class professor: public person {
    string department;
    int coursestaught;
    float salary;
public:
    professor(string d, int e, float f, string n, string id, string a, int b, string c): department(d), coursestaught(e), salary(f), person(n, id, a, b, c) {}
    void displayinfo() override {
        person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursestaught << endl;
        cout << "Salary: " << salary << endl;
        cout << "--------------------------------" << endl;
    }
};

class student: public person {
    int enrollmentyear;
    int coursesenrolled;
    float gpa;
public:
    student(int d, int e, float f, string n, string id, string a, int b, string c): enrollmentyear(d), coursesenrolled(e), gpa(f), person(n, id, a, b, c) {}
    void displayinfo() override {
        person::displayinfo();
        cout << "Enrollment year: " << enrollmentyear << endl;
        cout << "Courses enrolled: " << coursesenrolled << endl;
        cout << "GPA: " << gpa << endl;
        cout << "--------------------------------" << endl;
    }
};

class staff: public person {
    string department;
    string position;
    float salary;
public:
    staff(string d, string e, float f, string n, string id, string a, int b, string c): department(d), position(e), salary(f), person(n, id, a, b, c) {}
    void displayinfo() override {
        person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "--------------------------------" << endl;
    }
};
class course {
protected:
    string id;
    string name;
    int credits;
    string instructor;
    string schedule;
    vector<student> students;
public:
    course(string i, int b, string c, string n, string s): id(i), credits(b), instructor(c), name(n), schedule(s) {}
    void registerStudent(student s) {
        students.push_back(s);
        cout << "Student " << s.getname() << " registered successfully for " << name << " by " << instructor << "." << endl;
    }
    void calcGrades() {
        cout << "Grade calculated for course " << name << endl;
    }
    void displayCourseInfo() {
        cout << "Course ID: " << id << endl;
        cout << "Course Name: " << name << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Registered Students: " << students.size() << endl;
        cout << "--------------------------------" << endl;
    }
};

int main() {
    student s1(2022, 4, 3.9, "Bob", "S5678", "456 Pine St", 5595678, "bob@uni.com");
    professor p1("Mathematics", 5, 80000, "Dr. Johnson", "P789", "789 Birch St", 5556789, "johnson@uni.com");
    staff st1("HR", "Supervisor", 55000, "Emma", "ST456", "123 Cedar St", 5554321, "emma@uni.com");
    course c1("MATH201", 4, "Ms. Laura", "Calculus I", "Tue/Thu 2:00 PM");
    s1.displayinfo();
    p1.displayinfo();
    st1.displayinfo();
    c1.registerStudent(s1);
    c1.displayCourseInfo();
    c1.calcGrades();

    return 0;
}