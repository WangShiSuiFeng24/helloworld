#include <iostream>
const int Seasons = 4;

const char *Snames[Seasons] = {
    "Spring", "Summer", "Fall", "Winter"};

void fill(double[], int);
void show(double[], int);

int main()
{
    double expenses[Seasons];
    fill(expenses, Seasons);
    show(expenses, Seasons);
    return 0;
}

void fill(double arr[], int size)
{
    using namespace std;
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> arr[i];
    }
}

void show(double arr[], int size)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < size; ++i)
    {
        cout << Snames[i] << ": $" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total Expenses: $" << total << endl;
}