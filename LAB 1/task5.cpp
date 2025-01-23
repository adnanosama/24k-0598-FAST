#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    string moviename;
    float adultticketprice;
    float childticketprice;
    int numadult;
    int numchild;
    int totaltickets;
    float charitypercent;
    float gross;
    cout << "Enter the name of the movie: "<<endl;
    cin >> moviename;
    cout << "Enter the price of the adult ticket: "<<endl;
    cin >> adultticketprice;
    cout << "Enter the price of the child ticket: "<<endl;
    cin >> childticketprice;
    cout << "Enter the number of adult tickets sold: "<<endl;
    cin >> numadult;
    cout << "Enter the number of child tickets sold: "<<endl;
    cin >> numchild;
    cout << "Enter the percentage of the gross amount to be donated to charity: "<<endl;
    cin >> charitypercent;
    gross = (adultticketprice*numadult) + (childticketprice*numchild);
    cout << fixed << setprecision(2);
    totaltickets = numadult + numchild;
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');
    cout << "Movie Name:.............................. "<<moviename<<endl;
    cout << "Number of Tickets Sold:.................. "<<totaltickets<<endl;
    cout << "Gross Amount:............................ "<<gross<<"$"<<endl;
    cout << "Percentage of Gross Amount Donated: "<<charitypercent<<"%"<<endl;
    cout << "Amount Donated:............... "<<(gross*charitypercent)/100<<"$"<<endl;
    cout << "Net Sale:................................. "<<gross-((gross*charitypercent)/100)<<"$"<<endl;    

}