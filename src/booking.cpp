#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "booking.h"
#include "movie.h"

using namespace std;

int Booking::currentId = 0;

Booking::Booking()
{
    bookingId = -1;
    seats.resize(TOTAL_SEATS, false);  // Initialize all seats as available
    status = "Available";
}

int Booking::readFile() {
    ifstream file("./data/bookings.txt");
    if (!file.is_open()) {
        return 0;   //tra 0 neu k ton tai file
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ';');
        try {
            int currentId = stoi(id);
            if (currentId > Booking::currentId) {
                Booking::currentId = currentId;
            }
        } catch (...) {
            continue;
        }
    }
    file.close();
    return Booking::currentId;
}

void Booking::createBooking()
{
    currentId = readFile();
    bookingId = ++currentId;

    cout << "\n==== Tao Booking Moi! ====\n";
    cout << "Nhap vao ten dat cho (booking name): ";
    getline(cin, bookingName);

    // Display available movies
    cout << "\nPhim dang chieu:\n";
    Movie::printData();     //static void

    cout << "\nNhap vao ID Phim can dat cho: ";
    int movieId;
    cin >> movieId;
    cin.ignore();

    // Load movie tu file
    ifstream movieFile("./data/movies.txt");
    if (!movieFile.is_open()) {
        cout << "# Khong the mo file movies.txt\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(movieFile, line)) {
        stringstream ss(line);
        string id, title, year, genre, runtime;
        
        getline(ss, id, ';');
        getline(ss, title, ';');
        getline(ss, year, ';');
        getline(ss, genre, ';');
        getline(ss, runtime, ';');
        
        if (stoi(id) == movieId)    //kiem tra 
        {
            movie = Movie(stoi(id), title, stoi(year), genre, stoi(runtime));
            found = true;
            break;
        }
    }
    movieFile.close();

    if (!found)
    {
        cout << "Khong tim thay phim!\n";
        return;
    }

    displayAvailableSeats();
    
    cout << "Nhap so ghe (1-" << TOTAL_SEATS << "): ";
    cin >> seatNumber;
    cin.ignore();

    if (bookSeat(seatNumber)) {
        status = "Booked";
        saveBooking();
        displayBookingDetails();
    }
}

void Booking::displayAvailableSeats() const     //console mac dinh windows 120x30 
{
    cout << "\nSo do cho ngoi:\n";
    for (int i = 0; i < TOTAL_SEATS; i++)
    {
        if (!seats[i]) {
            cout << (i + 1) << " ";
        } else {
            cout << "X ";
        }
        if ((i + 1) % 10 == 0) cout << "\n";
    }
    cout << endl;
}

bool Booking::bookSeat(int seatNum)
{
    if (seatNum < 1 || seatNum > TOTAL_SEATS)
    {
        cout << "So ghe khong hop le!\n";
        return false;
    }
    if (seats[seatNum - 1])
    {
        cout << "Ghe da duoc dat!\n";
        return false;
    }
    seats[seatNum - 1] = true;
    return true;
}

void Booking::saveBooking() const
{
    ofstream file("./data/bookings.txt", ios::app);
    if (file.is_open()) {
        file << bookingId << ";"
             << bookingName << ";"
             << movie.getId() << ";"
             << seatNumber << ";"
             << status << "\n";
        file.close();
    }
}

void Booking::printData() {
    ifstream file("./data/bookings.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file bookings.txt\n";
        return;
    }

    string line;
    cout << "\n=== Danh sach Booking ===\n";
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, movieId, seat, status;
        
        getline(ss, id, ';');
        getline(ss, name, ';');
        getline(ss, movieId, ';');
        getline(ss, seat, ';');
        getline(ss, status, ';');
        
        cout << "Booking #" << id << "\n"
                 << "Ten: " << name << "\n"
                 << "Ma phim: " << movieId << "\n"
                 << "Ghe: " << seat << "\n"
                 << "Trang thai: " << status << "\n"
                 << "-------------------\n";
    }
    file.close();
}

void Booking::displayBookingDetails() const
{
    cout << "\n=== Chi tiet Booking ===\n"
         << "Ma booking: " << bookingId << "\n"
         << "Ten: " << bookingName << "\n"
         << "Ghe: " << seatNumber << "\n"
         << "Trang thai: " << status << "\n";
}

