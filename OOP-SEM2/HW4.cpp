#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    int id;

public:
    Student(string n, int i) : name(n), id(i) {}
    
    virtual float getTuition(const string& status, int creditHours) = 0;

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int i) : Student(n, i) {}

    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    float getTuition(const string& status, int creditHours) override {
        if (status == "undergraduate")
            return 200 * creditHours;
        else if (status == "graduate")
            return 300 * creditHours;
        else if (status == "doctoral")
            return 400 * creditHours;
        else {
            cout << "Invalid status entered." << endl;
            return 0;
        }
    }

    void display() override {
        Student::display();
        cout << "Research Topic: " << researchTopic << endl;
    }
};


int main() {
    GraduateStudent gs("Adnan osama", 2025);
    gs.setResearchTopic("Artificial Intelligence in Healthcare ");

    gs.display();

    string status = "graduate";
    int credits = 9;

    float tuition = gs.getTuition(status, credits);
    cout << "Status: " << status << endl;
    cout << "Credit Hours: " << credits << endl;
    cout << "Tuition: $" << tuition << endl;

    return 0;
}
