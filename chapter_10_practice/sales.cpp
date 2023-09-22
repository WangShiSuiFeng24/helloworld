// sales.cpp -- compile with 10_4.cpp
#include <iostream>
#include "sales.h"
using namespace SALES;

Sales::Sales()
{
    using std::cin;
    using std::cout;

    // double temp;
    int i = 0;
    do 
    {
        cout << "Enter a number: ";

        while (!(cin >> sales[i]))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "ERROR, Reenter a number: ";
        }
        // sales[i] = temp;
        i++;
    } while (i < QUARTERS);

    double sum = 0;
    max = min = sales[0];
    for (int i = 0; i < QUARTERS; ++i)
    {
        if (sales[i] > max)
            max = sales[i];
        if (sales[i] < min)
            min = sales[i];
        sum += sales[i];
    }
    average = sum / QUARTERS;
}

Sales::Sales(const double ar[], int n)
{
    double sum = 0;
    if (n > QUARTERS)
    {
        for (int i = 0; i < QUARTERS; ++i)
            sales[i] = ar[i];
    }
    else
    {
        for (int i = 0; i < n; ++i)
            sales[i] = ar[i];
    }

    max = min = sales[0];
    for (int i = 0; i < QUARTERS; ++i)
    {
        if (sales[i] > max)
            max = sales[i];
        if (sales[i] < min)
            min = sales[i];
        sum += sales[i];
    }
    average = sum / QUARTERS;
}

Sales::~Sales()
{

}

void Sales::showSales() const
{
    using std::cout;
    using std::endl;
    cout << "This Sales's quarter list info: " << endl;
    for (int i = 0; i < QUARTERS; ++i)
        cout << "No." << i + 1 << ": sales: " << sales[i] << endl;
    cout << "AVERAGE: " << average << endl;
    cout << "MAX: " << max << endl;
    cout << "MIN: " << min << endl;
}