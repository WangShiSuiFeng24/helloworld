#include <iostream>
#include <cstring>
#include <new>
using namespace std;
struct chaff
{
    char dross[20];
    int slag;
};
int set_chaff(chaff &, char *, int);
void show_chaff(const chaff &);

int main()
{
    char buffer[1024];

    char st[20];
    int slag, n = 0;

    chaff *pcf = new (buffer) chaff[2];

    cout << "Enter String to set chaff: ";
    cin.getline(st, 20);
    cout << "Enter a number: ";
    cin >> slag;

    while (strlen(st) > 0)
    {
        cin.get();
        set_chaff(pcf[n++], st, slag);
        if (n >= 2)
            break;

        cout << "Enter String to set chaff: ";
        cin.getline(st, 20);
        cout << "Enter a number: ";
        cin >> slag;
    }
    for (int i = 0; i < 2; ++i)
        show_chaff(pcf[i]);

    return 0;
}

int set_chaff(chaff & cf, char * str, int n)
{
    if (strlen(str) > 0)
    {
        strcpy(cf.dross, str);
        cf.slag = n;
        return 1;
    }
    else
        return 0;
}

void show_chaff(const chaff & cf)
{
    cout << "Chaff's Dross: " << cf.dross << endl;
    cout << "Chaff's slag: " << cf.slag << endl;
}