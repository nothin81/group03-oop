#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    int id;
    string name;
    string genre;
    int duration;
    // 01; John Wick 4; Action; 169
    Movie setMovie(int id, string name, string genre, int duration);
    void display();
};

Movie Movie::setMovie(int id, string name, string genre, int duration)
{
    this->id = id;
    this->name = name;
    this->genre = genre;
    this->duration = duration;
}
void Movie::display()
{
    cout << "[" << id << "] " << name << " - " << genre
         << " (" << duration << " minutes)" << endl;
}
