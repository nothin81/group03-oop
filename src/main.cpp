#include <iostream>
#include "movie.cpp"
using namespace std;

int main()
{
    Movie m;
    m.setMovie(01, "John Wick 4", "Action", 169);
    m.display();
    return 0;
}
