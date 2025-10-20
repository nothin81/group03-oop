#include <iostream>
#include "movie.h"
using namespace std;

int main()
{
    Movie m;
    m.addMovie();
    m.display();
    m.writeFileEntry();

    cout << "\nDoc File:\n";
    Movie::readFileEntry();
    return 0;
}
