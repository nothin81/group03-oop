#ifndef CINEMA_H
#define CINEMA_H

#include <string>
using std::string;

class Cinema {
private:
    int id;
    string name;
    string address;
    int screeningRoom;
    static int currentId;  // ID track trong file

public:
    Cinema();
    Cinema(int id, string name, string address, int screeningRoom);
    
    int getId() const;
    string getName() const;
    string getAddress() const;
    int getScreeningRoom() const;
    
    void setId(int id);
    void setName(string name);
    void setAddress(string address);
    void setScreeningRoom(int screeningRoom);
    
    static int readFile();
    static void showData();
    void writeFile() const;

    void addCinema();
    void display() const;
};

#endif