#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(const string& title, const string& pubDate, const string& id, const string& pub)
        : title(title), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }
    void checkout(){
        cout << "Media checked out." << endl;
    }
    void returnitem(){
        cout << "Media returned." << endl;
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(const string& title, const string& pubDate, const string& id, const string& pub,
         const string& author, const string& isbn, int pages)
        : Media(title, pubDate, id, pub), author(author), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nNumber of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director;
    string duration;
    string rating;

public:
    DVD(const string& title, const string& pubDate, const string& id, const string& pub,
        const string& director, const string& duration, const string& rating)
        : Media(title, pubDate, id, pub), director(director), duration(duration), rating(rating) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << "\nRating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(const string& title, const string& pubDate, const string& id, const string& pub,
       const string& artist, int tracks, const string& genre)
        : Media(title, pubDate, id, pub), artist(artist), numberOfTracks(tracks), genre(genre) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media {
    string genre;
    string language;

public:
    Magazine(const string& title, const string& pubDate, const string& id, const string& pub,
             const string& genre, const string& lang)
        : Media(title, pubDate, id, pub), genre(genre), language(lang) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Genre: " << genre << "\nLanguage: " << language << endl;
    }
};

class Library {
    Media* mediaList[100];
    int size;

public:
    Library(Media* media[], int count) : size(count) {
        for (int i = 0; i < count; ++i) {
            mediaList[i] = media[i];
        }
    }

    void searchMedia(const string& title) const {
        for (int i = 0; i < size; ++i) {
            if (mediaList[i]->getTitle() == title) {
                mediaList[i]->displayInfo();
                return;
            }
        }
        cout << "Media with title \"" << title << "\" not found." << endl;
    }

    void searchMedia(const string& attribute, const string& value) const {
        for (int i = 0; i < size; ++i) {
            if (attribute == "publicationDate" && mediaList[i]->getPublicationDate() == value) {
                mediaList[i]->displayInfo();
                return;
            }
        }
        cout << "Media with " << attribute << " \"" << value << "\" not found." << endl;
    }

    void displayAll() const {
        for (int i = 0; i < size; ++i) {
            mediaList[i]->displayInfo();
            cout << "----------------------------\n";
        }
    }

    ~Library() {
        for (int i = 0; i < size; ++i) {
            delete mediaList[i];
        }
    }
};

int main() {
    Media* mediaItems[] = {
        new Book("1984", "1949-06-08", "B002", "Secker & Warburg", "George Orwell", "9780451524935", 328),
        new DVD("The Dark Knight", "2008-07-18", "D002", "Warner Bros.", "Christopher Nolan", "152 min", "PG-13"),
        new CD("Abbey Road", "1969-09-26", "C002", "Apple Records", "The Beatles", 17, "Rock"),
        new Magazine("Time", "2022-05-01", "M002", "Time Inc.", "May 2022", "Edward Felsenthal")
    };

    Library library(mediaItems, 4);

    cout << "Displaying all media items in the library:\n";
    library.displayAll();

    cout << "\nSearching for media with title \"The Dark Knight\":\n";
    library.searchMedia("The Dark Knight");

    cout << "\nSearching for media with publication date \"1969-09-26\":\n";
    library.searchMedia("publicationDate", "1969-09-26");

    cout << "\nSearching for media with title \"1984\":\n";
    library.searchMedia("1984");

    cout << "\nSearching for media with publication date \"2030-05-01\":\n";
    library.searchMedia("publicationDate", "2030-05-01");
    cout << "\nSearching for media with title \"Nonexistent Title\":\n";
    library.searchMedia("Nonexistent Title");

    return 0;
}