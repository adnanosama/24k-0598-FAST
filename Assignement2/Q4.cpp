#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INITIAL_HASH = 5381;

// Global hash function
int calculateHash(const string& password) {
    int hash = INITIAL_HASH;
    for (char c : password) {
        hash = hash * 33 + static_cast<int>(c);
    }
    return hash;
}

class User {
protected:
    string name;
    string id;
    vector<string> permissions;
    string email;
    int hashedPassword;

public:
    User(string n, string i, string e, string pwd, vector<string> perms)
        : name(n), id(i), email(e), permissions(perms) {
        hashedPassword = calculateHash(pwd);
    }

    virtual ~User() {}

    bool authenticate(string pwd) {
        return calculateHash(pwd) == hashedPassword;
    }

    virtual void display() {
        cout << "Name: " << name << "\nID: " << id 
             << "\nEmail: " << email << "\nPermissions: ";
        for (auto& p : permissions) cout << p << " ";
        cout << endl;
    }

    bool hasPermission(string action) {
        return find(permissions.begin(), permissions.end(), action) != permissions.end();
    }

    virtual void accessLab(string action) {
        if (hasPermission(action)) {
            cout << "Access granted to " << action << endl;
        } else {
            cout << "Access denied to " << action << endl;
        }
    }
    string getID() const {
        return id;
    }
};

class Student : public User {
    vector<int> assignments;

public:
    Student(string n, string i, string e, string pwd) 
        : User(n, i, e, pwd, {"submit_assignment"}) {}

    void display() override {
        User::display();
        cout << "Assignments status: ";
        for (int status : assignments) cout << status << " ";
        cout << endl;
    }

    void addAssignment() {
        assignments.push_back(0);
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < assignments.size()) {
            assignments[index] = 1;
        }
    }
};

class TA : public Student {
    vector<string> students;
    vector<string> projects;

public:
    TA(string n, string i, string e, string pwd)
        : Student(n, i, e, pwd) {
        permissions = {"view_projects", "manage_students"};
    }

    void display() override {
        User::display();
        cout << "Managed students: ";
        for (auto& s : students) cout << s << " ";
        cout << "\nProjects: ";
        for (auto& p : projects) cout << p << " ";
        cout << endl;
    }

    bool assignStudent(string studentID) {
        if (students.size() < 10) {
            students.push_back(studentID);
            return true;
        }
        return false;
    }

    bool addProject(string projectName) {
        if (projects.size() < 2) {
            projects.push_back(projectName);
            return true;
        }
        return false;
    }
};

class Professor : public User {
public:
    Professor(string n, string i, string e, string pwd)
        : User(n, i, e, pwd, {"assign_projects", "full_lab_access"}) {}

    void display() override {
        User::display();
        cout << "Professor privileges: Full lab access\n";
    }

    bool assignProject(TA& ta, string projectName) {
        return ta.addProject(projectName);
    }
};

// Global authentication function
void authenticateAndPerformAction(User* user, string action) {
    string pwd;
    cout << "Enter password for " << user->getID() << ": ";
    cin >> pwd;
    
    if (user->authenticate(pwd)) {
        cout << "Authentication successful!\n";
        user->accessLab(action);
    } else {
        cout << "Authentication failed!\n";
    }
}

int main() {
    Student student1("Ali", "S123", "ali@uni.edu", "student123");
    student1.addAssignment();
    student1.addAssignment();

    TA ta1("Ahmed", "TA456", "ahmed@uni.edu", "ta456pass");
    ta1.assignStudent("S123");
    ta1.addProject("ML Research");

    Professor prof1("Dr. Smith", "P789", "smith@uni.edu", "prof123");

    // Test authentication and actions
    authenticateAndPerformAction(&student1, "submit_assignment");
    authenticateAndPerformAction(&ta1, "manage_students");
    authenticateAndPerformAction(&prof1, "assign_projects");

    // Test functionality
    student1.submitAssignment(0);
    ta1.assignStudent("S124");
    prof1.assignProject(ta1, "AI Project");

    cout << "\nStudent Info:\n";
    student1.display();
    
    cout << "\nTA Info:\n";
    ta1.display();
    
    cout << "\nProfessor Info:\n";
    prof1.display();

    return 0;
}