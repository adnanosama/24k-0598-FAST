#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold employee data
struct Employee {
    int id;
    string name;
    string designation;
    int years;

    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Years of Service: " << years << endl;
        cout << "-----------------------------" << endl;
    }
};

void writeDummyData() {
    ofstream outFile("CW2.txt");
    vector<Employee> data = {
        {1, "Ali", "Manager", 3},
        {2, "Sara", "Assistant", 1},
        {3, "John", "Manager", 1},
        {4, "Zara", "Manager", 4},
        {5, "Mike", "Technician", 2}
    };

    for (const auto& emp : data) {
        outFile << emp.id << endl
                << emp.name << endl
                << emp.designation << endl
                << emp.years << endl;
    }

    outFile.close();
}

// Read all employees from file
vector<Employee> readEmployees() {
    vector<Employee> employees;
    ifstream inFile("CW2.txt");
    string line;
    while (getline(inFile, line)) {
        Employee emp;
        emp.id = stoi(line);
        getline(inFile, emp.name);
        getline(inFile, emp.designation);
        getline(inFile, line);
        emp.years = stoi(line);
        employees.push_back(emp);
    }
    inFile.close();
    return employees;
}

// Query (a): Find managers with ≥ 2 years of service
vector<Employee> findQualifiedManagers(const vector<Employee>& data) {
    vector<Employee> result;
    for (const auto& emp : data) {
        if (emp.designation == "Manager" && emp.years >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

// Query (b): Overwrite file with only query result
void overwriteWithQualified(const vector<Employee>& qualified) {
    ofstream outFile("CW2.txt");
    for (const auto& emp : qualified) {
        outFile << emp.id << endl
                << emp.name << endl
                << emp.designation << endl
                << emp.years << endl;
    }
    outFile.close();
}

// Query (c): Write modified data with incremented ID and years
void writeModifiedData(const vector<Employee>& qualified) {
    ofstream outFile("CW2.txt");
    for (auto emp : qualified) {
        emp.id += 100; // just to show incremented IDs clearly
        emp.years += 1;
        outFile << emp.id << endl
                << emp.name << endl
                << emp.designation << endl
                << emp.years << endl;
    }
    outFile.close();
}


int main() {
    
    writeDummyData();

    
    vector<Employee> allEmployees = readEmployees();
    vector<Employee> qualified = findQualifiedManagers(allEmployees);

    cout << "Qualified Managers (>=2 years):\n";
    for (const auto& emp : qualified)
        emp.display();

    
    overwriteWithQualified(qualified);


    writeModifiedData(qualified);

    cout << "\nData has been updated with incremented IDs and Years.\n";
    vector<Employee> Employees = readEmployees();
    cout << "Updated Employees:\n";
    for (const auto& emp : Employees)
        emp.display();
 
    return 0;
}
