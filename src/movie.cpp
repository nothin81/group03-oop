#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "movie.h"
using namespace std;

Movie::Movie()
{
    id = -1;
    title = "Unknown";
    release_year = 2077;
    genre = "Unknown, Unknown";
    runtime = 0;
}

int Movie::getId()
{
    return id;
}

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
    static int nextId = 0;
    id = nextId++;
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
    ifstream fm_in("../data/movies.txt");
    if (!fm_in.is_open())
    {
        cout << "### Khong mo duoc file movies.txt! ###" << endl;
        return;
    }

    string s_entry;
    cout << "\n===== DANH SACH PHIM =====\n";
    while (getline(fm_in, s_entry))
    {
        stringstream ss(s_entry);
        string i_id, s_title, s_genre, i_runtime;

        getline(ss, i_id, ';');
        getline(ss, s_title, ';');
        getline(ss, s_genre, ';');
        getline(ss, i_runtime, ',');

        int id = stoi(i_id);    //str -> int
        int runtime = stoi(i_runtime);

        cout << "[" << i_id << "] " << s_title << " - " << s_genre << " (" << i_runtime << " minutes)" << endl;
    }
    fm_in.close();
}

void Movie::writeFileEntry()
{
    ofstream fm_out("movies.txt", ios::app);
    if (fm_out.is_open())
    {
        fm_out << id << "," << title << "," << genre << "," << runtime << "\n";
        fm_out.close();
    } else {
        cout << "### Khong mo duoc file movies.txt! ###" << endl;
    }
}

void Movie::display()
{
    cout << "[" << id << "] " << title << " - " << genre << " (" << runtime << " minutes)" << endl;
}
