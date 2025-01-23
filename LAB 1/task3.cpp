 #include <iostream>
 using namespace std;

 int main(){
    int ID;
    int surcharge;
    float totalbill=0;
    string name;
    float unitconsumed;
    cout << "Enter the ID of the customer: "<<endl;
    cin >> ID;
    cout << "Enter the name of the customer: "<<endl;
    cin >> name;
    cout << "Enter the unit consumed by the customer: "<<endl;
    cin >> unitconsumed;
    cout << "The ID of the customer is: "<<ID<<endl;
    cout << "The name of the customer is: "<<name<<endl;
    cout << "The unit consumed by the customer is: "<<unitconsumed<<endl;
    if (unitconsumed<=199)
    {
        totalbill = unitconsumed*16.20;
        cout << "amount charges @16.20 per unit: "<<totalbill<<endl;
    }
    else if (unitconsumed>=200 && unitconsumed<300)
    {
        totalbill = unitconsumed*20.10;
        cout << "amount charges @20.10 per unit: "<<totalbill<<endl;
    }
    else if (unitconsumed>=300 && unitconsumed<500)
    {
        totalbill = unitconsumed*27.10;
        cout << "amount charges @27.10 per unit: "<<totalbill<<endl;
    }
    else if (unitconsumed>=500)
    {
        totalbill = unitconsumed*35.90;
        cout << "amount charges @35.90 per unit: "<<totalbill<<endl;
    }
    if (totalbill>18000)
    {
        surcharge= totalbill*0.15;
        cout << "Surcharge amount: "<<surcharge<<endl;
    }
    cout << "Total amount to be paid by the customer: "<<totalbill+surcharge<<endl;
    return 0;
 }