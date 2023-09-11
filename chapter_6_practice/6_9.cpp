#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct patrons
{
    string full_name;
    double fund;
};

int main()
{
    ifstream fin;
    fin.open("patrons.txt");

    if (!fin.is_open())
    {
        cout << "Error open file!\n";
        exit(EXIT_FAILURE);
    }

    int patrons_number;

    fin >> patrons_number;
    fin.get();

    patrons *p = new patrons[patrons_number];

    int i;
    for (i = 0; i < patrons_number; ++i)
    {
        getline(fin, p[i].full_name);
        fin >> p[i].fund;
        fin.get();
    }

    fin.close();

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