#include <iostream>
#include <fstream>
// #include <cstdlib>
int main()
{
    using namespace std;
    ifstream fin;
    fin.open("carinfo.txt");

    if (!fin.is_open())
    {
        cout << "Open file failure!";
        exit(EXIT_FAILURE);
    }
    char ch;
    int count = 0;
    while (fin.get(ch))
        ++count;

    cout << "There are " << count << " characters in the file.";
    fin.close();
    return 0;
}