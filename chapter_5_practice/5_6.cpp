#include <iostream>
#include <string>
using namespace std;
const int Years = 3;
const int Months = 12;
const string months[Months] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const string years[] =
    {
        "first", "second", "third"};
int main()
{
    int sale_amount[Years][Months] = {};

    int year, month;
    int total_amount = 0;
    for (year = 0; year < Years; ++year)
    {
        int year_mount = 0;
        for (month = 0; month < Months; ++month)
        {
            cout << "Enter the sale amount of the " << years[year] << " year " << months[month] << ": ";
            cin >> sale_amount[year][month];
            year_mount += sale_amount[year][month];
        }
        cout << "The " << years[year] << " year's sale amount is " << year_mount << endl;
        total_amount += year_mount;
    }
    cout << "The total sale amount in three years is " << total_amount << endl;
    return 0;
}