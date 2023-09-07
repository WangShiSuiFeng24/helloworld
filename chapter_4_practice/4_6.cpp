#include <iostream>
using namespace std;

struct CandyBar
{
    char brand[20];
    float weight;
    unsigned int calories;
};

int main()
{
    CandyBar snack[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Hershey bar", 4.2, 550},
        {"Musketeers", 2.6, 430}};

    cout << "My 1st CandyBar is " << snack[0].brand << "." << endl;
    cout << "And its weight is " << snack[0].weight << ", calories is " << snack[0].calories;
    cout << "." << endl;

    return 0;
}