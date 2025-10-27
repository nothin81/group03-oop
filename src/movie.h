#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using std::string;

class Movie
{
private:
    int id;
    string title;
    int release_year;
    string genre;
    int runtime;
    static int currentId; // ID track khi load file

public:
    Movie()  //test default values
    {
        id = -1;
        title = "Unknown";
        release_year = 2999;
        genre = "Unknown, Unknown";
        runtime = 0;
    }
    Movie(int id, string& title, int release_year, string& genre, int runtime)
    {
        this->id = id;
        this->title = title;
        this->release_year = release_year;
        this->genre = genre;
        this->runtime = runtime;
    }
    void display();

    void setTitle(string title);
    void setReleaseYear(int release_year);
    void setGenre(string genre);
    void setRuntime(int runtime);

    int getId() const;
    string getTitle() const;
    int getReleaseYear() const;
    string getGenre() const;
    int getRuntime() const;

    void addMovie();
    static int readFile();
    void writeFile();
    static void printData();
};

#endif