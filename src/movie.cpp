#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    int id;
    string title;
    int release_year;
    string genre;
    int runtime;

public:
    Movie(); //constructor 
    Movie(int id, string& title, int release_year, string& genre, int runtime)
    {
        id = -1;
        title = "Unknown";
        release_year = 2999;
        genre = "Unknown, Unknown";
        runtime = 0;
    }

    void display();

    void setTitle(string title);
    void setGenre(string genre);
    void setRuntime(int runtime);

    int getId();
    string getTitle();
    string getGenre();
    int getRuntime();

    void addMovie();
    void readFileEntry();
    void writeFileEntry();
};

void Movie::setTitle(string title)
{
    this->title = title;
}

string Movie::getTitle() 
{
    return title;
}

void Movie::setGenre(string genre)
{
    this->genre = genre;
}

string Movie::getGenre() 
{
    return genre;
}

void Movie::setRuntime(int runtime)
{
    this->runtime = runtime;
}

int Movie::getRuntime() 
{
    return runtime;
}

void Movie::addMovie()
{
    id++;
    cout << "Nhap vao ten phim: ";
    getline(cin, title);
    // cin.ignore();

    cout << "\nNhap vao the loai phim: ";
    getline(cin, genre);
    // cin.ignore();

    cout << "\nNhap vao thoi gian phim (m): ";
    cin >> runtime;
    cin.ignore();

}

void Movie::readFileEntry()
{

}

void Movie::writeFileEntry()
{
    
}

void Movie::display()
{
    cout << "[" << id << "] " << title << " - " << genre << " (" << runtime << " minutes)" << endl;
}
