#include<iostream>
#include<string>
using namespace std;

class Date{
	public:
		int year;
		int day;
		int month;

		Date(int month,int day,int year){
			this->month=month;
			this->year=year;
			this->day=day;
		}

		void displaydate(){
			cout<<month<<"/"<< day <<"/"<<year<<endl;

		}

};

int main(){
	Date date(12,29,2006);
	date.displaydate();
    return 0;
}