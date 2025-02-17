#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class books{
    string author;
    string title;
    string publisher;
    float price;
    int stockposition;
    int copies;
    public:
    books(){
        author="";
        title="";
        publisher="";
        price=0.0;
        stockposition=0;
        copies=0;
    }
    books(string author, string title, string publisher, float price, int stockposition, int copies): author(author), title(title), publisher(publisher), price(price), stockposition(stockposition), copies(copies) {
        if(price<0){
            this->price=0.0;
        }
        if(stockposition<0){
            this->stockposition=0;
        }
        if(copies<0){
            this->copies=0;
        }
    }
    string getdetails(){
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << fixed << setprecision(2) << price << endl;
        cout << "Stock Position: " << stockposition << endl;
        cout << "Copies: " << copies << endl;
        return "";
        
    }
    string getauthor(){
        return author;
    }
    string gettitle(){
        return title;
    }
    int getcopies(){
        return copies;
    }
    float getprice(){
        return price;
    }

};

int main(){
    int index;
    string title;
    string author;
    books booksarray[10];
    booksarray[0] = books("author1","title1","publisher1",10.0,1,10);
    booksarray[1] = books("author2","title2","publisher2",20.0,2,20);
    booksarray[2] = books("author3","title3","publisher3",30.0,3,30);
    booksarray[3] = books("author4","title4","publisher4",40.0,4,40);
    booksarray[4] = books("author5","title5","publisher5",50.0,5,50);
    booksarray[5] = books("author6","title6","publisher6",60.0,6,60);
    booksarray[6] = books("author7","title7","publisher7",70.0,7,70);
    booksarray[7] = books("author8","title8","publisher8",80.0,8,80);
    booksarray[8] = books("author9","title9","publisher9",90.0,9,90);
    booksarray[9] = books("author10","title10","publisher10",100.0,10,100);
    

    cout << "Enter the title of the book: ";
    getline(cin, title);
    cout << "Enter the author of the book: ";
    getline(cin, author);
    for(int i = 0; i < 10; i++) {
        if(title == booksarray[i].gettitle() && author == booksarray[i].getauthor()){
            cout << booksarray[i].getdetails() << endl;
            index = i;
            break;
        }
        if(i == 9) {
            cout << "Book not found." << endl;
        }
    }
    cout << "How many copies do you want to buy: ";
    int copiesToBuy;
    cin >> copiesToBuy;
    if(copiesToBuy > booksarray[index].getcopies()){
        cout << "Required copies not in stock" << endl;
    } else {
        cout << "Total cost of copies: " << copiesToBuy * booksarray[index].getprice() << endl;
    }
    return 0;
}