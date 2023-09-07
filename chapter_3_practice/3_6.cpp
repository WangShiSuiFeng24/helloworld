#include <iostream>
using namespace std;

int main()
{
    float distance_in_mile, distance_in_km;
    float fuel_in_gallon, fuel_in_litre;
    float fuel_consume;

    cout << "Enter the distance in miles: ";
    cin >> distance_in_mile;
    cout << "Enter the fuel consume in gallon: ";
    cin >> fuel_in_gallon;
    fuel_consume = distance_in_mile / fuel_in_gallon;

    cout << "The fuel consume is " << fuel_consume << "mpg(miles/gallon)." << endl;
    cout << "Enter the distance in kilometer: ";
    cin >> distance_in_km;
    cout << "Enter the fuel consume in litre: ";
    cin >> fuel_in_litre;
    fuel_consume = (fuel_in_litre / distance_in_km) * 100;

    cout << "The fuel consume is " << fuel_consume << "L/100KM." << endl;

    return 0;
}