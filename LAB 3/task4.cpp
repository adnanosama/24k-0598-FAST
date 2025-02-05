#include <iostream>
#include <string>
using namespace std;

class Employee{
  public:
  string firstname;
  string secondname;
  double salary;
  
  Employee(string firstname,string secondname,double salary){
      this->firstname=firstname;
      this->secondname=secondname;
      this->salary=salary;
  }
  void checksalary(){
      if(salary<0){
          salary=0.0;
      }
      return;
  }

  double getsalary(){
      return salary;
  }
  void raise(){
      salary=1.10*salary;
      return;
  }
};

int main() {
    Employee e1("Adnan","osama",800000);
    e1.checksalary();
    Employee e2("zaid","zubair",900000);
    e2.checksalary();
    cout<<"Before raise:\n"<<endl;
    cout<<e1.getsalary()<<endl;
    cout<<e2.getsalary()<<endl;
    e1.raise();
    e2.raise();
    cout<<"After raise:\n"<<endl;
    cout<<e1.getsalary()<<endl;
    cout<<e2.getsalary()<<endl;
    
    return 0;
}