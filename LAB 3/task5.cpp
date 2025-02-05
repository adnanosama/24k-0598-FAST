#include <iostream>
#include <string>

using namespace std;

class Book{
    private:
        string name;
        int ISBN;
        string authername;
        string publisher;
    public:
        Book(string name, int ISBN, string authername, string publisher){
            this->name = name;
            this->ISBN = ISBN;
            this->authername = authername;
            this->publisher = publisher;
        }
        void getBookInfo(){
            cout << "Book Name: " << name << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Auther Name: " << authername << endl;
            cout << "Publisher: " << publisher << endl;
        }
        void setname(string name){
            this->name = name;
        }
        void setISBN(int ISBN){
            this->ISBN = ISBN;
        }
        void setauthername(string authername){
            this->authername = authername;
        }
        void setpublisher(string publisher){
            this->publisher = publisher;
        }


};

int main(){
    Book books[5] = {
        Book("Time", 123, "illusive", "unseen"),
        Book("Of the Infinity", 124, "kullu", "hypothetical"),
        Book("Black holes", 125, "Fake", "Unreal"),
        Book("Which raise", 126, "Diappear", "Foreseen"),
        Book("The questions about universe", 127, "NO one", "can be seen")
    };
    for (int i = 0; i < 5; i++)
    {
        books[i].getBookInfo();
        cout <<"\n"<<endl;
    }
    
}

