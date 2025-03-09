#include <iostream>
#include <string>
using namespace std;

class books{
    string genre;
    public:
    books(){
        genre = "";
    }
    books(string genre){
        this->genre = genre;
    }

    string getGenre() {
        return genre;
    }

};

class novel: public books{
    string title;
    string author;
    public:
    novel(){
        title = "";
        author = "";
    }
    novel(string genre, string title, string author): books(genre){
        this->title = title;
        this->author = author;
    }

    string getTitle(){
        return title;
    }

    string getAuthor(){
        return author;
    }
    void displayInfo(){
        cout << "Genre: " << getGenre() << ", Title: " << getTitle() << ", Author: " << getAuthor() << endl;
    }
};

class Mystery : public books {
    private:
        string title;
        string author;
    public:
        Mystery(string g, string t, string a) : books(g), title(t), author(a) {}
    
        string getTitle() {
            return title;
        }
        string getAuthor() {
            return author;
        }
        
        void displayInfo() {
            cout << "Genre: " << getGenre() << ", Title: " << getTitle() << ", Author: " << getAuthor() << endl;
        }
    };

    int main(){
        novel n("Mystery", "The Da Vinci Code", "Dan Brown");
        n.displayInfo();
        Mystery m("Mystery", "The Da Vinci Code", "Dan Brown");
        m.displayInfo();
        return 0;
    }