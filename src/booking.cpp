#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "booking.h"
#include "movie.h"
#include "cinema.h"

using namespace std;

int Booking::currentId = 0;

Booking::Booking()
{
    bookingId = -1;
    seats.resize(TOTAL_SEATS, false);  // Initialize all seats as available
    status = "Available";
}

int Booking::readFile() {
    ifstream booking_file("./data/bookings.txt");
    if (!booking_file.is_open()) {
        return 1;   //tra 1 neu k ton tai file
    }
    int t_id;
    string line;
    while (getline(booking_file, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ';');
        try {
            t_id = stoi(id);
            if (t_id > currentId) {
                currentId = t_id;
            }
        } catch (...) {
            continue;
        }
    }
    booking_file.close();
    return currentId;   
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
    ifstream movie_file("./data/movies.txt");
    if (!movie_file.is_open()) {
        cout << "# Khong the mo file movies.txt\n";
        return;
    }

    string line;
    bool isfound = false;
    while (getline(movie_file, line)) {
        stringstream movie_ss(line);
        string id, title, year, genre, runtime;
        
        getline(movie_ss, id, ';');
        getline(movie_ss, title, ';');
        getline(movie_ss, year, ';');
        getline(movie_ss, genre, ';');
        getline(movie_ss, runtime, ';');
        
        if (stoi(id) == movieId)    //kiem tra 
        {
            movie = Movie(stoi(id), title, stoi(year), genre, stoi(runtime));
            isfound = true;
            break;
        }
    }
    movie_file.close();

    if (!isfound)
    {
        cout << "Khong tim thay phim!\n";
        return;
    }

    cout << "\nDanh sach rap chieu:\n";
    Cinema::showData();

    cout << "\nNhap vao ID Rap: ";
    cin >> cinemaId;
    cin.ignore();

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
            cout << " | " << (i + 1) << " | ";
        } else {
            cout << " | X  |";
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
    ofstream booking_file("./data/bookings.txt", ios::app);
    if (booking_file.is_open()) {
        booking_file << bookingId << ";"
             << bookingName << ";"
             << movie.getId() << ";"
             << cinemaId << ";"  // Add cinemaId de register cac cinema
             << seatNumber << ";"
             << status << "\n";
        booking_file.close();
    }
}

void Booking::printData()
{
    ifstream booking_file("./data/bookings.txt");
    if (!booking_file.is_open()) {
        cout << "Khong the mo file bookings.txt\n";
        return;
    }

    string line;
    cout << "\n=== Danh sach Booking ===\n";
    while (getline(booking_file, line)) {
        stringstream booking_ss(line);
        string id, name, movieId, cinemaId, seat, status;

        getline(booking_ss, id, ';');
        getline(booking_ss, name, ';');
        getline(booking_ss, movieId, ';');
        getline(booking_ss, cinemaId, ';');
        getline(booking_ss, seat, ';');
        getline(booking_ss, status, ';');

        ifstream cine_file("./data/cinemas.txt");
        string cine_name = "Unknown";
        string cine_addr = "Unknown";
        
        if (cine_file.is_open()) {
            string cine_line;
            while (getline(cine_file, cine_line)) {
                stringstream cineStream(cine_line);
                string cId, cName, cAddress, cRooms;    // bien tam thoi
                
                getline(cineStream, cId, ';');
                getline(cineStream, cName, ';');
                getline(cineStream, cAddress, ';');
                
                if (cId == cinemaId) {
                    cine_name = cName;
                    cine_addr = cAddress;
                    break;
                }
            }
            cine_file.close();
        }
        
        cout << "Booking #" << id << "\n"
             << "Ten: " << name << "\n"
             << "Ma phim: " << movieId << "\n"
             << "Rap: " << cine_name << "\n"
             << "Dia chi: " << cine_addr << "\n"
             << "Ghe: " << seat << "\n"
             << "Trang thai: " << status << "\n"
             << "-------------------\n";
    }
    booking_file.close();
}

void Booking::displayBookingDetails() const
{
    cout << "\n=== Chi tiet Booking ===\n"
         << "Ma booking: " << bookingId << "\n"
         << "Ten: " << bookingName << "\n"
         << "Ghe: " << seatNumber << "\n"
         << "Trang thai: " << status << "\n";
}

