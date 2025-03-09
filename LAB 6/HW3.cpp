#include <iostream>
#include <string>
using namespace std;

class student{
    int id;
    string name;
    public:
    student(){
        id = 0;
        name = "";
    }
    student(int i, string n) : id(i), name(n) {}
    void getstudentdetails(){
        cout << "ID: " << id <<endl;
        cout<< "Name: " << name << endl;
    }

};

class marks: virtual public student{
    protected:
    int marks_oop,marks_pf,makrs_ds,marks_db;
    public:
    void getmarks(int oop, int pf, int ds, int db){
        marks_oop = oop;
        marks_pf = pf;
        makrs_ds = ds;
        marks_db = db;
    }
    void displaymarks(){
        cout << "Marks in OOP: " << marks_oop << endl;
        cout << "Marks in PF: " << marks_pf << endl;
        cout << "Marks in DS: " << makrs_ds << endl;
        cout << "Marks in DB: " << marks_db << endl;
    }
    
};

class result: virtual public marks{
    protected:
    int total_marks;
    double avg_marks;
    public:
    result(int i, string n) : student(i, n) {}
    void calculate(){
        total_marks = marks_oop + marks_pf + makrs_ds + marks_db;
        avg_marks = total_marks / 4.0;
    }
    void display(){
        getstudentdetails();
        displaymarks();
        cout << "Total Marks: " << total_marks <<"/" <<"400"<< endl;
        cout << "Average Marks: " << avg_marks << endl;
    }
};

int main(){
    result r(1, "Ali");
    r.getmarks(90, 80, 70, 60);
    r.calculate();
    r.display();
    return 0;
}