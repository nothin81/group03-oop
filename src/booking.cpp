#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "booking.h"
#include "movie.h"

using namespace std;

Booking::Booking()
{
    seats.resize(TOTAL_SEATS, false);  // Initialize all seats as available
    status = "Available";
}

void Booking::createBooking()
{
    cout << "\n==== Tao Booking Moi! ====\n";
    cout << "Enter booking name: ";
    getline(cin, bookingName);

    // Display available movies
    cout << "\nAvailable Movies:\n";
    Movie::readFileEntry();

    cout << "\nEnter movie ID to book: ";
    int movieId;
    cin >> movieId;
    cin.ignore();

    // Load movie tu file
    ifstream movieFile("./movies.txt");
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
        cout << "Movie not found!\n";
        return;
    }

    displayAvailableSeats();
    
    cout << "Enter seat number (1-" << TOTAL_SEATS << "): ";
    cin >> seatNumber;
    cin.ignore();

    if (bookSeat(seatNumber)) {
        status = "Booked";
        saveBooking();
        displayBookingDetails();
    }
}

void Booking::displayAvailableSeats() const
{
    cout << "\nAvailable Seats:\n";
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (!seats[i]) {
            cout << (i + 1) << " ";
        }
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

bool Booking::bookSeat(int seatNum)
{
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        cout << "Invalid seat number!\n";
        return false;
    }
    if (seats[seatNum - 1]) {
        cout << "Seat already taken!\n";
        return false;
    }
    seats[seatNum - 1] = true;
    return true;
}

void Booking::saveBooking() const
{
    ofstream bookingFile("./bookings.txt", ios::app);
    if (bookingFile.is_open()) {
        bookingFile << bookingName << ";"
                   << movie.getId() << ";"
                   << movie.getTitle() << ";"
                   << seatNumber << ";"
                   << status << "\n";
        bookingFile.close();
    }
}

void Booking::viewAllBookings()
{
    ifstream bookingFile("./bookings.txt");
    string line;
    
    cout << "\n=== All Bookings ===\n";
    while (getline(bookingFile, line)) {
        stringstream ss(line);
        string name, movieId, title, seat, status;
        
        getline(ss, name, ';');
        getline(ss, movieId, ';');
        getline(ss, title, ';');
        getline(ss, seat, ';');
        getline(ss, status, ';');
        
        cout << "Booking Name: " << name << "\n"
             << "Movie: " << title << " (ID: " << movieId << ")\n"
             << "Seat: " << seat << "\n"
             << "Status: " << status << "\n"
             << "-------------------\n";
    }
    bookingFile.close();
}

void Booking::displayBookingDetails() const
{
    cout << "\n=== Xac Nhan Thong Tin ===\n"
         << "Name: " << bookingName << "\n"
         << "Movie: " << movie.getTitle() << "\n"
         << "Seat Number: " << seatNumber << "\n"
         << "Status: " << status << "\n";
}

