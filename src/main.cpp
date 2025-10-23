#include <iostream>
#include "movie.h"
#include "booking.h"
using namespace std;

void intro()
{
    cout << "=== UNG DUNG DAT PHIM ===\n";
    cout << "";
    cout << "";
    cout << "";
    cout << "";
    cout << "";
    
}

int main()
{
    intro();
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
