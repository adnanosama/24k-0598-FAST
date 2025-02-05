#include<iostream>
using namespace std;

class Glass {
	public:
		int LiquidLevel;
		void Drink(int milliliters){
			LiquidLevel=LiquidLevel-milliliters;
		}
		void Refill(){
			LiquidLevel=200;
		}
};

int main(){
	int choice=0, amount;
	Glass liquid;
	liquid.LiquidLevel=200;
	for(int i; ;i++){
		cout<<"what do you want to drink?\n1.water\n2.juice\n";
		cin >> choice;
		if(choice==1){
			cout << "how many milliliters?\n";
			cin >> amount;
			liquid.Drink(amount);
			if(liquid.LiquidLevel<100){
				liquid.Refill();
				cout<< "Water has been refilled\n";
			}
		}
		if(choice==2){
			cout << "how many milliliters?\n";
			cin >> amount;
			liquid.Drink(amount);
			if(liquid.LiquidLevel<100){
				liquid.Refill();
				cout<< "juice has been refilled\n";
			}
		}
		cout<< "do you want more?,enter 0 to exit and 1 for yes\n";
		cin >> choice;
		if(choice==0){
			break;
		}
	}
}
