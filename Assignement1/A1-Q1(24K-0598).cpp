#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class mentor;
class sport;
class skill;
class Student;

class skill {
    int skillID;
    string skillname;
    string description;
public:
    skill(int id, string name, string desc) : skillID(id), skillname(name), description(desc) { }
    string getName() { return skillname; }
    void showskilldetails(){
        cout<<  "Skill Name: "<< skillname<< "\nDescription: "<< description << endl;
    }
    void updateskilldescription(string newdesc){
        description = newdesc;
    }
};

class sport {
    int sportID;
    string name;
    string description;
    string requiredskills[10];
    int skillCount;
public:
    sport(int id, string name, string desc, string* skills, int numSkills) 
        : sportID(id), name(name), description(desc), skillCount(numSkills) {
        for (int i = 0; i < numSkills; i++) {
            requiredskills[i] = skills[i];
        }
    }
    sport(const sport &other) 
        : sportID(other.sportID), name(other.name), description(other.description), skillCount(other.skillCount) {
        for (int i = 0; i < skillCount; i++) {
            requiredskills[i] = other.requiredskills[i];
        }
    }
    void addskill(skill& s){
        if (skillCount < 10) {
            requiredskills[skillCount++] = s.getName();
            skillCount++;
        }
    }
    void removeskill(skill& s){
        for (int i = 0; i < skillCount; i++) {
            if (requiredskills[i] == s.getName()) {
                for (int j = i; j < skillCount - 1; j++) {
                    requiredskills[j] = requiredskills[j + 1];
                }
                skillCount--;
                break;
            }
        }
    }
};

class mentor {
    int mentorID;
    string *sportexpertise[3];
    int maxlearners = 3;
    string assignedlearners[3];
    string Name;
public:
    mentor(int id, string name) : mentorID(id), Name(name) { }
    string getName() const { return Name; }
    
    void assignlearner(const Student& s, int index);
    void removelearner(const Student& s, int index);
    
    string viewlearners(){
        string learners = "";
        cout << "Learners: " << endl;
        for (int i = 0; i < maxlearners; i++) {
            learners += assignedlearners[i] + "\n";
        }
        return learners;
    }
    void provideguidance(){
        cout << "Guidance provided" << endl;
    }
};

class Student {
    int studentID;
    string Name;
    int age;
    string mentorassigned;
    sport *sportinterests[3];
public:
    Student(int id, string name, int age) : studentID(id), Name(name), age(age) { } 
    void registerformentorship(const mentor& m){
        mentorassigned = m.getName();
    }
    int viewmentordetails() const {
        cout << "Mentor Name: " << mentorassigned << endl;
        return 0;
    }
    void updatesportsinterest(const sport& s, int index){
        if (index >= 0 && index < 3) {
            sportinterests[index] = new sport(s);
        }
    }
    string getName() const { return Name; }
};

void mentor::assignlearner(const Student& s, int index){
    if (index >= 1 && index <= maxlearners) {
        assignedlearners[index-1] = s.getName();
    } else {
        cout << "No more available space for learners." << endl;
    }
}

void mentor::removelearner(const Student& s, int index){
    index -= 1;
    if (index < 0 || index >= maxlearners) {
        cout << "No available learners to remove." << endl;
    } else {
        assignedlearners[index] = "";
        cout << "Learner " << s.getName() << " removed successfully." << endl;
    }
}

int main() {
    mentor m(1, "John Doe");
    Student s(1, "saad", 20);
    Student s2(2, "Ali", 21);

    string skillsArr[2] = {"Kicking", "Running"};
    sport s1(1, "Football", "A sport that involves kicking a ball", skillsArr, 2);
    skill sk1(1, "Kicking", "Kicking the ball");
    skill sk2(2, "Running", "Running around the field");
    s.updatesportsinterest(s1, 0);
    s.registerformentorship(m);
    m.assignlearner(s, 1);
    m.assignlearner(s2, 2);
    s.viewmentordetails();
    sk1.showskilldetails();
    sk2.showskilldetails();
    cout << m.viewlearners() << endl;
    m.removelearner(s, 1);
    cout << m.viewlearners() << endl;
    return 0;
}
