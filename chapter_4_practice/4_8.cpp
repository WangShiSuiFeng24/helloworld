#include <iostream>
using namespace std;

struct Pizza
{
    char company[40];
    float diameter;
    float weight;
};

int main()
{
    Pizza *dinner = new Pizza;
    cout << "Enter the Pizza's information: " << endl;
    cout << "Pizza's diameter(inches): ";
    cin >> dinner->diameter;

    cout << "Pizza's weight(pounds): ";
    cin >> dinner->weight;

    cout << "Pizza's Company: ";
    cin.get();
    cin.getline(dinner->company, 40);

    cout << "The lunch pizza is " << dinner->company << "." << endl;
    cout << "And its diameter is " << dinner->diameter << " inch, weight is " << dinner->weight;
    cout << " pounds." << endl;

    delete dinner;
    return 0;
}