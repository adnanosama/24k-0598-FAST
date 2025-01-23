#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    string firstname, lastname;
    float score1, score2, score3, score4, score5;
    float totalscore;
    float avgtestscore;
    cout << "Enter the name of the student following 5 test scores: "<<endl;
    cin >> firstname >> lastname >> score1 >> score2 >> score3 >> score4 >> score5;
    totalscore = score1 + score2 + score3 + score4 + score5;
    avgtestscore = totalscore/5;
    cout << fixed << setprecision(2);
    cout << "student name: "<<firstname <<" "<< lastname <<endl;
    cout << "test scores:" << score1 <<" "<< score2 <<" "<< score3 <<" "<< score4 <<" "<< score5 <<endl;
    cout << "average test score: "<<avgtestscore <<endl;
    return 0;
    
}