#include <iostream>
#include <string>
using namespace std;

struct patrons
{
    string full_name;
    double fund;
};

int main()
{
    int patrons_number;
    cout << "Enter the number of patrons number: ";
    cin >> patrons_number;

    patrons *p = new patrons[patrons_number];
    cin.get();

    for (int i = 0; i < patrons_number; ++i)
    {
        cout << "#" << i + 1 << ": " << endl;
        cout << "Enter the patron's full name: ";
        getline(cin, p[i].full_name);
        cout << "Enter the patron's fund: ";
        cin >> p[i].fund;
        cin.get();
    }

    int i;
    cout << endl
         << "Patron who's fund is bigger than 10000: " << endl
         << "Grand Patrons: " << endl;

    for (i = 0; i < patrons_number; ++i)
    {
        if (p[i].fund >= 10000)
            cout << p[i].full_name << " : " << p[i].fund << endl;
    }
    if (i == 0)
        cout << "NONE" << endl;

    cout << endl
         << "Patrons: " << endl;
    for (i = 0; i < patrons_number; ++i)
    {
        if (p[i].fund < 10000)
            cout << p[i].full_name << " : " << p[i].fund << endl;
    }
    if (i == 0)
        cout << "NONE" << endl;

    delete[] p;
    return 0;
}
