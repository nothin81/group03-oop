#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using std::string;

class Movie {
private:
    int id;
    string title;
    int release_year;
    string genre;
    int runtime;

public:
    Movie(); //constructor 
    // Movie(int id, string& title, int release_year, string& genre, int runtime)  //test default values
    // {
    //     id = -1;
    //     title = "Unknown";
    //     release_year = 2999;
    //     genre = "Unknown, Unknown";
    //     runtime = 0;
    // }
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
    void setGenre(string genre);
    void setRuntime(int runtime);

    int getId();
    string getTitle();
    string getGenre();
    int getRuntime();

    void addMovie();
    static void readFileEntry();   //k can obj;
    void writeFileEntry();
};

#endif