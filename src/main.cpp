#include <iostream>
#include "cinema.h"
#include "movie.h"
#include "booking.h"
using namespace std;

void displayHeader()
{
    cout << "========================================\n"
         << "          UNG DUNG DAT VE PHIM        \n"
         << "========================================\n";
}
void displayMainMenu()
{
    cout << "\nMENU CHINH:\n"
         << "\t1. Quan ly phim\n"
         << "\t2. Quan ly rap\n"
         << "\t3. Quan ly dat ve\n"
         << "\t0. Thoat\n"
         << "Lua chon cua ban: ";
}

void displayMovieMenu()
{
    cout << "\nQUAN LY PHIM:\n"
         << "\t1. Them vao phim moi\n"
         << "\t2. Xem danh sach phim\n"
         << "\t0. Quay lai\n"
         << "Lua chon cua ban: ";
}

int movieMenu()
{
    int choice2;
    Movie mov;

    do {
        displayMovieMenu();
        cin >> choice2;
        cin.ignore();
        switch (choice2)
        {
            case 1:
                mov.addMovie();
                mov.writeFile();
                break;
            case 2:
                Movie::readFile();
                break;
        }
    } while (choice2 != 0);  //neu sai thi ve 0
    return 0;
}

void displayCinemaMenu()
{
    cout << "\nQUAN LY RAP CHIEU:\n"
         << "\t1. Them vao rap chieu moi\n"
         << "\t2. Xem danh sach rap\n"
         << "\t0. Quay lai\n"
         << "Lua chon cua ban: ";
}

int cinemaMenu()
{
    Cinema cine;
    int choice2;
    do {
        displayCinemaMenu();
        cin >> choice2;
        cin.ignore();
        switch (choice2) {
            case 1:
                cine.addCinema();
                cine.writeFile(); // bi trung lap ham nay
                break;
            case 2:
                Cinema::displayData();
                break;
        }
    } while (choice2 != 0);
    return 0;
}

void displayBookingMenu()
{
    cout << "\nQUAN LY DAT VE:\n"
         << "\t1. Dat ve moi\n"
         << "\t2. Xem danh sach ve\n"
         << "\t0. Quay lai\n"
         << "Lua chon cua ban: ";
}

int bookingMenu()
{
    Booking bookings;
    int choice2;
    do {
        displayBookingMenu();
        cin >> choice2;
        cin.ignore();
        switch (choice2) {
            case 1:
                bookings.createBooking();
                break;
            case 2:
                bookings.printData();
                break;
        
        }
    }while (choice2 != 0);
    return 0;
}

int main()
{   
    Movie mov;
    Cinema cine;
    Booking bookings;
    int choice;
   
    while(true)
    {
        displayHeader();
        displayMainMenu();
        if ( !(cin >> choice) )
        {
            cout << "# Hay nhap vao ki tu";
            cin.ignore();
        }

        switch (choice)
        {
            case 1:
                if (movieMenu() == 0)
                    break;
                case 2:
                if (cinemaMenu() == 0)
                    break;
            case 3:
                if (bookingMenu() == 0)
                    break;
            case 0:
                cout << "THOAT CHUONG TRINH!" << endl;
                return 0;
            default:
                cout << "# Lua chon khong hop le!" << endl;
        }

    }
    return 0;
}
