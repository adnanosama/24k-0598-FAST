#include<iostream>
#include<string>
using namespace std;

class User{
public:
int age;
string name;

User(int age,string name):age(age),name(name){}

void setname(string n){
    name=n;
    return;
}
string getname(){
    return name;
}
void setage(int a){
    age=a;
    return;
}
int getage(){
    return age;
}

};
int main(){
    User p(19,"adnan");
    cout<<"My name is "<<p.getname()<<" My age is "<<p.getage()<<endl;
    return 0;
}