#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "movie.h"
using namespace std;

int Movie::currentId = 1;

int Movie::getId() const {return id;}
string Movie::getTitle() const {return title;}
int Movie::getReleaseYear() const { return release_year;}
string Movie::getGenre() const { return genre;}
int Movie::getRuntime() const { return runtime;}

void Movie::setTitle(string title) {this->title = title;}
void Movie::setReleaseYear(int release_year) {this->release_year = release_year;}
void Movie::setGenre(string genre) {this->genre = genre;}
void Movie::setRuntime(int runtime) { this->runtime = runtime;}

int Movie::readFile()
{
    ifstream movie_file("./data/movies.txt");
    if (!movie_file.is_open()) {
        return 1; // Tra ve 1 neu file k ton tai
    }

    string movie_line;
    while (getline(movie_file, movie_line)) {
        stringstream movie_ss(movie_line);
        string i_id;
        getline(movie_ss, i_id, ';');
        try {
            int id = stoi(i_id);
            if (id > currentId) {
                currentId = id;
            }
        } catch (...) {
            continue;
        }
    }
    movie_file.close();
    return currentId;
}

void Movie::addMovie()
{
    currentId = readFile(); // Get last ID from file
    id = ++currentId; // Increment and use next ID
    
    cout << "Nhap vao ten phim: ";
    getline(cin, title);

    cout << "Nhap vao nam phat hanh: ";
    cin >> release_year;
    cin.ignore();

    cout << "Nhap vao the loai phim: ";
    getline(cin, genre);

    cout << "Nhap vao thoi gian phim (m): ";
    cin >> runtime;
    cin.ignore();
}

void Movie::printData()
{
    ifstream fm_in("./data/movies.txt");
    if (!fm_in.is_open())
    {
        cout << "### Khong mo duoc file movies.txt! ###" << endl;
        return;
    }

    string entry;
    cout << "\n===== DANH SACH PHIM =====\n";
    while (getline(fm_in, entry))
    {
        stringstream ss(entry);
        string i_id, s_title, i_release_year, s_genre, i_runtime;

        getline(ss, i_id, ';');
        getline(ss, s_title, ';');
        getline(ss, i_release_year, ';');
        getline(ss, s_genre, ';');
        getline(ss, i_runtime, ';');

        cout << "[" << i_id << "] " << s_title << " (" << i_release_year << ")"
             << " - " << s_genre << " (" << i_runtime << " minutes)" << endl;
    }
    fm_in.close();
}

void Movie::writeFile()
{
    ofstream fm_out("./data/movies.txt", ios::app);
    if (fm_out.is_open())
    {
        fm_out << id << ";" << title << ";" << release_year << ";" << genre << ";" << runtime << "\n";
        fm_out.close();
    } else {
        cout << "### Khong mo duoc file movies.txt! ###" << endl;
    }
}

void Movie::display()   //khong dung
{
    cout << "[" << id << "] " << title << " - " << genre << " (" << runtime << " minutes)" << endl;
}
