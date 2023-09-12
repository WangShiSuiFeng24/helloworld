// strgback.cpp -- a function that returns a pointer to char
#include <iostream>
char *buildstr(char c, int n);

int main()
{
    using namespace std;
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;

    char *ps = buildstr(ch, times);
    cout << ps << endl;

    delete[] ps;
    ps = buildstr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete[] ps;
    return 0;
}

char * buildstr(char c, int n)
{
    char *str = new char[n + 1];
    str[n] = '\0';
    while (n-- > 0)
        str[n] = c;
    return str;
}

