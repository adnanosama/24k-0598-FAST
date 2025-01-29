#include <iostream>
using namespace std;

struct employee{
    string name;
    int id;
    int salary;
};

struct organization{
    string oragnizqtion_name;
    string organization_number;
    employee emp;
};

int main(){
    organization org;
    org.oragnizqtion_name= "NU-Fast";
    org.emp.id= 127;
    org.emp.name= "Linus Sebastian";
    org.emp.salary= 400000;
    org.organization_number= "NUFAST123ABC";
    cout << "the size of organization is: " << sizeof(org) << endl;
    cout << "the organization name is: " << org.oragnizqtion_name << endl;
    cout << "the organization number is: " << org.organization_number << endl;
    cout << "the employee name is: " << org.emp.name << endl;
    cout << "the employee id is: " << org.emp.id << endl;
    cout << "the employee salary is: " << org.emp.salary << endl;
    
}