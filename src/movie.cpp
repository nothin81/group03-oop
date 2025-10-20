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
    Movie(int id, string& title, const int release_year, const string& genre, int runtime);
    ~Movie();
    void display();

    void setTitle(string title);
    void setGenre(string genre);
    void setRuntime(int runtime);

    int getId();
    string getTitle();
    string getGenre();
    int getRuntime();

    void addMovie();
};

Movie::Movie(int id, string& title, const int release_year, const string& genre, int runtime)
    : id(id), title(title), release_year(release_year), genre(genre), runtime(runtime){}

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
    cout << "Nhap vao ten phim: ";
    std::getline 
}

void Movie::display()
{
    cout << "[" << id << "] " << name << " - " << genre
         << " (" << duration << " minutes)" << endl;
}
