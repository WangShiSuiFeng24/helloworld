#include <iostream>
#include "sales.h"

using namespace std;
using namespace SALES;

void SALES::setSales(Sales & s, const double ar[], int n)
{
    double sum = 0;
    if (n >= QUARTERS)
    {
        for (int i = 0; i < QUARTERS; ++i)
            s.sales[i] = ar[i];
    }
    else
    {
        for (int i = 0; i < n; ++i)
            s.sales[i] = ar[i];
        for (int i = n; i < QUARTERS; ++i)
            s.sales[i] = 0;
    }

    s.max = s.min = s.sales[0];
    for (int i = 0; i < QUARTERS; ++i)
    {
        sum += s.sales[i];
        if (s.sales[i] > s.max)
            s.max = s.sales[i];
        if (s.sales[i] < s.min)
            s.min = s.sales[i];
    }
    s.average = sum / QUARTERS;
}

void SALES::setSales(Sales & s)
{
    double ar[QUARTERS] = {};
    int i = 0;
    do 
    {
        cout << "Enter a number: ";
        if (!(cin >> ar[i]))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "ERROE, Reenter a number: ";
        }
        ++i;
    } while (i < QUARTERS);

    setSales(s, ar, 4);
}

void SALES::showSales(const Sales & s)
{
    cout << "This Sale's quarter list info:" << endl;
    for (int i = 0; i < QUARTERS; ++i)
        cout << "No." << i + i << ": sales: " << s.sales[i] << endl;
    cout << "AVERAGE: " << s.average << endl;
    cout << "MAX: " << s.max << endl;

    cout << "MIN: " << s.min << endl;
}