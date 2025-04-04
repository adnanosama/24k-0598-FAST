#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Poltergeist; 


class Ghost {
protected:
    string workerName;
    int scareLevel;

public:
    Ghost(string name, int scare) : workerName(name), scareLevel(scare) {}
    virtual ~Ghost() {}

    virtual void haunt() const = 0;

    int getScareLevel() const {
        return scareLevel;
    }

    friend ostream& operator<<(ostream& os, const Ghost& ghost) {
        os << "Ghost played by: " << ghost.workerName << ", Scare Level: " << ghost.scareLevel;
        return os;
    }

    Ghost* operator+(const Ghost& other) const;
    
};

// Derived classes for different types of ghosts
class Poltergeist : virtual public Ghost {
public:
    Poltergeist(string name, int scare) : Ghost(name, scare) {}

    void haunt() const override {
        cout << workerName << " (Poltergeist) is moving objects around!" << endl;
    }
};

class Banshee : virtual public Ghost {
public:
    Banshee(string name, int scare) : Ghost(name, scare) {}

    void haunt() const override {
        cout << workerName << " (Banshee) is screaming loudly!" << endl;
    }
};

class ShadowGhost : virtual public Ghost {
public:
    ShadowGhost(string name, int scare) : Ghost(name, scare) {}

    void haunt() const override {
        cout << workerName << " (ShadowGhost) is whispering creepily!" << endl;
    }
};

// Hybrid ghost
class ShadowPoltergeist : public Poltergeist, public ShadowGhost {
public:
ShadowPoltergeist(string name, int scare)
: Ghost(name, scare), 
  Poltergeist(name, scare),
  ShadowGhost(name, scare) {}

    void haunt() const override {
        Poltergeist::haunt();
        ShadowGhost::haunt();
    }
};

// Visitor class
class Visitor {
    string name;
    int bravery;

public:
    Visitor(string name, int bravery) : name(name), bravery(bravery) {}

    string getReaction(int scareLevel) const {
        if (scareLevel < bravery - 2) {
            return name + " laughs or taunts the ghost.";
        } else if (scareLevel > bravery + 2) {
            return name + " screams or runs away!";
        } else {
            return name + " gets a shaky voice.";
        }
    }

    friend ostream& operator<<(ostream& os, const Visitor& visitor) {
        os << "Visitor: " << visitor.name << ", Bravery: " << visitor.bravery;
        return os;
    }
};

// HauntedHouse class
class HauntedHouse {
    string name;
    vector<Ghost*> ghosts;

public:
    HauntedHouse(string name) : name(name) {}

    void addGhost(Ghost* ghost) {
        ghosts.push_back(ghost);
    }

    void simulateHaunting(const vector<Visitor>& visitors) const {
        cout << "Welcome to " << name << "!" << endl;
        for (const auto& ghost : ghosts) {
            ghost->haunt();
            for (const auto& visitor : visitors) {
                cout << visitor.getReaction(ghost->getScareLevel()) << endl;
            }
        }
    }

    ~HauntedHouse() {
        for (auto ghost : ghosts) {
            delete ghost;
        }
    }
};

// Global friend function 
void visit(const vector<Visitor>& visitors, const HauntedHouse& house) {
    house.simulateHaunting(visitors);
}

Ghost* Ghost::operator+(const Ghost& other) const {
    return new Poltergeist(workerName + " & " + other.workerName, (scareLevel + other.scareLevel) / 2);
}

int main() {
    srand(static_cast<unsigned>(time(0))); // for random scare levels

    
    HauntedHouse house1("Spooky Mansion");
    HauntedHouse house2("Creepy Castle");


    house1.addGhost(new Poltergeist("Alice", rand() % 10 + 1));
    house1.addGhost(new Banshee("Bob", rand() % 10 + 1));
    house1.addGhost(new ShadowGhost("Charlie", rand() % 10 + 1));
    house2.addGhost(new ShadowPoltergeist("Diana", rand() % 10 + 1));
    house2.addGhost(new Poltergeist("Eve", rand() % 10 + 1));


    vector<Visitor> visitors = {
        Visitor("John", 3),  // Cowardly
        Visitor("Jane", 6),  // Average
        Visitor("Jack", 9)   // Fearless
    };

 
    visit(visitors, house1);
    cout << endl;
    visit(visitors, house2);

    return 0;
}



