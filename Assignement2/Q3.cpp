#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string id;
    static int activeDeliveries;

public:
    Vehicle(string vid) : id(vid) {}
    static int getActiveDeliveries() { return activeDeliveries; }

    virtual void calculateRoute() = 0;
    virtual void estimateTime() = 0;
    virtual void command(string packageID, int urgency = 0) = 0;
    
    friend bool operator==(const Vehicle& v1, const Vehicle& v2);
    friend void resolveConflict(Vehicle& v1, Vehicle& v2);
    virtual ~Vehicle() {}
};

int Vehicle::activeDeliveries = 0;

class RamzanDrone : public Vehicle {
    int speed;
public:
    RamzanDrone(string vid, int s) : Vehicle(vid), speed(s) {}
    
    void calculateRoute() override {
        cout << "Drone calculating aerial route.\n";
        activeDeliveries++;
    }
    
    void estimateTime() override {
        cout << "Estimated delivery time: " << 100 / speed << " hours.\n";
    }
    
    void command(string packageID, int urgency = 0) override {
        if (urgency > 0) {
            cout << "URGENT: Activating high-speed mode for " << packageID << " (Urgency Level: " << urgency << ").\n";
        } else {
            cout << "Delivering " << packageID << " by drone.\n";
        }
    }
};

class RamzanTimeShip : public Vehicle {
    bool historicalCheck;
public:
    RamzanTimeShip(string vid) : Vehicle(vid), historicalCheck(false) {}
    
    void calculateRoute() override {
        cout << "TimeShip verifying historical consistency.\n";
        activeDeliveries++;
    }
    
    void estimateTime() override {
        cout << "TimeShip delivery: Exact arrival time guaranteed.\n";
    }
    
    void command(string packageID, int urgency = 0) override {
        if (urgency > 0) {
            cout << "Validating historical accuracy for " << packageID << " (Urgency Level: " << urgency << ").\n";
            historicalCheck = true;
        } else {
            cout << "Processing normal time-accurate delivery for " << packageID << ".\n";
        }
    }
};

class RamzanHyperPod : public Vehicle {
    int capacity;
public:
    RamzanHyperPod(string vid, int cap) : Vehicle(vid), capacity(cap) {}
    
    void calculateRoute() override {
        cout << "HyperPod navigating underground tunnel network.\n";
        activeDeliveries++;
    }
    
    void estimateTime() override {
        cout << "HyperPod delivery time: Optimized for bulk delivery.\n";
    }
    
    void command(string packageID, int urgency = 0) override {
        if (urgency > 0) {
            cout << "Prioritizing urgent bulk delivery for " << packageID << " (Urgency Level: " << urgency << ").\n";
        } else {
            cout << "Transporting bulk package " << packageID << " via HyperPod.\n";
        }
    }
};

void resolveConflict(Vehicle& v1, Vehicle& v2) {
    cout << "Resolving AI conflict between " << v1.id << " and " << v2.id << " based on efficiency metrics.\n";
}

bool operator==(const Vehicle& v1, const Vehicle& v2) {
    return v1.id == v2.id;
}

int main() {
    RamzanDrone drone("DRONE1", 200);
    RamzanTimeShip timeship("TIMESHIP1");
    RamzanHyperPod hyperpod("HYPERPOD1", 500);

    Vehicle* v1 = &drone;
    Vehicle* v2 = &timeship;
    Vehicle* v3 = &hyperpod;

    v1->calculateRoute();
    v2->calculateRoute();
    v3->calculateRoute();
    cout<<endl;
    drone.command("IFTAR_MEAL_1");
    drone.command("IFTAR_MEAL_2", 1);
    timeship.command("IFTAR_MEAL_3", 2);
    hyperpod.command("SEHRI_PACK_1", 3);
    cout<<endl;
    if (drone == timeship) {
        cout << "Same vehicles.\n";
    } else {
        cout << "Different vehicles.\n";
    }
    cout << endl;
    resolveConflict(drone, timeship);
    cout << endl;
    cout << "Active deliveries: " << Vehicle::getActiveDeliveries() << endl;

    return 0;
}
