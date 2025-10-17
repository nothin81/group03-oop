#include <iostream>
#include <string>

using std::string;

class Movie
{
private:
    int id;
    string title;
    int runtime;

public:
    Movie getMovie(int id, string title, int runtime);
    void display();
};


