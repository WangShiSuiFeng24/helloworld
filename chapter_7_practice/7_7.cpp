#include <iostream>
const int Max = 5;
double * fill_array(double *begin, double *end);
void show_array(const double *begin, const double *end);
void revalue(double r, double *begin, double *end);

int main()
{
    using namespace std;
    double properties[Max];

    double * pend = fill_array(properties, properties + Max);
    show_array(properties, pend);

    if (pend > properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, pend);
        show_array(properties, pend);
    }

    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

double * fill_array(double * begin, double * end)
{
    using namespace std;
    double temp;
    int i;
    while (begin < end)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
        }
        else if (temp < 0)
            break;
        *begin = temp;
        ++begin;
        ++i;
    }
    return begin;
}

void show_array(const double *begin, const double * end)
{
    using namespace std;
    int i = 0;
    while (begin < end)
    {
        cout << "Property #" << i + 1 << ": $";
        cout << *begin << endl;
        ++begin;
        ++i;
    }
}

void revalue(double r, double* begin, double * end)
{
    while (begin < end)
    {
        *begin *= r;
        ++begin;
    }
}