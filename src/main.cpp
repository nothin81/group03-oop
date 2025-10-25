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

void displayCinemaMenu()
{
    cout << "\nQUAN LY RAP CHIEU:\n"
         << "\t1. Them vao rap chieu moi\n"
         << "\t2. Xem danh sach rap\n"
         << "\t0. Quay lai\n"
         << "Lua chon cua ban: ";
}

void displayBookingMenu()
{
    cout << "\nQUAN LY DAT VE:\n"
         << "\t1. Dat ve moi\n"
         << "\t2. Xem danh sach ve\n"
         << "\t0. Quay lai\n"
         << "Lua chon cua ban: ";
}

int main()
{   
    Movie mov;
    Cinema cine;
    Booking booking;
    int choice;
   
    while(true)
    {
        
    }
    return 0;
}
