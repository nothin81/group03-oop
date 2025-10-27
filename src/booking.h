#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <vector>
#include <string>
#include "movie.h"

class Booking {
private:
    int bookingId;
    std::string bookingName;
    Movie movie;
    int cinemaId;
    int seatNumber;
    std::string status;
    std::vector<bool> seats;
    static int currentId;
    static const int TOTAL_SEATS = 50;

public:
    Booking();
    static int readFile();
    void createBooking();
    void displayAvailableSeats() const;
    bool bookSeat(int seatNum);
    void saveBooking() const;
    static void printData();
    void displayBookingDetails() const;
};

#endif