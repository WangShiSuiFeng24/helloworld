#include <iostream>
#include <string>
using namespace std;
struct car
{
    string brand;
    int year;
};

int main()
{
    int num_of_car;
    cout << "How many cars do you wish to catalog? ";
    cin >> num_of_car;
    cin.get();

    car *pc = new car[num_of_car];

    int i;
    for (i = 0; i < num_of_car; i++)
    {
        cout << "Car #" << i + 1 << ":" << endl;
        cout << "Please enter the maker: ";
        getline(cin, pc[i].brand);
        cout << "Please enter the year made: ";
        cin >> pc[i].year;
        cin.get();
    }

    cout << "Here is you collection:" << endl;
    for (i = 0; i < num_of_car; i++)
    {
        cout << pc[i].year << " " << pc[i].brand << endl;
    }
    delete[] pc;
    return 0;
}