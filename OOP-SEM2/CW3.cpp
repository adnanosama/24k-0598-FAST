#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct DOB {
    int day;
    int month;
    int year;
};

class PatientRecord {
private:
    int patientID;
    string name;

    DOB dob;
    vector<string> medicalHistory;
    vector<string> currentTreatment;
    float amount;
    string paymentMethod;

public:
    PatientRecord(int id, string n, int d, int m, int y) {
        patientID = id;
        name = n;
        dob.day = d;
        dob.month = m;
        dob.year = y;
        amount = 0;
        paymentMethod = "";
    }

    void getPublicData() {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob.day << "/" << dob.month << "/" << dob.year << endl;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
private:
    int doctorID;
    string name;
    string specialization;

public:
    Doctor(int id, string n, string s) {
        doctorID = id;
        name = n;
        specialization = s;
    }

    void getDoctorInfo() {
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
    }

    void updateMedicalHistory(PatientRecord &p, string entry) {
        p.medicalHistory.push_back(entry);
    }

    void updateCurrentTreatment(PatientRecord &p, string treatment) {
        p.currentTreatment.push_back(treatment);
    }

    void viewMedicalData(PatientRecord &p) {
        cout << "Medical History:" << endl;
        for (string s : p.medicalHistory) {
            cout << s << endl;
        }
        cout << "Current Treatment:" << endl;
        for (string s : p.currentTreatment) {
            cout << s << endl;
        }
    }
};

class Billing {
public:
    void addBillingDetails(PatientRecord &p, float a, string pm) {
        p.amount = a;
        p.paymentMethod = pm;
    }

    void getBillingInfo(PatientRecord &p) {
        cout << "Billing Amount: " << p.amount << endl;
        cout << "Payment Method: " << p.paymentMethod << endl;
    }
};

class Receptionist {
public:
    void getLimitedData(PatientRecord &p) {
        p.getPublicData();
    }
};

int main() {
    PatientRecord patient(1, "John Doe", 1, 1, 1990);

    Doctor doc(101, "Dr. Smith", "Cardiology");
    doc.getDoctorInfo();
    doc.updateMedicalHistory(patient, "Heart disease");
    doc.updateMedicalHistory(patient, "High blood pressure");
    doc.viewMedicalData(patient);
    doc.updateCurrentTreatment(patient, "Medication A");
    doc.updateCurrentTreatment(patient, "Medication B");
    doc.viewMedicalData(patient);

    Billing bill;
    bill.addBillingDetails(patient, 1500, "Credit Card");
    bill.getBillingInfo(patient);

    Receptionist reception;
    reception.getLimitedData(patient);

    // The receptionist cannot access medical or billing data directly
    // This is enforced by not exposing those methods publicly

    return 0;
}
