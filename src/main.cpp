#include <iostream>
#include "movie.cpp"
using namespace std;

int main()
{
    Movie m;
    m.addMovie();
    m.display();
    m.writeFileEntry();

    cout << "\nĐọc lại danh sách từ file:\n";
    Movie::readFileEntry();
    return 0;
}
