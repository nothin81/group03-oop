#include <iostream>
#include <fstream>
#include <sstream>
#include "cinema.h"

using namespace std;

int Cinema::currentId = 0;

Cinema::Cinema()
{
    id = -1;
    name = "Unknown";
    address = "Unknown";
    screeningRoom = 0;
}

Cinema::Cinema(int id, string name, string address, int screeningRoom)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->screeningRoom = screeningRoom;
}

int Cinema::getId() const { return id; }
string Cinema::getName() const { return name; }
string Cinema::getAddress() const { return address; }
int Cinema::getScreeningRoom() const { return screeningRoom; }

void Cinema::setId(int id) { this->id = id; }
void Cinema::setName(string name) { this->name = name; }
void Cinema::setAddress(string address) { this->address = address; }
void Cinema::setScreeningRoom(int screeningRoom) { this->screeningRoom = screeningRoom; }

int Cinema::readFile() {
    ifstream file("./data/cinemas.txt");
    if (!file.is_open()) {
        return 0;  // tra ve 0 neu file k ton tai
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id_str;
        getline(ss, id_str, ';');
        try {
            int id = stoi(id_str);
            if (id > currentId) {
                currentId = id;
            }
        } catch (...) {
            continue;
        }
    }
    file.close();
    return currentId;
}

void Cinema::addCinema()
{
    currentId = readFile();  // lay id tu doc file
    id = ++currentId;       // fix su dung
    
    cout << "Nhap ten rap: ";
    getline(cin, name);
    
    cout << "Nhap dia chi: ";
    getline(cin, address);
    
    cout << "Nhap so phong chieu: ";
    cin >> screeningRoom;
    cin.ignore();
}

void Cinema::writeFile() const
{
    ofstream file("./data/cinemas.txt", ios::app);
    if (file.is_open()) {
        file << id << ";" << name << ";" << address << ";" << screeningRoom << "\n";
        file.close();
    } else {
        cout << "### Khong mo duoc file cinemas.txt! ###" << endl;
    }
}

void Cinema::showData() {
    ifstream file("./data/cinemas.txt");
    if (!file.is_open()) {
        cout << "### Khong mo duoc file cinemas.txt! ###" << endl;
        return;
    }

    string line;
    cout << "\n===== DANH SACH RAP =====\n";
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, address, room;
        
        getline(ss, id, ';');
        getline(ss, name, ';');
        getline(ss, address, ';');
        getline(ss, room, ';');
        
        cout << "[" << id << "] " << name 
             << "\nDia chi: " << address 
             << "\nSo phong chieu: " << room << "\n-------------------\n";
    }
    file.close();
}