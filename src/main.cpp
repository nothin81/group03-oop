#include <iostream>
#include "movie.h"
#include "booking.h"
using namespace std;

void displayHeader()
{
    cout << "========================================\n"
         << "          UNG DUNG DAT VE PHIM        \n"
         << "========================================\n";
}

int main()
{
    displayHeader();
    Movie m;
    while(true)
    {
    m.addMovie();
    m.display();
    m.writeFileEntry();

    cout << "\nDoc File:\n";
    Movie::readFileEntry();

    Booking b;
    b.createBooking();
    }
    return 0;
}
