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

}
int main()
{   
    Movie mov;
    Cinema cine;
    Booking booking;
    int choice;

    displayHeader();
    
    while(true)
    {
    }
    return 0;
}
