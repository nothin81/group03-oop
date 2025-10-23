#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>
#include <vector>
#include <string>

class Cinema {
private:
    int id;
    std::string name;
    std::string address;
    int screeningRoom;

public:
    Cinema();
    Cinema(int id, std::string name, std::string address, int screeningRoom);
    
    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    int getScreeningRoom() const;
    
    void setId(int id);
    void setName(std::string name);
    void setAddress(std::string address);
    void setScreeningRoom(int screeningRoom);
    
    void addCinema();
    void display() const;
    static void readFileEntry();
    void writeFileEntry() const;
};

#endif