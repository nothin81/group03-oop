#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <vector>
#include <string>
#include "movie.h"

using namespace std;

class Booking
{
private:
    string bookingName;
    Movie movie;
    int seatNumber;
    string status;       // con trong :"V" , da book : "K"
    vector<bool> seats;  // true if seat is taken, false if available
    const int TOTAL_SEATS = 50;  // Example total seats

public:
    Booking();
    void createBooking();
    void displayAvailableSeats() const;
    bool bookSeat(int seatNum);
    void saveBooking() const;
    static void viewAllBookings();
    void displayBookingDetails() const;
};

#endif